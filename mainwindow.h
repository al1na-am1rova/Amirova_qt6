#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once
#include "Amirova_Group.h"
#include <QMainWindow>
#include <QPushButton>
#include <QPainter>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_load_from_file_button_clicked();
    void paintEvent(QPaintEvent *event);

private:
    Ui::MainWindow *ui;
    bool show_table = false;
};

#endif // MAINWINDOW_H
