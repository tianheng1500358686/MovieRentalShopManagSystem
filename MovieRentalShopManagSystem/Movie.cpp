#include "pch.h"
#include "Movie.h"

Movie::Movie()
{
}


Movie::Movie(const std::string & strTitle, int nPriceCode)
{
	m_strTitle = strTitle;
	m_nPriceCode = nPriceCode;
}

Movie::~Movie()
{
}

void Movie::setPriceCode(int priceCode)
{
	m_nPriceCode = priceCode;
}

int Movie::getPriceCode()
{
	return m_nPriceCode;
}

std::string Movie::getTitle()
{
	return m_strTitle;
}
