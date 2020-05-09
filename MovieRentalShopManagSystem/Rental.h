#pragma once

#include "Movie.h"

class Rental
{
public:
	Rental(Movie movie, int daysRented);
	~Rental();

	Movie getMovie();
	int getDaysRented();
private:
	int m_nDaysRented;
	Movie m_movie;
};

