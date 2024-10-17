#ifndef SINGLETON_H
#define SINGLETON_H

#include "global.h"

template <typename T>
class Singleton{

protected:
    Singleton() = default;
    Singleton(const Singleton<T>&) = delete;
    Singleton& operator=(const Singleton<T>&st) = delete;
    static std::shared_ptr<T> _instance;

public:
    static std::shared_ptr<T> GetInstance(){
        static std::once_flag s_flag;
        //初次时s_flag为false，call_once执行完回调之后，s_flag变成true，之后不会再调用call_once
        std::call_once(s_flag,[&](){
            _instance = std::shared_ptr<T>(new T);
        });

        return _instance;
    }

    ~Singleton(){
        std::cout <<"this is singleton destruct"<<std::endl;
    }

};





#endif // SINGLETON_H
