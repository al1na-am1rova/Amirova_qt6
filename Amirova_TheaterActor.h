#pragma once
#include "Amirova_Actor.h"


class Amirova_TheaterActor :
    public Amirova_Actor
{

friend class boost::serialization::access;
private:


public:
    string theater_name;
    int experience;

	BOOST_SERIALIZATION_SPLIT_MEMBER()

	Amirova_TheaterActor() {}
	~Amirova_TheaterActor() override {}

    // void create(istream& in) override;
    // void show(ostream& out) override;
    vector<int> get_fields_length() override;
    void show_actor_on_screen(QPainter& painter, QPoint& point, vector<int> strLen, int lineHeight, int startX, int multiplier) override;
    string get_type() override;


	template<class Archive>
	void save(Archive& ar, const unsigned int version) const
	{
		ar& boost::serialization::base_object<Amirova_Actor>(*this);
		ar << theater_name;
		ar << experience;
	}

	template<class Archive>
	void load(Archive& ar, const unsigned int version)
	{
		ar >> boost::serialization::base_object<Amirova_Actor>(*this);
		ar >> theater_name;
		ar >> experience;
	}

};

