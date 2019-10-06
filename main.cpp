#include <iostream>
using namespace std;
long long code = 0;
short numb[13];
short sum = 0;
bool a = 0, generation;
int main()
{
	setlocale(LC_ALL, "Russian");
	for (;;) {
		cout << "ISBN-13?[1/0]" << endl;
		cin >> generation;
		if (generation == 1) {
			a = 0;
			sum = 0;
			cout << "Введите код ISBN-13:" << endl;
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
		else {
			a = 0;
			sum = 0;
			cout << "Введите код ISBN-10:" << endl;
			cin >> code;
			if (code / static_cast<long long>(pow(10, 8)) == 0)
			{
				cout << "не действителен" << endl << endl;
				a = 1;
			}
			if (a == 0)
			{
				for (int i = 0; i < 10; i++)
				{
					numb[i] = (code % static_cast<long long>(pow(10, i + 1))) / static_cast<long long>(pow(10, i));
				}
				for (int i = 9; i > 0; i--)
				{
					sum += numb[i]*(i+1);
				}
				sum = 11 - (sum % 11);
				if (sum == numb[0]) { cout << "действителен" << endl << endl; }
				else { cout << "не действителен" << endl << endl; }
			}
		}
	}
}
