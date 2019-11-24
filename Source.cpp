#include <iostream>
#include "CharArray.hpp"
using namespace std;
using namespace ext;
int main()
{
	char_array a = new char[6]{ "Hello" };
	char_array b = new char[8]{ " world" };
	concatenate(a, b);
	append(a, '!');
	for (int i = 0; i < len(a); ++i)
	{
		cout << a[i];
	}
	cout << endl;
	a = substring(a, 3, 5);
	for (int i = 0; i < len(a); ++i)
	{
		cout << a[i];
	}
}

