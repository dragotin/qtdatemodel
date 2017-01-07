/*
** Copyright (C) 2016 Klaas Freitag <klaas@volle-kraft-voraus.de>
**
** This code is based on an example from the Qt Toolkit and released
** under the same license as the original code.
**
** See license in the cpp file
*/

#ifndef DATEMODEL_H
#define DATEMODEL_H

#include <QAbstractItemModel>
#include <QDate>
#include <QList>
#include <QVector>
#include <QDebug>
#include <QStringList>


class TreeItem;

/*!
    \class AbstractIndx
    \brief The AbstractIndx class is the base class for the data classes of DateModel.

    The AbstractIndx class is the base class for the DocumentIndx class, which is
    used to manage the data of the items of the DateModel. Apart from the public
    DocumentIndx, there are also hidden YearIndx and MonthIndx classes.

 */
class AbstractIndx
{
public:
    enum IndxType {
        Invalid  = 0,
        DocumentType,
        YearType,
        MonthType
    };

    AbstractIndx()
        :_type(Invalid) { }

    virtual ~AbstractIndx() { }

    explicit AbstractIndx(IndxType t, QDate d)
        :_type(t), _date(d) { }

    virtual QVariant data(int column) const;

    virtual IndxType type();

    virtual int columnCount();

    void setData( const QVariantList& list );

    int year();
    int month();
    int day();

protected:
    QVariantList _data;

private:
    IndxType     _type;
    QDate        _date;
};

/* ================================================================== */

/*!
    \class DocumentIndx
    \brief The DocumentIndx class is representing a document in the DateModel.

    The DocumentIndx class is representing a single item in the DateModel. It
    is constructed with a QDate as argument, as the most important sort criteria.

    To add user data to it, either the data() method can be reimplemented, or more
    conveniently, the setData() method of the base class could be used to set data
    for each of the columns.

 */

class DocumentIndx : public AbstractIndx
{
public:
    DocumentIndx( QDate d)
        :AbstractIndx(DocumentType, d) {
    }
};

/* ================================================================== */

/*!
    \class DateModel
    \brief The DateModel is a Qt Model to be used with Qt Treeviews, sorted by date.

    The DateModel is a special Qt data model that can be used with Qt Treeview.
    It sorts the data by date, in a treeview structured after years and month.

    To use the DateModel, it needs to be instanciated and set as model for a
    treeview. While the normal QAbstractItemModel methods work, it has a couple
    of convenience functions to make it easier to deal with.

 */

class DateModel : public QAbstractItemModel
{
public:
    DateModel(QObject *parent = 0);
    virtual ~DateModel();

    enum CalcType {
        Zero = 0,
        Sum,
        Count
    };

    void setColumnCount(int columns);
    void setHeaderLabels( const QStringList& headers);

    TreeItem* findYearItem(int year);
    TreeItem* findMonthItem(int year, int month);

    void setMonthSumColumn( int column );
    void setMonthCountColumn( int column );
    void setYearSumColumn( int column );
    void setYearCountColumn( int column );

    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QModelIndex index(int row, int column, const QModelIndex &parent) const;

    QModelIndex parent(const QModelIndex &index) const;
    int rowCount(const QModelIndex &parent) const;

    void addData(DocumentIndx doc);

protected:
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    TreeItem          *_rootItem;
    int               _columnCount;
    QVector<CalcType> _monthExtra;
    QVector<CalcType> _yearExtra;
    QStringList       _headers;

};

#endif // DATEMODEL_H
