#include "adddialog.h"
#include "ui_adddialog.h"
#include <QButtonGroup>
#include "editdialog.h"

AddDialog::AddDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddDialog)
{
    ui->setupUi(this);

    QButtonGroup *buttonGroup = new QButtonGroup(this);

    buttonGroup->addButton(ui -> actor_rb);
    buttonGroup->addButton(ui -> theater_rb);

    buttonGroup->setExclusive(true);

    connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)),this, SLOT(onRadioButtonClicked(QAbstractButton*)));

    ui ->experience_line ->setVisible(false);
    ui ->theater_line ->setVisible(false);
    ui ->experience_label ->setVisible(false);
    ui ->theater_label ->setVisible(false);
}

AddDialog::~AddDialog()
{
    delete ui;
}

void AddDialog::onRadioButtonClicked(QAbstractButton *button)
{
    if (button == ui->actor_rb) {
        ui ->experience_line ->setVisible(false);
        ui ->theater_line ->setVisible(false);
        ui ->experience_label ->setVisible(false);
        ui ->theater_label ->setVisible(false);
    } else if (button == ui->theater_rb) {
        ui ->experience_line ->setVisible(true);
        ui ->theater_line ->setVisible(true);
        ui ->experience_label ->setVisible(true);
        ui ->theater_label ->setVisible(true);
    }
}

void AddDialog::on_cancel_button_clicked()
{
    close();
}


void AddDialog::on_ok_button_clicked()
{
    if (ui -> actor_rb ->isChecked()) {
        actor->name = (ui -> name_line -> text()).QString::toStdString();
        actor->birth_year=(ui-> year_line->text()).QString::toInt();
        actor->gender = (ui->gender_line->text()).QString::toStdString();
        actor->height = (ui->height_line->text()).QString::toFloat();
        actor->is_able_to_sing = (ui-> sing_line->text()).QString::toInt();
        actor->city = (ui->city_line->text()).QString::toStdString();
        is_theater_actor = false;

    }
    else if (ui -> theater_rb -> isChecked()) {

        theater_actor->name = (ui -> name_line -> text()).QString::toStdString();
        theater_actor->birth_year=(ui-> year_line->text()).QString::toInt();
        theater_actor->gender = (ui->gender_line->text()).QString::toStdString();
        theater_actor->height = (ui->height_line->text()).QString::toFloat();
        theater_actor->is_able_to_sing = (ui-> sing_line->text()).QString::toInt();
        theater_actor->city = (ui->city_line->text()).QString::toStdString();
        theater_actor->theater_name = (ui -> theater_line -> text()).QString::toStdString();
        theater_actor->experience = (ui-> experience_line->text()).QString::toInt();
        is_theater_actor = true;
    }
    close();
}


