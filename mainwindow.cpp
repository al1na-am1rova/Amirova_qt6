#pragma once
#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QPainter>
#include <QWidget>
#include <QDebug>
#include "editdialog.h"
#include <QScrollArea>
#include <sstream>
//#include <QLayout>
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

    //std::cout << "ff" << flush;
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

template<class T>
void clone(T& src, T& trg)
{
    std::stringstream stream;
    boost::archive::binary_oarchive out(stream);
    boost::archive::binary_iarchive in(stream);
    out << src;
    in >> trg;
}


void MainWindow::on_edit_triggered() {

    std::vector<shared_ptr<Amirova_Actor>> actors;
    clone(ui->MyNewWidget->actors, actors);
    EditDialog* dlg = new EditDialog(this, {actors, ui->MyNewWidget->width(), ui->MyNewWidget->height()});
    dlg->show();

    if (dlg -> exec() == QDialog::Accepted)
    {
        clone(actors, ui->MyNewWidget->actors);
        ui->MyNewWidget->update();
        delete dlg;
    }

}
