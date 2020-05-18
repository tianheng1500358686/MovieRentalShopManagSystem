#include "pch.h"
#include "Customer.h"
#include "Movie.h"

Customer::Customer(const std::string & name)
{
	m_strName = name;
}


Customer::~Customer()
{
}

std::string Customer::getName()
{
	return m_strName;
}

void Customer::addRental(const Rental & arg)
{
	m_rentals.push_back(arg);
}

std::string Customer::statement()
{
	double totalAmount = 0;
	int frequentRenterPoints = 0;
	std::string result = "Rental record for " + getName() + "\n";
	for (auto & aRental : m_rentals)
	{
		//计算费用
		double thisAmount = 0;
		thisAmount = amountFor(aRental);
		//计算积分
		frequentRenterPoints++;
		if ((aRental.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
			(aRental.getDaysRented() > 1))
		{
			frequentRenterPoints++;
		}
		result += "\t" + aRental.getMovie().getTitle() + "\t" + convertToString(thisAmount) + "\n";
		totalAmount += thisAmount;
	}
	result += "Amount owed is " + convertToString(totalAmount) + "\n";
	result += "You earned " + convertToString(frequentRenterPoints) + " freuent renter points";
	
	return result;
}

double Customer::amountFor(const Rental & aRental)
{
	double result = 0.0;
	switch (aRental.getMovie().getPriceCode())
	{
	case Movie::REGULAR:
		result += 2;
		if (aRental.getDaysRented() > 2)
		{
			result += (aRental.getDaysRented() - 1) * 1.5;
		}
		break;
	case Movie::NEW_RELEASE:
		result += aRental.getDaysRented() * 3;
		break;
	case Movie::CHILDRENS:
		result += 1.5;
		if (aRental.getDaysRented() > 3)
		{
			result += (aRental.getDaysRented() - 3)*1.5;
		}
		break;
	default:
		break;
	}
	return result;
}

