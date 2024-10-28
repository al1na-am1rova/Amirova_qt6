// #ifndef MYWIDGET_H
// #define MYWIDGET_H

#pragma once

#include <QMainWindow>
#include <QObject>
#include <QWidget>

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MyWidget(QWidget *parent = nullptr);
    bool show_table = false;
    void paintEvent(QPaintEvent *event) override;
    QString LoadFileName;
    //void load(const QString& path);


signals:
};

//#endif // MYWIDGET_H
