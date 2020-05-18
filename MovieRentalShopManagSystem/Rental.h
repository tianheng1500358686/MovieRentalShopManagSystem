/*
	租赁类
	作者：田老师
	微信公众号  『跟田老师学C++』
	知识星球『C++/Qt』地址: https://t.zsxq.com/QVVfUVr
	注：请尊重原作者劳动成果，仅供学习使用，请勿盗用，违者必究！
*/
#pragma once

#include "Movie.h"

class Rental
{
public:
	Rental(Movie movie, int daysRented);
	~Rental();

	Movie getMovie() const;
	int getDaysRented() const;
	double getCharge();
private:
	int m_nDaysRented;
	Movie m_movie;
};

