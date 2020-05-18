/*
	������
	���ߣ�����ʦ
	΢�Ź��ں�  ��������ʦѧC++��
	֪ʶ����C++/Qt����ַ: https://t.zsxq.com/QVVfUVr
	ע��������ԭ�����Ͷ��ɹ�������ѧϰʹ�ã�������ã�Υ�߱ؾ���
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

