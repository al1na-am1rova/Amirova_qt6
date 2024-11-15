// #ifndef MAINWINDOW_H
// #define MAINWINDOW_H

#pragma once
#include <QMainWindow>
#include <QPushButton>
#include <QPainter>
#include "editdialog.h"
#include "C:\Amirova_lab3_OPP\Amirova_qt6\MyWidget.h"

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
    void on_edit_triggered();

private:
    Ui::MainWindow *ui;
protected:
    void resizeEvent(QResizeEvent *event) override;
};
