/****************************************************************************
** Meta object code from reading C++ file 'registerdialog.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../registerdialog.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'registerdialog.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RegisterDialog_t {
    QByteArrayData data[13];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RegisterDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RegisterDialog_t qt_meta_stringdata_RegisterDialog = {
    {
QT_MOC_LITERAL(0, 0, 14), // "RegisterDialog"
QT_MOC_LITERAL(1, 15, 23), // "sig_registerSwitchLogin"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 16), // "slot_http_finish"
QT_MOC_LITERAL(4, 57, 5), // "ReqId"
QT_MOC_LITERAL(5, 63, 2), // "id"
QT_MOC_LITERAL(6, 66, 3), // "res"
QT_MOC_LITERAL(7, 70, 10), // "ErrorCodes"
QT_MOC_LITERAL(8, 81, 3), // "err"
QT_MOC_LITERAL(9, 85, 23), // "on_btn_get_code_clicked"
QT_MOC_LITERAL(10, 109, 22), // "on_btn_confirm_clicked"
QT_MOC_LITERAL(11, 132, 21), // "on_return_btn_clicked"
QT_MOC_LITERAL(12, 154, 21) // "on_btn_cancel_clicked"

    },
    "RegisterDialog\0sig_registerSwitchLogin\0"
    "\0slot_http_finish\0ReqId\0id\0res\0"
    "ErrorCodes\0err\0on_btn_get_code_clicked\0"
    "on_btn_confirm_clicked\0on_return_btn_clicked\0"
    "on_btn_cancel_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RegisterDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    3,   45,    2, 0x08 /* Private */,
       9,    0,   52,    2, 0x08 /* Private */,
      10,    0,   53,    2, 0x08 /* Private */,
      11,    0,   54,    2, 0x08 /* Private */,
      12,    0,   55,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, QMetaType::QString, 0x80000000 | 7,    5,    6,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void RegisterDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<RegisterDialog *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sig_registerSwitchLogin(); break;
        case 1: _t->slot_http_finish((*reinterpret_cast< ReqId(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< ErrorCodes(*)>(_a[3]))); break;
        case 2: _t->on_btn_get_code_clicked(); break;
        case 3: _t->on_btn_confirm_clicked(); break;
        case 4: _t->on_return_btn_clicked(); break;
        case 5: _t->on_btn_cancel_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (RegisterDialog::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&RegisterDialog::sig_registerSwitchLogin)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject RegisterDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_RegisterDialog.data,
    qt_meta_data_RegisterDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *RegisterDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RegisterDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RegisterDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int RegisterDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void RegisterDialog::sig_registerSwitchLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
