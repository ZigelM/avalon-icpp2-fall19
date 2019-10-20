#include <string>
#include <iostream>
#include <ctime>
#include <random>
using namespace std;
struct Student 
{ 
	int Id; 
	int Graid; 
	string Name; 
};
const int N = 10;
int arr[N];
int main()
{
	setlocale(LC_ALL, "");
	srand(time(0));
	for (int i = 0; i < N; i++) { arr[i] = i; }
	Student numb[N];
	for (int i = 0; i < N; ++i)
	{
		int length = rand() % 3 + 3;
		char lett = rand() % 25 + 65;
		numb[i].Name += lett;
		for (int j = 1; j < length; ++j)
		{
			numb[i].Name += rand() % 25 + 97;
		}
		numb[i].Id = rand() % 999 + 1;
		numb[i].Graid = rand() % 100;
	}
	for (int i = 0; i < N; i++) {
		cout << numb[arr[i]].Id << "  " << numb[arr[i]].Name << "  " << numb[arr[i]].Graid << endl;
	}
	cout << endl << "Введите [1], чтобы сортировать по ID." << endl;
	cout << "Введите [2], чтобы сортировать по имени." << endl;
	cout << "Введите [3], чтобы сортировать по оценке." << endl << endl;
	int val;
	int v;
	cin >> val;
	cout << endl;
	switch (val)
	{
	case 1:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (numb[arr[i]].Id < numb[arr[j]].Id) {
					v = arr[j];
					arr[j] = arr[i];
					arr[i] = v;
				}
			}
		}
		break;
	case 2:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (numb[arr[i]].Name < numb[arr[j]].Name) {
					v = arr[j];
					arr[j] = arr[i];
					arr[i] = v;
				}
			}
		}
		break;
	case 3:
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (numb[arr[i]].Graid < numb[arr[j]].Graid) {
					v = arr[j];
					arr[j] = arr[i];
					arr[i] = v;
				}
			}
		}
		break;
	}
	for (int i = 0; i < N; i++) {
		cout << numb[arr[i]].Id << "  " << numb[arr[i]].Name << "  " << numb[arr[i]].Graid << endl;
	}

}
