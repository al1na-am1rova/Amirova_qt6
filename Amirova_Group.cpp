#pragma once
#include "Amirova_Group.h"
#include <QPainter>
#include <QWindow>
#include <QWidget>

BOOST_CLASS_EXPORT(Amirova_TheaterActor)

using boost::archive::archive_flags;

void Amirova_Group::add_actor()
{
    //cout << "Ввод нового актера" << endl;
    cout << "Create new actor" << endl;
	shared_ptr<Amirova_Actor> actor = make_shared<Amirova_Actor>();
	actor->Amirova_Actor::create(cin);
	actors.insert(actors.begin(), actor);
}

void Amirova_Group::add_theater_actor()
{
    //cout << "Ввод нового актера" << endl;
    cout << "Create new theater actor" << endl;
	shared_ptr<Amirova_TheaterActor> theater_actor = make_shared<Amirova_TheaterActor>();
	theater_actor->Amirova_TheaterActor::create(cin);
	actors.insert(actors.begin(), theater_actor);
}

void Amirova_Group::show_all_actors()
{
	if (!actors.empty()) {
        //cout << "Список всех актеров" << endl;
        cout << "all actors" << endl;
		for (auto& actor : actors) {
			actor->show(cout);
		}
	}
	else {
        //cout << "Список пуст" << endl;
        cout << "no actor" << endl;
	}
}

void Amirova_Group::clear_all() {
	actors.clear();
}

void Amirova_Group::save_to_file(QString SaveFileName)
{
    ofstream fout;
    fout.open(SaveFileName.toStdWString(), ios::out);

    if (fout.is_open()) {

        boost::archive::text_oarchive write(fout, archive_flags::no_header);
        write << actors;
    }

}

void Amirova_Group::load_from_file(QString LoadFileName)
{
    ifstream fin;
    fin.open(LoadFileName.toStdWString(), ios::in);

	if (fin.is_open()) {
		boost::archive::text_iarchive load(fin, archive_flags::no_header);
		load >> actors;
	}
}

vector<int> Amirova_Group::count_str_len(vector<QString> header, int sideSpace) {

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

void Amirova_Group:: show_all_actors_on_screen(QPainter& painter, QPoint& point, vector<int> strLen, int LineHeight, int startX,int multiplier) {

    std::for_each(actors.begin(), actors.end(), std::bind(&Amirova_Actor::show_actor_on_screen,std::placeholders::_1,ref(painter), ref(point), strLen, LineHeight, startX, multiplier));
}

int Amirova_Group::get_group_size() {
    return actors.size();
}
