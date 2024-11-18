#include "editdialog.h"
#include "ui_editdialog.h"
#include <sstream>

EditDialog::EditDialog(QWidget *parent, vector<shared_ptr<Amirova_Actor>>& actors)
    : QDialog(parent)
    , actors(actors)
    , ui(new Ui::EditDialog)
{
    ui->setupUi(this);

    for(auto actor: actors)
    {
        ui->listWidget->addItem(QString::fromLocal8Bit(actor -> name));
    }
    ui->listWidget->setCurrentRow(0);
    updateControls();
}

EditDialog::~EditDialog()
{
    delete ui;
}

void EditDialog::on_listWidget_currentRowChanged(int currentRow)
{
    updateControls();
}

void EditDialog::updateControls()
{
    bool show = !actors.empty();

    //список НЕ пустой
    if (show) {
        shared_ptr<Amirova_Actor> current_actor = actors[ui->listWidget->currentRow()];
        ui->name_line->setText(QString::fromLocal8Bit(current_actor->name));
        ui->year_line->setText(QString::number(current_actor->birth_year));
        ui->gender_line->setText(QString::fromLocal8Bit(current_actor->gender));
        ui->height_line->setText(QString::number(current_actor->height));
        ui->sing_line->setText(QString::number(current_actor->is_able_to_sing));
        ui->city_line->setText(QString::fromLocal8Bit(current_actor->city));

        if (auto theaterActor = std::dynamic_pointer_cast<Amirova_TheaterActor>(current_actor)) {

            ui->theater_line->setText(QString::fromLocal8Bit(theaterActor->theater_name));
            ui->experience_line->setText(QString::number(theaterActor->experience));

            ui->theater_label->setVisible(show);
            ui->experience_label->setVisible(show);

            ui->theater_line->setVisible(show);
            ui->experience_line->setVisible(show);

            ui->theater_label->setEnabled(show);
            ui->experience_label->setEnabled(show);

            ui->theater_line->setEnabled(show);
            ui->experience_line->setEnabled(show);
        }

        else {

            ui->theater_label->setVisible(false);
            ui->experience_label->setVisible(false);

            ui->theater_line->setVisible(false);
            ui->experience_line->setVisible(false);

            ui->theater_line->clear();
            ui->experience_line->clear();

            // ui->theater_label->setEnabled(false);
            // ui->experience_label->setEnabled(false);

            // ui->theater_line->setEnabled(false);
            // ui->experience_line->setEnabled(false);
        }
    }

    //список пуст
    else {
        ui->name_line->clear();
        ui->year_line->clear();
        ui->gender_line->clear();
        ui->height_line->clear();
        ui->sing_line->clear();
        ui->city_line->clear();
        ui->theater_line->clear();
        ui->experience_line->clear();

        ui->theater_label->setVisible(show);
        ui->experience_label->setVisible(show);

        ui->theater_line->setVisible(show);
        ui->experience_line->setVisible(show);

    }

    // ui->name_label->setVisible(show);
    // ui->year_label->setVisible(show);
    // ui->gender_label->setVisible(show);
    // ui->height_label->setVisible(show);
    // ui->sing_label->setVisible(show);
    // ui->city_label->setVisible(show);

    // ui->name_line->setVisible(show);
    // ui->year_line->setVisible(show);
    // ui->gender_line->setVisible(show);
    // ui->height_line->setVisible(show);
    // ui->sing_line->setVisible(show);
    // ui->city_line->setVisible(show);

    ui->name_label->setEnabled(show);
    ui->year_label->setEnabled(show);
    ui->gender_label->setEnabled(show);
    ui->height_label->setEnabled(show);
    ui->sing_label->setEnabled(show);
    ui->city_label->setEnabled(show);

    ui->name_line->setEnabled(show);
    ui->year_line->setEnabled(show);
    ui->gender_line->setEnabled(show);
    ui->height_line->setEnabled(show);
    ui->sing_line->setEnabled(show);
    ui->city_line->setEnabled(show);

    ui->delete_button->setEnabled(show);

}

void EditDialog::on_close_button_clicked()
{
    done(QDialog::Accepted);
}


void EditDialog::on_add_actor_button_clicked()
{

   AddDialog* add_dlg = new AddDialog(this, false);
   add_dlg->show();

    if (add_dlg -> exec() == QDialog::Accepted) {
       shared_ptr<Amirova_Actor> new_actor = make_shared<Amirova_Actor>(add_dlg->actor);
       actors.push_back(new_actor);
       ui->listWidget->addItem(QString::fromLocal8Bit(new_actor -> name));
       ui->listWidget->setCurrentRow(actors.size()-1);
       updateControls();
    }
    delete add_dlg;

}

void EditDialog::on_add_theater_actor_button_clicked()
{
    AddDialog* add_dlg = new AddDialog(this, true);
    add_dlg->show();

    if (add_dlg -> exec() == QDialog::Accepted) {
        shared_ptr<Amirova_TheaterActor> new_actor = make_shared<Amirova_TheaterActor>(add_dlg->theater_actor);
        actors.push_back(new_actor);
        ui->listWidget->addItem(QString::fromLocal8Bit(new_actor -> name));
        ui->listWidget->setCurrentRow(actors.size()-1);
        updateControls();
    }
    delete add_dlg;
}


void EditDialog::on_delete_button_clicked()
{
    int currentRow = ui->listWidget->currentRow();
    if(currentRow < 0)
        return;
    delete ui->listWidget->takeItem(currentRow);
    actors.erase(actors.begin() + currentRow);
    if (currentRow < actors.size()) ui->listWidget->setCurrentRow(currentRow);
    else ui->listWidget->setCurrentRow( actors.size()-1);
    updateControls();
}



void EditDialog::on_name_line_editingFinished()
{
    int current_row = ui -> listWidget ->currentRow();
    actors[current_row]->name = (ui -> name_line -> text()).QString::toLocal8Bit();
    delete ui->listWidget->takeItem(current_row);
    ui->listWidget->insertItem(current_row,QString::fromLocal8Bit(actors[current_row] -> name));
}


void EditDialog::on_year_line_editingFinished()
{
    int current_row = ui -> listWidget ->currentRow();
    actors[current_row]->birth_year = (ui -> year_line -> text()).QString::toInt();
}


void EditDialog::on_gender_line_editingFinished()
{
    int current_row = ui -> listWidget ->currentRow();
    actors[current_row]->gender = (ui -> gender_line -> text()).QString::toLocal8Bit();
}


void EditDialog::on_height_line_editingFinished()
{
    int current_row = ui -> listWidget ->currentRow();
    actors[current_row]->height = (ui -> height_line -> text()).QString::toDouble();
}


void EditDialog::on_sing_line_editingFinished()
{
    int current_row = ui -> listWidget ->currentRow();
    actors[current_row]->is_able_to_sing = (ui -> sing_line -> text()).QString::toInt();
}


void EditDialog::on_city_line_editingFinished()
{
    int current_row = ui -> listWidget ->currentRow();
    actors[current_row]->city = (ui -> city_line -> text()).QString::toLocal8Bit();
}


void EditDialog::on_theater_line_editingFinished()
{
    int current_row = ui -> listWidget ->currentRow();
    if (auto theaterActor = std::dynamic_pointer_cast<Amirova_TheaterActor>(actors[current_row])) {
        theaterActor->theater_name = (ui -> theater_line -> text()).QString::toLocal8Bit();
    }
}


void EditDialog::on_experience_line_editingFinished()
{
    int current_row = ui -> listWidget ->currentRow();
    if (auto theaterActor = std::dynamic_pointer_cast<Amirova_TheaterActor>(actors[current_row])) {
        theaterActor->experience = (ui -> experience_line -> text()).QString::toInt();
    }
}



