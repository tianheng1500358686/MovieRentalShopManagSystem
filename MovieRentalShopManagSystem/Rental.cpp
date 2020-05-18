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

Movie Rental::getMovie() const
{
	return m_movie;
}

int Rental::getDaysRented() const
{
	return m_nDaysRented;
}

double Rental::getCharge()
{
	double result = 0.0;
	switch (getMovie().getPriceCode())
	{
	case Movie::REGULAR:
		result += 2;
		if (getDaysRented() > 2)
		{
			result += (getDaysRented() - 1) * 1.5;
		}
		break;
	case Movie::NEW_RELEASE:
		result += getDaysRented() * 3;
		break;
	case Movie::CHILDRENS:
		result += 1.5;
		if (getDaysRented() > 3)
		{
			result += (getDaysRented() - 3)*1.5;
		}
		break;
	default:
		break;
	}
	return result;
}
