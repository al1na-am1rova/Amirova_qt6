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

void MainWindow:: resizeEvent(QResizeEvent *event) {
    QSize newSize = this->size();
    ui -> scrollArea ->setFixedSize(newSize.width(), newSize.height() - 40);
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_load_from_file_triggered() {

    LoadFileName = QFileDialog::getOpenFileName(this, tr("Открыть"), QDir::currentPath(), tr("Текст (*.txt)"));
    ui -> MyNewWidget -> load_from_file(LoadFileName);
    update();
}

void MainWindow::on_save_to_file_triggered() {
   QString SaveFileName = QFileDialog::getOpenFileName(this, tr("Открыть"), QDir::currentPath(), tr("Текст (*.txt)"));
   ui -> MyNewWidget -> save_to_file(SaveFileName);
}

void MainWindow::on_clean_data_triggered() {

    ui -> MyNewWidget -> clean();
    LoadFileName = "";

}
