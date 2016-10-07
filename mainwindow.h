/*
** Copyright (C) 2016 Klaas Freitag <klaas@volle-kraft-voraus.de>
**
** This code is based on an example from the Qt Toolkit and released
** under the same license as the original code.
**
** See license in datemodel.cpp
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
