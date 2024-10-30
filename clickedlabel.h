#ifndef CLICKEDLABEL_H
#define CLICKEDLABEL_H

#include <QLabel>
#include "global.h"

class ClickedLabel :public QLabel
{
    Q_OBJECT
public:
    ClickedLabel(QWidget *parent);

    void setState(QString normal = "",QString hover = "",QString press = "",
                  QString select = "",QString selectHover = "",QString selectPress = "");
    ClickLbState getState();
protected:
     void mousePressEvent(QMouseEvent* e) override;
     void enterEvent(QEvent *event) override;
     void leaveEvent(QEvent *event) override;

private:

     QString _normal;
     QString _hover;
     QString _press;
     QString _select;
     QString _selectHover;
     QString _selectPress;

    ClickLbState _state;
signals:
    void clicked();

};

#endif // CLICKEDLABEL_H
