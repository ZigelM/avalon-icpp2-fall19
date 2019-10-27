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
const int N = 20;
const float percent[] = { 0.25,0.5,0.75 };
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
		cout << numb[arr[i]].Id << " " << numb[arr[i]].Name << " " << numb[arr[i]].Graid << endl;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (numb[arr[i]].Graid < numb[arr[j]].Graid) {
				int v = arr[j];
				arr[j] = arr[i];
				arr[i] = v;
			}
		}
	}
	cout << endl << "Нужно получить:" 
		<< endl << numb[arr[var[0]]].Graid +1
		<< " чтобы стать лучше " << percent[0] * 100 << "% студентов,"
		<< endl << numb[arr[var[1]]].Graid +1
		<< " чтобы стать лучше " << percent[1] * 100 << "% студентов,"
		<< endl << numb[arr[var[2]]].Graid +1
		<< " чтобы стать лучше " << percent[2] * 100 << "% студентов."
		<< endl;
}
