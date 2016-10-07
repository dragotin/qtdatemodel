/*
** Copyright (C) 2016 Klaas Freitag <klaas@volle-kraft-voraus.de>
**
** This code is based on an example from the Qt Toolkit and released
** under the same license as the original code.
**
** See license in datemodel.cpp
*/

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
