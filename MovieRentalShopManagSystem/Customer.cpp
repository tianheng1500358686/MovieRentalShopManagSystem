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
	for (auto & each : m_rentals)
	{
		//计算费用
		double thisAmount = 0;
		thisAmount = amountFor(each);
		//计算积分
		frequentRenterPoints++;
		if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
			(each.getDaysRented() > 1))
		{
			frequentRenterPoints++;
		}
		result += "\t" + each.getMovie().getTitle() + "\t" + convertToString(thisAmount) + "\n";
		totalAmount += thisAmount;
	}
	result += "Amount owed is " + convertToString(totalAmount) + "\n";
	result += "You earned " + convertToString(frequentRenterPoints) + " freuent renter points";
	
	return result;
}

double Customer::amountFor(const Rental & each)
{
	double thisAmount = 0.0;
	switch (each.getMovie().getPriceCode())
	{
	case Movie::REGULAR:
		thisAmount += 2;
		if (each.getDaysRented() > 2)
		{
			thisAmount += (each.getDaysRented() - 1) * 1.5;
		}
		break;
	case Movie::NEW_RELEASE:
		thisAmount += each.getDaysRented() * 3;
		break;
	case Movie::CHILDRENS:
		thisAmount += 1.5;
		if (each.getDaysRented() > 3)
		{
			thisAmount += (each.getDaysRented() - 3)*1.5;
		}
		break;
	default:
		break;
	}
	return thisAmount;
}

