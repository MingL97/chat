#include "timerbtn.h"

#include <QMouseEvent>
#include <QDebug>

TimerBtn::TimerBtn(QWidget *parent):QPushButton(parent),_counter(10)
{
    _timer = new QTimer(this);

    connect(_timer,&QTimer::timeout,[this](){
        _counter -- ;
        if(_counter <= 0)
        {
            _timer->stop();
            _counter = 10;
            this->setText(tr("获取"));
            this->setEnabled(true);
            return;
        }
        this->setText(QString::number(_counter));

    });
}

TimerBtn::~TimerBtn()
{

}

void TimerBtn::mouseReleaseEvent(QMouseEvent *e)
{

    if(e->button() == Qt::LeftButton)
    {

        _timer->start(1000);
        this->setEnabled(false);
        this->setText(QString::number(_counter));
        emit clicked();


    }

    QPushButton::mouseReleaseEvent(e);

}
