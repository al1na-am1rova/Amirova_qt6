#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include "Amirova_Actor.h"
#include "Amirova_TheaterActor.h"
#include "adddialog.h"

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    struct Data
    {
        std::vector <shared_ptr<Amirova_Actor>> actors;
        //bool labels;
        int w;
        int h;
    } data;

    explicit EditDialog(QWidget *parent,const Data &data);
    ~EditDialog();

    bool is_new_actor_theater_actor;

private:
    Ui::EditDialog *ui;
    void updateControls();

signals:
    // void setLabels(bool);
    void setWidth(int);
    void setHeight(int);

private slots:
    // void on_checkBox_checkStateChanged(const Qt::CheckState&);
    // void on_listWidget_currentRowChanged(int currentRow);
    // void on_spinX_valueChanged(int);
    // void on_spinY_valueChanged(int);
    // void on_addButton_clicked();
    // void on_deleteButton_clicked();
    // void on_sliderW_valueChanged(int value);
    // void on_sliderH_valueChanged(int value);


    void on_close_button_clicked();
    void on_add_button_clicked();
    void on_delete_button_clicked();
};

#endif // EDITDIALOG_H
