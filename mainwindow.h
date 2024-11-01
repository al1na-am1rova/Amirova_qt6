// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

#pragma once
#include "Amirova_Group.h"
#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include "MyWidget.h"

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
    QString LoadFileName;
    QString SaveFileName;

private slots:
    void on_load_from_file_triggered();
    void on_clean_data_triggered();
    void on_save_to_file_triggered();

private:
    Ui::MainWindow *ui;
    //Amirova_Group group;
    //bool show_table = false;
protected:
    void resizeEvent(QResizeEvent *event) override;
};

// #endif // MAINWINDOW_H
