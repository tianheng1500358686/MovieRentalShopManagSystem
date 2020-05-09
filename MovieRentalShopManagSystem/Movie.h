#pragma once

#include <iostream>

class Movie
{
public:
	Movie();
	Movie(const std::string & strTitle, int nPriceCode);
	~Movie();

	void setPriceCode(int priceCode);
	int getPriceCode();
	std::string getTitle();

public:
	static const int CHILDRENS = 2;
	static const int REGULAR = 0;
	static const int NEW_RELEASE = 1;
private:
	std::string m_strTitle;
	int m_nPriceCode;
};

