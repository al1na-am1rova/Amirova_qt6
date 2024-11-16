#include "editdialog.h"
#include "ui_editdialog.h"
#include <sstream>

EditDialog::EditDialog(QWidget *parent,const Data& data)
    : QDialog(parent)
    , data(data)
    , ui(new Ui::EditDialog)
{
    ui->setupUi(this);
    //ui->checkBox->setChecked(data.labels);
    for(auto actor: data.actors)
    {
        ui->listWidget->addItem(QString::fromLocal8Bit(actor -> name));
    }
    ui->listWidget->setCurrentRow(0);
    // ui->sliderH->setValue(data.h);
    // ui->sliderW->setValue(data.w);
    updateControls();
}

EditDialog::~EditDialog()
{
    delete ui;
}

// void EditDialog::on_checkBox_checkStateChanged(const Qt::CheckState &state)
// {
//     emit setLabels(state == Qt::Checked);
// }

// void EditDialog::on_listWidget_currentRowChanged(int currentRow)
// {
//     if(currentRow < 0 || currentRow >= data.points.size())
//         return;
//     ui->spinX->setValue(data.points[currentRow].x());
//     ui->spinY->setValue(data.points[currentRow].y());
// }


// void EditDialog::on_spinX_valueChanged(int x)
// {
//     int currentRow = ui->listWidget->currentRow();
//     if(currentRow < 0)
//         return;
//     data.points[currentRow].setX(x);
//     ui->listWidget->currentItem()->setText(pointToString(data.points[currentRow]));
// }


// void EditDialog::on_spinY_valueChanged(int y)
// {
//     int currentRow = ui->listWidget->currentRow();
//     if(currentRow < 0)
//         return;
//     data.points[currentRow].setY(y);
//     ui->listWidget->currentItem()->setText(pointToString(data.points[currentRow]));
// }


// void EditDialog::on_addButton_clicked()
// {
//     data.points.push_back(QPointF(data.points.size() * 50, data.points.size() * 50));
//     ui->listWidget->addItem(pointToString(data.points.back()));
//     ui->listWidget->setCurrentRow(data.points.size()-1);
//     updateControls();
// }


// void EditDialog::on_deleteButton_clicked()
// {
//     int currentRow = ui->listWidget->currentRow();
//     if(currentRow < 0)
//         return;
//     data.points.erase(data.points.begin() + currentRow);
//     delete ui->listWidget->takeItem(currentRow);
//     updateControls();
// }

void EditDialog::updateControls()
{
    bool show = !data.actors.empty();

    if (show) {
        shared_ptr<Amirova_Actor> current_actor = data.actors[ui->listWidget->currentRow()];
        ui->name_line->setText(QString::fromLocal8Bit(current_actor->name));
        ui->year_line->setText(QString::number(current_actor->birth_year));
        ui->gender_line->setText(QString::fromLocal8Bit(current_actor->gender));
        ui->height_line->setText(QString::number(current_actor->height));
        ui->sing_line->setText(QString::number(current_actor->is_able_to_sing));
        ui->city_line->setText(QString::fromLocal8Bit(current_actor->city));
        if (current_actor -> get_type() == "theater_actor") {

            // ui->theater_label->setVisible(show);
            // ui->experience_label->setVisible(show);

            // ui->theater_line->setVisible(show);
            // ui->experience_line->setVisible(show);

            ui->theater_label->setEnabled(show);
            ui->experience_label->setEnabled(show);

            ui->theater_line->setEnabled(show);
            ui->experience_line->setEnabled(show);

            // ui->theater_line->setText(QString::fromLocal8Bit(current_actor->theater_name));
            // ui->experience_line->setText(QString::fromLocal8Bit(current_actor->experience));
        }

        else {

            // ui->theater_label->setVisible(false);
            // ui->experience_label->setVisible(false);

            // ui->theater_line->setVisible(false);
            // ui->experience_line->setVisible(false);

            ui->theater_label->setEnabled(false);
            ui->experience_label->setEnabled(false);

            ui->theater_line->setEnabled(false);
            ui->experience_line->setEnabled(false);
        }
    }

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

    ui->edit_button->setEnabled(show);
    ui->delete_button->setEnabled(show);


}


// void EditDialog::on_sliderW_valueChanged(int value)
// {
//     emit setWidth(value);
// }


// void EditDialog::on_sliderH_valueChanged(int value)
// {
//     emit setHeight(value);
// }

// template<class T>
// void clone(T& src, T& trg)
// {
//     std::stringstream stream;
//     boost::archive::binary_oarchive out(stream);
//     boost::archive::binary_iarchive in(stream);
//     out << src;
//     in >> trg;
// }

void EditDialog::on_close_button_clicked()
{
    close();
}


void EditDialog::on_add_button_clicked()
{

   AddDialog* add_dlg = new AddDialog(this);
   add_dlg->show();

    if (add_dlg -> exec() == QDialog::Accepted)
     {
        // if (!add_dlg->is_theater_actor) {
        //     shared_ptr<Amirova_Actor> new_actor = make_shared<Amirova_Actor>();
        //     new_actor = add_dlg->actor;
        //     data.actors.insert(data.actors.end(), new_actor);
        // }
        // else {
        //     shared_ptr<Amirova_TheaterActor> new_theater_actor = make_shared<Amirova_TheaterActor>();
        //     new_theater_actor = add_dlg->theater_actor;
        //     data.actors.insert(data.actors.end(), new_theater_actor);
        // }
        updateControls();
        delete add_dlg;
    }

}


void EditDialog::on_delete_button_clicked()
{
    int last_current_row = ui -> listWidget ->currentRow();
    data.actors.erase(data.actors.begin(),data.actors.begin() + ui->listWidget->currentRow() + 1);

    if (!data.actors.empty()) ui->listWidget->setCurrentRow(last_current_row);
    updateControls();

    ui -> listWidget ->clear();
    for(auto actor: data.actors)
    {
        ui->listWidget->addItem(QString::fromLocal8Bit(actor -> name));
    }

}

