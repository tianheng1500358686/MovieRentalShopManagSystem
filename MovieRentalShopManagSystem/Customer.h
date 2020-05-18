/*
	�˿���
	���ߣ�����ʦ
	΢�Ź��ں�  ��������ʦѧC++��
	֪ʶ����C++/Qt����ַ: https://t.zsxq.com/QVVfUVr
	ע��������ԭ�����Ͷ��ɹ�������ѧϰʹ�ã�������ã�Υ�߱ؾ���
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



