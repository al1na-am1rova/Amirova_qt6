#include "Amirova_TheaterActor.h"
#include "utils.h"

void Amirova_TheaterActor::show(ostream& out) {
    Amirova_Actor::show(cout);
    // out << "Театр, в котором актёр работает в настоящее время: " << theater_name
    //     << "\tОбщий стаж работы в театре (лет): " << experience << endl;
    out << "theater: " << theater_name
        << " experience " << experience << endl;
}

void Amirova_TheaterActor::create(istream& in) {
    Amirova_Actor::create(cin);
    // cout << "Введите театр, в котором актёр работает в настоящее время: ";
    // getline(in, theater_name);
    // cout << "Введите общий стаж работы в театре (лет): ";
    cout << "theater: ";
    getline(in, theater_name);
    cout << "experience: ";
    experience = get_correct_number(0, 2024 - birth_year);
}

vector<int> Amirova_TheaterActor::get_fields_length() {
    vector<int> len = this -> Amirova_Actor::get_fields_length();
    len[6] = this ->theater_name.length();
    len[7] = 2;
    return len;
}

void Amirova_TheaterActor::show_actor_on_screen(QPainter&  painter, QPoint& point, vector<int> strLen, int lineHeigth,int startX,int multiplier) {

    painter.drawText(point, QString::fromLocal8Bit(name));
    point.setX(point.x() + strLen[0] * multiplier);
    painter.drawText(point, QString::number(birth_year));
    point.setX(point.x() + strLen[1] * multiplier);
    painter.drawText(point, QString::fromLocal8Bit(gender));
    point.setX(point.x() + strLen[2] * multiplier);
    painter.drawText(point, QString::number(height));
    point.setX(point.x() + strLen[3] * multiplier);
    painter.drawText(point, QString::number(is_able_to_sing));
    point.setX(point.x() + strLen[4] * multiplier);
    painter.drawText(point, QString::fromLocal8Bit(city));
    point.setX(point.x() + strLen[5] * multiplier);
    painter.drawText(point, QString::fromLocal8Bit(theater_name));
    point.setX(point.x() + strLen[6] * multiplier);
    painter.drawText(point, QString::number(experience));
    point.setX(startX);
    point.setY(point.y() + lineHeigth);

}
