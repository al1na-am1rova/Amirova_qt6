#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include "Amirova_Actor.h"
#include "Amirova_TheaterActor.h"
#include <QAbstractButton>

namespace Ui {
class AddDialog;
}

class AddDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddDialog(QWidget *parent = nullptr);
    ~AddDialog();

    bool is_theater_actor;
    shared_ptr<Amirova_Actor> actor;
    shared_ptr<Amirova_TheaterActor> theater_actor;

private slots:

    void on_cancel_button_clicked();

    void on_ok_button_clicked();

    void onRadioButtonClicked(QAbstractButton *button);

private:
    Ui::AddDialog *ui;
};

#endif // ADDDIALOG_H
