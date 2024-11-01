#include "MyWidget.h"

//BOOST_CLASS_EXPORT(Amirova_TheaterActor)

using boost::archive::archive_flags;

MyWidget::MyWidget(QWidget *parent)
    : QWidget{parent}
{
}

vector<int> MyWidget::count_str_len(vector<QString> header, int sideSpace) {

    // ищем ширину полей заголовка таблички
    vector<int> strLen(8);
    for (int i = 0; i < 8; ++i) strLen[i] = header[i].size();

    // ищем ширину (длину строк) полей каждого объекта
    // ищем максимальную длину строки для каждого поля среди всех объектов и заголовка и записываем её в strLen
    for (auto actor : actors) {
        vector<int> memLen = actor -> get_fields_length();
        for (int i = 0; i < 8; ++i)
            if (memLen[i] > strLen[i])
                strLen[i] = memLen[i];
    }

    // добавляем отступы
    for (int i = 1; i < 8; ++i)
    {
        strLen[i - 1] += sideSpace;
    }

    return strLen;

}

 void MyWidget::paintEvent(QPaintEvent *event) {
    vector<QString> header {"Имя","Год рождения", "Пол", "Рост(м)", "Наличие вокальных данных (1-есть, 0 - нет)", "Город", "Театр", "Общий стаж работы в театре (лет)" };

    int startX = 0;
    int top = 10;
    int sideSpace = 10;
    int lineHeight = 30;
    int multiplier = 5;

    vector<int> strLen = count_str_len(header, sideSpace);
    int groupSize = actors.size();

    if (groupSize != 0) {
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

        //this -> setMinimumWidth(point.x() + 5 * sideSpace);
        int totalWidth = (point.x() + 4 * sideSpace);

        // Рисуем горизонтальные линии для каждой строки
        for (int i = 0; i < groupSize; ++i) {
            painter.drawLine(startX - sideSpace, top + lineHeight / 2 + i * lineHeight, point.x() + 4 * sideSpace, top + lineHeight / 2 + i * lineHeight);
        }
        //нижняя граница таблицы
        painter.drawLine(startX - sideSpace, top + lineHeight / 2 + groupSize * lineHeight - sideSpace/2, point.x() + 4 * sideSpace, top + lineHeight / 2 + groupSize * lineHeight- sideSpace/2);

        //this -> setMinimumHeight(top + lineHeight + groupSize * lineHeight /*+ sideSpace/2*/);
        int totalHeight = (actors.size() + 1) * lineHeight - 10;

        top += lineHeight;
        point.setX(startX);
        point.setY(top);
        std::for_each(actors.begin(), actors.end(), std::bind(&Amirova_Actor::show_actor_on_screen,std::placeholders::_1,ref(painter), ref(point), strLen, lineHeight, startX, multiplier));

        // Устанавливаем минимальные размеры виджета
        setMinimumSize(totalWidth, totalHeight);
        setGeometry(geometry().x(), geometry().y(), totalWidth, totalHeight);
    }
}

 void MyWidget::load_from_file(QString LoadFileName) {
     ifstream fin;
     fin.open(LoadFileName.toStdWString(), ios::in);

     if (fin.is_open()) {
         boost::archive::text_iarchive load(fin, archive_flags::no_header);
         load >> actors;
     }
 }

 void MyWidget::save_to_file(QString SaveFileName) {
     ofstream fout;
     fout.open(SaveFileName.toStdWString(), ios::out);

     if (fout.is_open()) {
         boost::archive::text_oarchive write(fout, archive_flags::no_header);
         write << actors;
     }
 }

 void MyWidget::clean()
 {
     actors.clear();
     update();
 }
