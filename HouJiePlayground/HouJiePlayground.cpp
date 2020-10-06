// HouJiePlayground.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	const int constant = 26;
	const int* const_p = &constant;
	int* modifier = const_cast<int*>(const_p);
	*modifier = 3;
    return 0;
}

