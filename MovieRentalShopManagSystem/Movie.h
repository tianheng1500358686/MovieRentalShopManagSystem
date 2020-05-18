/*
	影片类
	作者：田老师
	微信公众号  『跟田老师学C++』
	知识星球『C++/Qt』地址: https://t.zsxq.com/QVVfUVr
	注：请尊重原作者劳动成果，仅供学习使用，请勿盗用，违者必究！
*/
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

