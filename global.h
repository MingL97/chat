#ifndef GLOBAL_H
#define GLOBAL_H

#include <QWidget>
#include <functional>
#include <QStyle>
#include <QRegularExpression>
#include <memory>
#include <iostream>
#include <mutex>
#include <QByteArray>

/**
 * @brief repolish 用来刷新qss
 */
extern std::function<void(QWidget*)> repolish;


//接口枚举
enum ReqId
{
    ID_GET_VARIFY_CODE = 1001,
    ID_REGISTER_USER = 1002
};

//模块
enum Modules
{
    REGISTER_MOD = 0, //注册模块
};

//错误码
enum ErrorCodes
{
    SUCCESS = 0,
    ERR_JSON = 1,
    ERR_NETWORK = 2
};


#endif // GLOBAL_H
