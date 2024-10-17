#ifndef HTTPMGR_H
#define HTTPMGR_H

#include "singleton.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>
#include <global.h>

//crtp

class HttpMgr:public QObject,public Singleton<HttpMgr>,
        public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT
public:
    ~HttpMgr();
private:
    //保证单例可以访问HttpMgr的析构函数
    friend class Singleton<HttpMgr>;
    HttpMgr();
    QNetworkAccessManager _manager;

    void postHttpReq(QUrl url,QJsonObject json, ReqId reqId,Modules mod);
private slots:
    void slot_http_finished(ReqId id,QString res,ErrorCodes err,Modules mod);
signals:
    void sig_http_finished(ReqId id,QString res,ErrorCodes err,Modules mod);

    void sig_reg_mod_finished(ReqId id,QString res,ErrorCodes err);
};

#endif // HTTPMGR_H
