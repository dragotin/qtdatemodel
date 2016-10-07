/*
** Copyright (C) 2016 Klaas Freitag <klaas@volle-kraft-voraus.de>
**
** This code is based on an example from the Qt Toolkit and released
** under the same license as the original code.
**
** See license in datemodel.cpp
*/

#include "mainwindow.h"
#include <QApplication>
#include <QTreeView>

#include "datemodel.h"

#define QL1(x) QLatin1String(x)

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTreeView view;

    DateModel model;
    model.setColumnCount(4);
    model.setMonthSumColumn(3);
    model.setMonthCountColumn(1);
    model.setYearSumColumn(3);
    model.setYearCountColumn(1);

    QStringList labels;
    labels.append( "Year, Month");
    labels.append( "Document No.");
    labels.append( "Customer");
    labels.append( "Revenue");

    model.setHeaderStrings(labels);

    DocumentIndx doc(QDate(2012, 12, 31));
    QVariantList vl;
    vl.insert(0, QL1(""));
    vl.insert(1, QL1("1002")); // column 1
    vl.insert(2, QL1("Silvester Statione")); //column 2
    vl.insert(3, 12.24);
    doc.setData(vl);
    model.addData( doc );

    DocumentIndx doc1(QDate(2013, 3, 11));
    vl[1] = QL1("278f"); // column 0
    vl[2] = QL1("March Litostra"); //column 1
    vl[3] = 14.53;
    doc1.setData(vl);
    model.addData( doc1 );

    DocumentIndx doc2(QDate(2013, 4, 1));
    vl[1] = QL1("33a3"); // column 0
    vl[2] = QL1("April Hammel"); //column 1
    vl[3] = 21.88;
    doc2.setData(vl);
    model.addData( doc2 );

    DocumentIndx doc3(QDate(2013, 4, 23));
    vl[1] = QL1("4780"); // column 0
    vl[2] = QL1("Arvial Mont"); //column 1
    vl[3] = 68.23;
    doc3.setData(vl);
    model.addData( doc3 );

    DocumentIndx doc4(QDate(2013, 5, 12));
    vl[1] = QL1("51a6"); // column 0
    vl[2] = QL1("May Musla"); //column 1
    vl[3] = 11.21;
    doc4.setData(vl);
    model.addData( doc4 );

    view.setModel(&model);
    view.setWindowTitle(QObject::tr("Date Tree Model"));
    view.show();

    return a.exec();
}
