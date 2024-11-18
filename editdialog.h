#ifndef EDITDIALOG_H
#define EDITDIALOG_H

#include <QDialog>
#include "Amirova_Actor.h"
#include "Amirova_TheaterActor.h"
#include "adddialog.h"
#include <QListWidgetItem>

namespace Ui {
class EditDialog;
}

class EditDialog : public QDialog
{
    Q_OBJECT

public:
    // struct Data
    // {
    //     std::vector <shared_ptr<Amirova_Actor>> actors;
    // } data;
    std::vector <shared_ptr<Amirova_Actor>> actors;
    explicit EditDialog(QWidget *parent,vector<shared_ptr<Amirova_Actor>>& actors);
    ~EditDialog();

private:
    Ui::EditDialog *ui;
    void updateControls();

signals:
    void setWidth(int);
    void setHeight(int);

private slots:

    void on_listWidget_currentRowChanged(int currentRow);

    void on_close_button_clicked();
    void on_delete_button_clicked();
    void on_add_theater_actor_button_clicked();
    void on_add_actor_button_clicked();
    void on_name_line_editingFinished();
    void on_year_line_editingFinished();
    void on_gender_line_editingFinished();
    void on_height_line_editingFinished();
    void on_sing_line_editingFinished();
    void on_city_line_editingFinished();
    void on_theater_line_editingFinished();
    void on_experience_line_editingFinished();
};

#endif // EDITDIALOG_H
