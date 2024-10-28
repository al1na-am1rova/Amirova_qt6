#pragma once
#include "Amirova_Actor.h"
#include "Amirova_TheaterActor.h"
#include "framework.h"
#include "mainwindow.h"

class Amirova_Group
{
		friend class boost::serialization::access;
		vector <shared_ptr<Amirova_Actor>> actors;
	public:
		template<class Archive>
		void serialize(Archive& ar, const unsigned int version)
		{
			ar& actors;
		}
        int get_group_size();
		void add_actor();
		void add_theater_actor();
		void show_all_actors();
		void clear_all();
		virtual void save_to_file();
		virtual void load_from_file();
        vector<int> count_str_len(vector<QString> header, int sideSpace);
        void show_all_actors_on_screen(QPainter& painter, QPoint& point, vector<int> strLen, int LineHeight, int startX, int multiplier);
};

