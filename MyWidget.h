//#ifndef MYWIDGET_H
//#define MYWIDGET_H

#pragma once

//#include "Amirova_Group.h"
#include "Amirova_Actor.h"
#include "Amirova_TheaterActor.h"
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include "framework.h"

class MyWidget : public QWidget
{
    Q_OBJECT
public:
    vector <shared_ptr<Amirova_Actor>> actors;
    template<class Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
        ar& actors;
    }
    explicit MyWidget(QWidget *parent = nullptr);
    void paintEvent(QPaintEvent *event) override;
    void load_from_file(QString LoadFileName);
    void save_to_file(QString SaveFileName);
    void clean();
    vector<int> count_str_len(vector<QString> header, int sideSpace);
    // void onSetWidth(int);
    // void onSetHeight(int);

private:

signals:
};

//#endif //MYWIDGET_H
