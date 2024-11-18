#include "Amirova_Actor.h"
#include "utils.h"

BOOST_CLASS_IMPLEMENTATION(Amirova_Actor, boost::serialization::level_type::object_serializable);

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
    point.setX(startX);
    point.setY(point.y() + lineHeigth);
}

string Amirova_Actor::get_type(){
    return "actor";
}
