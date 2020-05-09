#include "pch.h"
#include "Customer.h"
#include "Movie.h"

#include <sstream>

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
	int ffff = Movie::REGULAR;
	std::string result = "Rental record for " + getName() + "\n";
	for (auto & each : m_rentals)
	{
		//计算费用
		double thisAmount = 0;
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
		//计算积分
		frequentRenterPoints++;
		if ((each.getMovie().getPriceCode() == Movie::NEW_RELEASE) &&
			(each.getDaysRented() > 1))
		{
			frequentRenterPoints++;
		}
		
		std::stringstream streamThisAmount;
		std::string strThisAmount;
		streamThisAmount << thisAmount;
		streamThisAmount >> strThisAmount;
		result += "\t" + each.getMovie().getTitle() + "\t" + strThisAmount + "\n";
		totalAmount += thisAmount;
	}

	std::stringstream streamTotalAmount;
	std::string strTotalAmount;
	streamTotalAmount << totalAmount;
	streamTotalAmount >> strTotalAmount;
	result += "Amount owed is " + strTotalAmount + "\n";

	std::stringstream streamFrequentRenterPoints;
	std::string strFrequentRenterPoints;
	streamFrequentRenterPoints << frequentRenterPoints;
	streamFrequentRenterPoints >> strFrequentRenterPoints;
	result += "You earned " + strFrequentRenterPoints + " freuent renter points";
	
	return result;
}
