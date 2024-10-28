#include "Amirova_Actor.h"
#include "utils.h"

BOOST_CLASS_IMPLEMENTATION(Amirova_Actor, boost::serialization::level_type::object_serializable);

string get_correct_gender() {
    string gender;
    while ((cin >> gender).fail()
        || cin.peek() != '\n'
        //|| (gender != "мужской" && gender != "женский"))
          || (gender != "male" && gender != "female"))
    {
        cin.clear();
        cin.ignore(10000, '\n');
        //cout << "Введите пол ('мужской' / 'женский') :" << endl;
        cout << "Type ('male' / 'female') :" << endl;
    }
    return gender;
}

void Amirova_Actor::show(ostream& out) {
    // out << "Имя: " << name
    //     << "\tГод рождения: " << birth_year
    //     << "\tПол: " << gender
    //     << "\tРост (в метрах) : " << height
    //     << "\tНаличие вокальных данных(1 - есть, 0 - нет): " << is_able_to_sing
    //     << "\tГород: " << city << endl;
    out << "name: " << name
        << "\t birth_year: " << birth_year
        << "\t gender: " << gender
        << "\t height : " << height
        << "\t is_able_to_sing(0-no, 1-yes): " << is_able_to_sing
        << "\t city: " << city << endl;
}

void Amirova_Actor::create(istream& in) {
    // cout << "Новый актёр \n Имя: " << endl;
    // //cout << "Имя: ";
    // in.ignore(1000, '\n');
    // getline(in, name);
    // cout << "Год рождения: " << endl;
    // birth_year = get_correct_number(1900, 2024);
    // cout << "Пол: " << endl;
    // gender = get_correct_gender();
    // cout << "Рост (в метрах) : " << endl;
    // height = get_correct_number(0.0, 4.0);
    // cout << "Наличие вокальных данных(1 - есть, 0 - нет): " << endl;
    // is_able_to_sing = get_correct_number(0, 1);
    // cout << "Город: ";
    // in.ignore(1000, '\n');
    // getline(in, city);

    cout << "New actor \n name: " << endl;
    in.ignore(1000, '\n');
    getline(in, name);
    cout << " birth_year: " << endl;
    birth_year = get_correct_number(1900, 2024);
    cout << "gender: " << endl;
    gender = get_correct_gender();
    cout << "height(m): " << endl;
    height = get_correct_number(0.0, 4.0);
    cout << "is_able_to_sing(1-yes,0-no): " << endl;
    is_able_to_sing = get_correct_number(0, 1);
    cout << "city: ";
    in.ignore(1000, '\n');
    getline(in, city);
}

vector<int> Amirova_Actor:: get_fields_length(){
    vector<int> len(8,0);
    len[0] = this->name.length();
    len[1] = 4;
    len[2] = this->gender.length();
    len[3] = 4;
    len[4] = 1;
    len[5] = this->city.length();
    return len;
}

void Amirova_Actor::show_actor_on_screen(QPainter& painter, QPoint& point, vector<int> strLen, int lineHeigth, int startX, int multiplier) {

    painter.drawText(point, QString::fromStdString(name));
    point.setX(point.x() + strLen[0] * multiplier);
    painter.drawText(point, QString::number(birth_year));
    point.setX(point.x() + strLen[1] * multiplier);
    painter.drawText(point, QString::fromStdString(gender));
    point.setX(point.x() + strLen[2] * multiplier);
    painter.drawText(point, QString::number(height));
    point.setX(point.x() + strLen[3] * multiplier);
    painter.drawText(point, QString::number(is_able_to_sing));
    point.setX(point.x() + strLen[4] * multiplier);
    painter.drawText(point, QString::fromStdString(city));
    point.setX(startX);
    point.setY(point.y() + lineHeigth);
}
