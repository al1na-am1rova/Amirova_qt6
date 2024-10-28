#pragma once
#include "framework.h"
#include <QPainter>

class Amirova_Actor
{
	friend class boost::serialization::access;

protected:
	string name;
	int birth_year;
	string gender;
	double height; 
	bool is_able_to_sing;
	string city;
public:
    virtual vector<int> get_fields_length();
	friend string get_correct_gender();

	virtual void create(istream& in);
	virtual void show(ostream& out);
    virtual void show_actor_on_screen(QPainter& painter, QPoint& point, vector<int> strLen, int lineHeight, int startX, int multiplier);

	Amirova_Actor() {}
	virtual ~Amirova_Actor() {}

	template <class Archive>
	void serialize(Archive& ar, const unsigned int version) {
		ar& name;
		ar& birth_year;
		ar& gender;
		ar& height;
		ar& is_able_to_sing;
		ar& city;
	}
};

