#include "httpmgr.h"


HttpMgr::~HttpMgr()
{

}

HttpMgr::HttpMgr()
{

    connect(this,&HttpMgr::sig_http_finished,this,&HttpMgr::slot_http_finished);
}

void HttpMgr::postHttpReq(QUrl url, QJsonObject json, ReqId reqId, Modules mod)
{
    QByteArray data = QJsonDocument(json).toJson();
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/json");
    request.setHeader(QNetworkRequest::ContentLengthHeader,QByteArray::number(data.length()));
    auto self = shared_from_this();
    QNetworkReply * reply = _manager.post(request,data);
    connect(reply,&QNetworkReply::finished,[self,reply,reqId,mod](){

        //出错
        if(reply->error() != QNetworkReply::NoError)
        {
            qDebug()<<reply->errorString();

            emit self->sig_http_finished(reqId,"",ErrorCodes::ERR_NETWORK,mod);
            reply->deleteLater();
            return;
        }

        //无错误
        QString res  = reply->readAll();
        emit self->sig_http_finished(reqId,res,ErrorCodes::SUCCESS,mod);
        reply->deleteLater();
        return;

    });

}

void HttpMgr::slot_http_finished(ReqId id, QString res, ErrorCodes err, Modules mod)
{
    if(mod  == Modules::REGISTER_MOD)
    {

        emit sig_reg_mod_finished(id,res,err);
    }
}
