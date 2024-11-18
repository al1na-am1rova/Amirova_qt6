#include "adddialog.h"
#include "ui_adddialog.h"
#include <QButtonGroup>
#include "editdialog.h"

AddDialog::AddDialog(QWidget *parent, bool is_theater_actor)
    : QDialog(parent),
    is_theater_actor(is_theater_actor),
    ui(new Ui::AddDialog)
{
    ui->setupUi(this);

    // QButtonGroup *buttonGroup = new QButtonGroup(this);

    // buttonGroup->addButton(ui -> actor_rb);
    // buttonGroup->addButton(ui -> theater_rb);

    // buttonGroup->setExclusive(true);

    // connect(buttonGroup, SIGNAL(buttonClicked(QAbstractButton*)),this, SLOT(onRadioButtonClicked(QAbstractButton*)));
    if (!is_theater_actor) {
    ui ->experience_line ->setVisible(false);
    ui ->theater_line ->setVisible(false);
    ui ->experience_label ->setVisible(false);
    ui ->theater_label ->setVisible(false);
    ui->label->setText("Добавление актера");
    }
    else ui->label->setText("Добавление актера театра");
}

AddDialog::~AddDialog()
{
    delete ui;
}

// void AddDialog::onRadioButtonClicked(QAbstractButton *button)
// {
//     if (button == ui->actor_rb) {
//         ui ->experience_line ->setVisible(false);
//         ui ->theater_line ->setVisible(false);
//         ui ->experience_label ->setVisible(false);
//         ui ->theater_label ->setVisible(false);
//     } else if (button == ui->theater_rb) {
//         ui ->experience_line ->setVisible(true);
//         ui ->theater_line ->setVisible(true);
//         ui ->experience_label ->setVisible(true);
//         ui ->theater_label ->setVisible(true);
//     }
// }

void AddDialog::on_cancel_button_clicked()
{
    done(QDialog::Rejected);
}


void AddDialog::on_ok_button_clicked()
{
    if (!is_theater_actor) {
        actor.name = (ui -> name_line -> text()).QString::toLocal8Bit();
        actor.birth_year=(ui-> year_line->text()).QString::toInt();
        actor.gender = (ui->gender_line->text()).QString::toLocal8Bit();
        actor.height = (ui->height_line->text()).QString::toFloat();
        actor.is_able_to_sing = (ui-> sing_line->text()).QString::toInt();
        actor.city = (ui->city_line->text()).QString::toLocal8Bit();

    }
    else {
        theater_actor.name = (ui -> name_line -> text()).QString::toLocal8Bit();
        theater_actor.birth_year=(ui-> year_line->text()).QString::toInt();
        theater_actor.gender = (ui->gender_line->text()).QString::toLocal8Bit();
        theater_actor.height = (ui->height_line->text()).QString::toFloat();
        theater_actor.is_able_to_sing = (ui-> sing_line->text()).QString::toInt();
        theater_actor.city = (ui->city_line->text()).QString::toLocal8Bit();
        theater_actor.theater_name = (ui -> theater_line -> text()).QString::toLocal8Bit();
        theater_actor.experience = (ui-> experience_line->text()).QString::toInt();
    }
    done(QDialog::Accepted);
}


