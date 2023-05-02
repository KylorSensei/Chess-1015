/****************************************************************************
** Meta object code from reading C++ file 'Jeu.hpp'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../include/Jeu.hpp"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Jeu.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSguiSCOPEEchiquierSceneENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSguiSCOPEEchiquierSceneENDCLASS = QtMocHelpers::stringData(
    "gui::EchiquierScene",
    "onMousePress",
    "",
    "QGraphicsSceneMouseEvent*",
    "event",
    "onMouseRelease"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSguiSCOPEEchiquierSceneENDCLASS_t {
    uint offsetsAndSizes[12];
    char stringdata0[20];
    char stringdata1[13];
    char stringdata2[1];
    char stringdata3[26];
    char stringdata4[6];
    char stringdata5[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSguiSCOPEEchiquierSceneENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSguiSCOPEEchiquierSceneENDCLASS_t qt_meta_stringdata_CLASSguiSCOPEEchiquierSceneENDCLASS = {
    {
        QT_MOC_LITERAL(0, 19),  // "gui::EchiquierScene"
        QT_MOC_LITERAL(20, 12),  // "onMousePress"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 25),  // "QGraphicsSceneMouseEvent*"
        QT_MOC_LITERAL(60, 5),  // "event"
        QT_MOC_LITERAL(66, 14)   // "onMouseRelease"
    },
    "gui::EchiquierScene",
    "onMousePress",
    "",
    "QGraphicsSceneMouseEvent*",
    "event",
    "onMouseRelease"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSguiSCOPEEchiquierSceneENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x08,    1 /* Private */,
       5,    1,   29,    2, 0x08,    3 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject gui::EchiquierScene::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsScene::staticMetaObject>(),
    qt_meta_stringdata_CLASSguiSCOPEEchiquierSceneENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSguiSCOPEEchiquierSceneENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSguiSCOPEEchiquierSceneENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<EchiquierScene, std::true_type>,
        // method 'onMousePress'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>,
        // method 'onMouseRelease'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QGraphicsSceneMouseEvent *, std::false_type>
    >,
    nullptr
} };

void gui::EchiquierScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EchiquierScene *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onMousePress((*reinterpret_cast< std::add_pointer_t<QGraphicsSceneMouseEvent*>>(_a[1]))); break;
        case 1: _t->onMouseRelease((*reinterpret_cast< std::add_pointer_t<QGraphicsSceneMouseEvent*>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *gui::EchiquierScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::EchiquierScene::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSguiSCOPEEchiquierSceneENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsScene::qt_metacast(_clname);
}

int gui::EchiquierScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 2;
    }
    return _id;
}
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSguiSCOPEAjouterPieceDialogENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSguiSCOPEAjouterPieceDialogENDCLASS = QtMocHelpers::stringData(
    "gui::AjouterPieceDialog"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSguiSCOPEAjouterPieceDialogENDCLASS_t {
    uint offsetsAndSizes[2];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSguiSCOPEAjouterPieceDialogENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSguiSCOPEAjouterPieceDialogENDCLASS_t qt_meta_stringdata_CLASSguiSCOPEAjouterPieceDialogENDCLASS = {
    {
        QT_MOC_LITERAL(0, 23)   // "gui::AjouterPieceDialog"
    },
    "gui::AjouterPieceDialog"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSguiSCOPEAjouterPieceDialogENDCLASS[] = {

 // content:
      11,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

Q_CONSTINIT const QMetaObject gui::AjouterPieceDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_CLASSguiSCOPEAjouterPieceDialogENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSguiSCOPEAjouterPieceDialogENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSguiSCOPEAjouterPieceDialogENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<AjouterPieceDialog, std::true_type>
    >,
    nullptr
} };

void gui::AjouterPieceDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

const QMetaObject *gui::AjouterPieceDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *gui::AjouterPieceDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSguiSCOPEAjouterPieceDialogENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int gui::AjouterPieceDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
