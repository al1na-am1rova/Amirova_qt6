#include "MyWidget.h"
#include "Amirova_Group.h"

MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}
{
}

 void MyWidget::paintEvent(QPaintEvent *event) {

    //vector<QString> header {"Name","Birth year", "Gender", "Height(m)", "Is able to sing (1-yes, 0 -no)", "City", "Theater", "Experience" };
    vector<QString> header {"Имя","Год рождения", "Пол", "Рост(м)", "Наличие вокальных данных (1-есть, 0 - нет)", "Город", "Театр", "Общий стаж работы в театре (лет)" };

    int startX = 50;
    int top = 50;
    int sideSpace = 10;
    int lineHeight = 30;
    int multiplier = 5;

    Amirova_Group group;
    //Amirova_Group group;
    group.load_from_file(LoadFileName);
    vector<int> strLen = group.count_str_len(header, sideSpace);
    int groupSize = group.get_group_size();

    if (show_table) {
        Q_UNUSED(event);

        QPainter painter(this);
        painter.setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::FlatCap));

        QPoint point(startX,top);

        for (int i = 0; i < header.size(); ++i)
        {
            painter.drawText(point, header[i]);
            point.setX(strLen[i] * multiplier + point.x());

        }

         // Рисуем горизонтальные линии для заголовка
        painter.drawLine(startX - sideSpace, top - lineHeight / 2, point.x() + 4 * sideSpace, top - lineHeight / 2);
        painter.drawLine(startX - sideSpace, top + lineHeight / 2, point.x() + 4  * sideSpace, top + lineHeight / 2);


        // Рисуем вертикальные линии
        point.setX(startX);
        for (int i = 0; i < header.size(); ++i) {
            painter.drawLine(point.x() - sideSpace, top - lineHeight/2 , point.x() - sideSpace, top + groupSize * lineHeight + sideSpace);
            point.setX(point.x() + strLen[i] * multiplier);
        }

        painter.drawLine(point.x() + 4 * sideSpace, top - lineHeight/2 , point.x() + 4 * sideSpace, top + groupSize * lineHeight + sideSpace);

        // Рисуем горизонтальные линии для каждой строки
        for (int i = 0; i < groupSize; ++i) {
            painter.drawLine(startX - sideSpace, top + lineHeight / 2 + i * lineHeight, point.x() + 4 * sideSpace, top + lineHeight / 2 + i * lineHeight);
        }
        //нижняя граница таблицы
        painter.drawLine(startX - sideSpace, top + lineHeight / 2 + groupSize * lineHeight - sideSpace/2, point.x() + 4 * sideSpace, top + lineHeight / 2 + groupSize * lineHeight- sideSpace/2);

        top += lineHeight;
        point.setX(startX);
        point.setY(top);
        group.show_all_actors_on_screen(painter,point,strLen,lineHeight,startX,multiplier);

    }
}
