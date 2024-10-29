#pragma once
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Amirova_Group.h"
#include "Amirova_Actor.h"
#include <QPainter>
#include <QWidget>
#include <QDebug>
#include <QScrollArea>
#include <QLayout>
#include <QFileDialog>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_load_from_file_button_clicked()
{
    LoadFileName = QFileDialog::getOpenFileName(this, tr("Открыть"), QDir::currentPath(), tr("Текст (*.txt)"));
    if (!LoadFileName.isEmpty()) {
        ui -> MyNewWidget -> show_table = true;
        ui -> MyNewWidget -> LoadFileName = LoadFileName;
    }
    else {
        //error
    }
    update();
}

