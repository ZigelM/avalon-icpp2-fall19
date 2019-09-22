#include <iostream>
using namespace std;
long long code = 0;
short numb[13];
short sum = 0;
bool a = 0;
int main()
{
	for (;;) {
		a = 0;
		sum = 0;
		setlocale(LC_ALL, "Russian");
		cout << "Введите код ISBN:" << endl;
		cin >> code;
		if (code / static_cast<long long>(pow(10, 12)) == 0) 
		{
			cout << "не действителен" << endl << endl;
			a = 1;
		}
		if (a == 0)
		{
			for (int i = 0; i < 13; i++)
			{
				numb[i] = (code % static_cast<long long>(pow(10, i + 1))) / static_cast<long long>(pow(10, i));
			}
			for (int i = 12; i > 0; i--)
			{
				if (i % 2 == 0)
				{
					sum += numb[i];
				}
				else
				{
					sum += numb[i] * 3;
				}
			}
			sum %= 10;
			sum = 10 - sum;
			if (sum == numb[0]) { cout << "действителен" << endl << endl; }
			else { cout << "не действителен" << endl << endl; }
		}
	}
}