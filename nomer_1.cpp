#include <iostream>
#include <string>
#include <stdio.h>
#include <limits.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	printf("%3s%-18s%-5s%-11s%-22s%-30s%-5s%-15s%s\n", "", "Тип переменной", "|", "Размер,", "|", "Значение", "|", "Количество", "|");
	printf("%-21s%-5s%-11s%-8s%-18s%-8s%-18s%-5s%-15s%s\n", "", "|", "байт", "|", "Минимальное", "|", "Максимальное", "|", "значимых бит", "|");
	printf("%s\n", "--------------------------------------------------------------------------------------------------------------");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15d%s\n", "", "bool", "|", sizeof(bool),
		"|", numeric_limits<bool>::min(), "|", numeric_limits<bool>::max(), "|", numeric_limits<bool>::digits, "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15d%s\n", "", "unsigned short", "|", sizeof(unsigned short),
		"|", numeric_limits<unsigned short>::min(), "|", numeric_limits<unsigned short>::max(), "|", numeric_limits<unsigned short>::digits, "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15d%s\n", "", "short", "|", sizeof(short),
		"|", numeric_limits<short>::min(), "|", numeric_limits<short>::max(), "|", numeric_limits<short>::digits, "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23u%-3s%-23u%-5s%-15d%s\n", "", "unsigned int", "|", sizeof(unsigned int),
		"|", numeric_limits<unsigned int>::min(), "|", numeric_limits<unsigned int>::max(), "|", numeric_limits<unsigned int>::digits, "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15d%s\n", "", "int", "|", sizeof(int),
		"|", numeric_limits<int>::min(), "|", numeric_limits<int>::max(), "|", numeric_limits<int>::digits, "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23u%-3s%-23u%-5s%-15d%s\n", "", "unsigned long", "|", sizeof(unsigned long),
		"|", numeric_limits<unsigned long>::min(), "|", numeric_limits<unsigned long>::max(), "|", numeric_limits<unsigned long>::digits, "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15d%s\n", "", "long", "|", sizeof(long),
		"|", numeric_limits<long>::min(), "|", numeric_limits<long>::max(), "|", numeric_limits<long>::digits, "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23llu%-3s%-23llu%-5s%-15d%s\n", "", "unsigned long long", "|", sizeof(unsigned long long),
		"|", numeric_limits<unsigned long long>::min(), "|", numeric_limits<unsigned long long>::max(), "|", numeric_limits<unsigned long long>::digits, "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23lld%-3s%-23lld%-5s%-15d%s\n", "", "long long", "|", sizeof(long long),
		"|", numeric_limits<long long>::min(), "|", numeric_limits<long long>::max(), "|", numeric_limits<long long>::digits, "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23d%-3s%-23d%-5s%-15d%s\n", "", "char", "|", sizeof(char),
		"|", numeric_limits<char>::min(), "|", numeric_limits<char>::max(), "|", numeric_limits<char>::digits, "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23e%-3s%-23e%-5s%-15d%s\n", "", "float", "|", sizeof(float),
		"|", numeric_limits<float>::min(), "|", numeric_limits<float>::max(), "|", numeric_limits<float>::digits, "|");
	printf("%3s%-18s%-5s%-11d%-3s%-23e%-3s%-23e%-5s%-15d%s\n", "", "double", "|", sizeof(double),
		"|", numeric_limits<double>::min(), "|", numeric_limits<double>::max(), "|", numeric_limits<double>::digits, "|");
	printf("%s\n", "--------------------------------------------------------------------------------------------------------------");
}

