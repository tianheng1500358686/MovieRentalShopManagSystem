/*
	顾客类
	作者：田老师
	微信公众号  『跟田老师学C++』
	知识星球『C++/Qt』地址: https://t.zsxq.com/QVVfUVr
	注：请尊重原作者劳动成果，仅供学习使用，请勿盗用，违者必究！
*/
#pragma once

#include <iostream>
#include <vector>
#include <sstream>

#include "Rental.h"

class Customer
{
public:
	Customer(const std::string & name);
	~Customer();

	std::string getName();
	void addRental(const Rental & arg);
	std::string statement();

private:
	template <class T>
	std::string convertToString(T value)
	{
		std::stringstream ss;
		ss << value;
		return ss.str();
	}
	double amountFor(const Rental & each);
private:
	std::string m_strName;
	std::vector<Rental> m_rentals;
};



