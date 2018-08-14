/****************************************************************************
** Meta object code from reading C++ file 'ui_test.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "ui_test.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ui_test.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_cosh_LineEdit_t {
    QByteArrayData data[5];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cosh_LineEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cosh_LineEdit_t qt_meta_stringdata_cosh_LineEdit = {
    {
QT_MOC_LITERAL(0, 0, 13), // "cosh_LineEdit"
QT_MOC_LITERAL(1, 14, 8), // "SendName"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "col_name"
QT_MOC_LITERAL(4, 33, 15) // "PayerNameCalled"

    },
    "cosh_LineEdit\0SendName\0\0col_name\0"
    "PayerNameCalled"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cosh_LineEdit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void cosh_LineEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cosh_LineEdit *_t = static_cast<cosh_LineEdit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->SendName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->PayerNameCalled(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (cosh_LineEdit::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cosh_LineEdit::SendName)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cosh_LineEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_cosh_LineEdit.data,
      qt_meta_data_cosh_LineEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cosh_LineEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cosh_LineEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cosh_LineEdit.stringdata0))
        return static_cast<void*>(this);
    return QLineEdit::qt_metacast(_clname);
}

int cosh_LineEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void cosh_LineEdit::SendName(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_cosh_NewBillTab_t {
    QByteArrayData data[1];
    char stringdata0[16];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cosh_NewBillTab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cosh_NewBillTab_t qt_meta_stringdata_cosh_NewBillTab = {
    {
QT_MOC_LITERAL(0, 0, 15) // "cosh_NewBillTab"

    },
    "cosh_NewBillTab"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cosh_NewBillTab[] = {

 // content:
       7,       // revision
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

void cosh_NewBillTab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject cosh_NewBillTab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cosh_NewBillTab.data,
      qt_meta_data_cosh_NewBillTab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cosh_NewBillTab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cosh_NewBillTab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cosh_NewBillTab.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int cosh_NewBillTab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_cosh_Tab_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cosh_Tab_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cosh_Tab_t qt_meta_stringdata_cosh_Tab = {
    {
QT_MOC_LITERAL(0, 0, 8), // "cosh_Tab"
QT_MOC_LITERAL(1, 9, 6), // "rename"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 8), // "new_name"
QT_MOC_LITERAL(4, 26, 10), // "handleCell"
QT_MOC_LITERAL(5, 37, 17), // "QTableWidgetItem*"
QT_MOC_LITERAL(6, 55, 6), // "handle"
QT_MOC_LITERAL(7, 62, 13), // "Set_billpayer"
QT_MOC_LITERAL(8, 76, 10) // "payer_name"

    },
    "cosh_Tab\0rename\0\0new_name\0handleCell\0"
    "QTableWidgetItem*\0handle\0Set_billpayer\0"
    "payer_name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cosh_Tab[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       4,    1,   32,    2, 0x0a /* Public */,
       7,    1,   35,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, QMetaType::QString,    8,

       0        // eod
};

void cosh_Tab::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cosh_Tab *_t = static_cast<cosh_Tab *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rename((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->handleCell((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->Set_billpayer((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cosh_Tab::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_cosh_Tab.data,
      qt_meta_data_cosh_Tab,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cosh_Tab::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cosh_Tab::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cosh_Tab.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int cosh_Tab::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
struct qt_meta_stringdata_cosh_TableWidget_t {
    QByteArrayData data[7];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cosh_TableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cosh_TableWidget_t qt_meta_stringdata_cosh_TableWidget = {
    {
QT_MOC_LITERAL(0, 0, 16), // "cosh_TableWidget"
QT_MOC_LITERAL(1, 17, 15), // "PayerNameSignal"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 7), // "Add_row"
QT_MOC_LITERAL(4, 42, 20), // "Add_row_no_new_items"
QT_MOC_LITERAL(5, 63, 13), // "Rename_column"
QT_MOC_LITERAL(6, 77, 8) // "col_name"

    },
    "cosh_TableWidget\0PayerNameSignal\0\0"
    "Add_row\0Add_row_no_new_items\0Rename_column\0"
    "col_name"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cosh_TableWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   35,    2, 0x0a /* Public */,
       4,    0,   36,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    6,

       0        // eod
};

void cosh_TableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cosh_TableWidget *_t = static_cast<cosh_TableWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PayerNameSignal(); break;
        case 1: _t->Add_row(); break;
        case 2: _t->Add_row_no_new_items(); break;
        case 3: _t->Rename_column((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (cosh_TableWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cosh_TableWidget::PayerNameSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cosh_TableWidget::staticMetaObject = {
    { &QTableWidget::staticMetaObject, qt_meta_stringdata_cosh_TableWidget.data,
      qt_meta_data_cosh_TableWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cosh_TableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cosh_TableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cosh_TableWidget.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int cosh_TableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void cosh_TableWidget::PayerNameSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_Rename_window_t {
    QByteArrayData data[3];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Rename_window_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Rename_window_t qt_meta_stringdata_Rename_window = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Rename_window"
QT_MOC_LITERAL(1, 14, 13), // "Delete_window"
QT_MOC_LITERAL(2, 28, 0) // ""

    },
    "Rename_window\0Delete_window\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Rename_window[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void Rename_window::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Rename_window *_t = static_cast<Rename_window *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Delete_window(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Rename_window::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Rename_window.data,
      qt_meta_data_Rename_window,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Rename_window::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Rename_window::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Rename_window.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Rename_window::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
struct qt_meta_stringdata_cosh_TabWidget_t {
    QByteArrayData data[14];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_cosh_TabWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_cosh_TabWidget_t qt_meta_stringdata_cosh_TabWidget = {
    {
QT_MOC_LITERAL(0, 0, 14), // "cosh_TabWidget"
QT_MOC_LITERAL(1, 15, 15), // "PayerNameSignal"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 10), // "Rename_tab"
QT_MOC_LITERAL(4, 43, 5), // "index"
QT_MOC_LITERAL(5, 49, 20), // "Update_payer_columns"
QT_MOC_LITERAL(6, 70, 14), // "Rename_columns"
QT_MOC_LITERAL(7, 85, 8), // "col_name"
QT_MOC_LITERAL(8, 94, 15), // "Repopulate_tabs"
QT_MOC_LITERAL(9, 110, 7), // "Add_tab"
QT_MOC_LITERAL(10, 118, 9), // "cosh_Tab*"
QT_MOC_LITERAL(11, 128, 5), // "Bill*"
QT_MOC_LITERAL(12, 134, 4), // "load"
QT_MOC_LITERAL(13, 139, 9) // "Calculate"

    },
    "cosh_TabWidget\0PayerNameSignal\0\0"
    "Rename_tab\0index\0Update_payer_columns\0"
    "Rename_columns\0col_name\0Repopulate_tabs\0"
    "Add_tab\0cosh_Tab*\0Bill*\0load\0Calculate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_cosh_TabWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   55,    2, 0x0a /* Public */,
       5,    0,   58,    2, 0x0a /* Public */,
       6,    1,   59,    2, 0x0a /* Public */,
       8,    0,   62,    2, 0x0a /* Public */,
       9,    2,   63,    2, 0x0a /* Public */,
       9,    1,   68,    2, 0x2a /* Public | MethodCloned */,
      13,    0,   71,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    0x80000000 | 10, QMetaType::Int, 0x80000000 | 11,    4,   12,
    0x80000000 | 10, QMetaType::Int,    4,
    QMetaType::Void,

       0        // eod
};

void cosh_TabWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        cosh_TabWidget *_t = static_cast<cosh_TabWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PayerNameSignal(); break;
        case 1: _t->Rename_tab((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->Update_payer_columns(); break;
        case 3: _t->Rename_columns((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->Repopulate_tabs(); break;
        case 5: { cosh_Tab* _r = _t->Add_tab((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Bill*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< cosh_Tab**>(_a[0]) = std::move(_r); }  break;
        case 6: { cosh_Tab* _r = _t->Add_tab((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< cosh_Tab**>(_a[0]) = std::move(_r); }  break;
        case 7: _t->Calculate(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (cosh_TabWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&cosh_TabWidget::PayerNameSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject cosh_TabWidget::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_cosh_TabWidget.data,
      qt_meta_data_cosh_TabWidget,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *cosh_TabWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *cosh_TabWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_cosh_TabWidget.stringdata0))
        return static_cast<void*>(this);
    return QTabWidget::qt_metacast(_clname);
}

int cosh_TabWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void cosh_TabWidget::PayerNameSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
