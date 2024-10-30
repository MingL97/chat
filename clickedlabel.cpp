#include "clickedlabel.h"
#include <QMouseEvent>
ClickedLabel::ClickedLabel(QWidget *parent)
{
    this->setCursor(Qt::PointingHandCursor);

}

void ClickedLabel::setState(QString normal, QString hover, QString press, QString select, QString selectHover, QString selectPress)
{

    //存储qss中的ui状态
    _normal = normal;
    _hover = hover;
    _press = press;
    _select = select;
    _selectHover = selectHover;
    _selectPress = selectPress;

    //开始是使用normal
    setProperty("state",normal);
    repolish(this);

}

ClickLbState ClickedLabel::getState()
{
    return _state;
}

void ClickedLabel::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        if(_state == ClickLbState::Normal)
        {
            _state = ClickLbState::Selected;
            setProperty("state",_selectHover);
            repolish(this);
            update();
        }
        else
        {
            _state = ClickLbState::Normal;
            setProperty("state",_hover);
            repolish(this);
            update();
        }
        emit clicked();
    }

    QLabel::mousePressEvent(e);
}

void ClickedLabel::enterEvent(QEvent *event)
{
    if(_state == ClickLbState::Normal)
    {
        setProperty("state",_hover);

    }
    else
    {
        setProperty("state",_selectHover);
    }
    repolish(this);
    update();


    QLabel::enterEvent(event);

}

void ClickedLabel::leaveEvent(QEvent *event)
{
    if(_state == ClickLbState::Normal)
    {
        setProperty("state",_normal);

    }
    else
    {
        setProperty("state",_select);
    }
    repolish(this);
    update();


    QLabel::leaveEvent(event);
}
