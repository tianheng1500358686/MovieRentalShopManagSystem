#include "pch.h"
#include "Rental.h"


Rental::Rental(Movie movie, int daysRented)
{
	m_movie = movie;
	m_nDaysRented = daysRented;
}

Rental::~Rental()
{
}

Movie Rental::getMovie()
{
	return m_movie;
}

int Rental::getDaysRented()
{
	return m_nDaysRented;
}
