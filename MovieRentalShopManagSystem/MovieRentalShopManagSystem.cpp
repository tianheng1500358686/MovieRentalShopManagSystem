// MovieRentalShopManagSystem.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include "Customer.h"

#include <iostream>
#include <memory>
#include <string>

int main()
{
	Movie childRens("Kung Fu Panda", Movie::CHILDRENS);
	Movie reguler("War wolf", Movie::REGULAR);
	Movie Release("Avatar 2", Movie::NEW_RELEASE);
	Rental rental1(childRens, 7);
	Rental rental2(reguler, 2);
	Rental rental3(Release, 4);
	std::shared_ptr<Customer> customerPtr = std::make_shared<Customer>("teacher tian");
	customerPtr->addRental(rental1);
	customerPtr->addRental(rental2);
	customerPtr->addRental(rental3);
    std::cout << customerPtr->statement();
}
