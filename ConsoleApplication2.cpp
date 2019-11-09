#include "stdafx.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <limits.h>
using namespace std;
int main()
{
	int a;
	setlocale(LC_ALL, "");
	printf("%3s%-18s%-5s%-11s%-22s%-30s%-5s%-15s%s\n","", "Тип переменной", "|", "Размер,", "|", "Значение", "|", "Количество","|");
	printf("%-21s%-5s%-11s%-8s%-18s%-8s%-18s%-5s%-15s%s\n", "", "|", "байт", "|", "Минимальное", "|", "Максимальное","|","значимых бит", "|");
	printf("%s\n", "--------------------------------------------------------------------------------------------------------------");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15s%s\n", "", "bool", "|", sizeof(bool), "|", numeric_limits<bool>::min(), "|", numeric_limits<bool>::max(), "|", "" ,"|");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15s%s\n", "", "unsigned short", "|", sizeof(unsigned short), "|", numeric_limits<unsigned short>::min(), "|", numeric_limits<unsigned short>::max(), "|", "", "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15s%s\n", "", "short", "|", sizeof(short), "|", numeric_limits<short>::min(), "|", numeric_limits<short>::max(), "|", "", "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15s%s\n", "", "unsigned int", "|", sizeof(unsigned int), "|", numeric_limits<unsigned int>::min(), "|", numeric_limits<unsigned int>::max(), "|", "", "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15s%s\n", "", "int", "|", sizeof(int), "|", numeric_limits<int>::min(), "|", numeric_limits<int>::max(), "|", "", "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15s%s\n", "", "unsigned long", "|", sizeof(unsigned long), "|", numeric_limits<unsigned long>::min(), "|", numeric_limits<unsigned long>::max(), "|", "", "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15s%s\n", "", "long", "|", sizeof(long), "|", numeric_limits<long>::min(), "|", numeric_limits<long>::max(), "|", "", "|");
	//printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15s%s\n", "", "unsigned long long", "|", sizeof(unsigned long long), "|", numeric_limits<unsigned long long>::min(), "|", numeric_limits<unsigned long long>::max(), "|", "", "|");
	//printf("%3s%-18s%-5s%-11u%-3s%-23d%-3s%-23d%-5s%-15s%s\n", "", "long long", "|", sizeof(long long), "|", numeric_limits<long long>::min(), "|", numeric_limits<long long>::max(), "|", "", "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15s%s\n", "", "char", "|", sizeof(char), "|", numeric_limits<char>::min(), "|", numeric_limits<char>::max(), "|", "", "|");
	//printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15s%s\n", "", "float", "|", sizeof(float), "|", numeric_limits<float>::min(), "|", numeric_limits<float>::max(), "|", "", "|");
	//printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15s%s\n", "", "double", "|", sizeof(double), "|", numeric_limits<double>::min(), "|", numeric_limits<double>::max(), "|", "", "|");
	cin >> a;
    return 0;
}

