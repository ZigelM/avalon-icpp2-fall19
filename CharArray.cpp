#include "CharArray.hpp"
#include <iostream>
namespace ext
{
	int len(char_array arr){
		int out = 0;
		while (arr[out] != '\0') { ++out; }
		return out;
	}

	void concatenate(char_array& first, char_array second){
		char_array charr = new char[len(first) + len(second) - 1];
		for (int i = 0; i < len(first); ++i){
			charr[i] = first[i];
		}
		for (int i = 0; i < len(second); ++i){
			charr[len(first) + i] = second[i];
		}
		charr[len(first) + len(second)] = '\0';
		delete[] first;
		first = charr;
	}

	char characterAt(char_array arr, int pos){
		if ((pos <= 0) || (pos > len(arr))) { arr[0]; }
		else { return arr[pos - 1]; }
	}

	void append(char_array& arr, char in){
		char_array charr = new char[len(arr) + 2];
		for (int i = 0; i < len(arr); ++i){
			charr[i] = arr[i];
		}
		charr[len(arr)] = in;
		charr[len(arr) + 1] = '\0';
		arr = charr;
	}

	char_array substring(char_array arr, int start, int length){
		char_array charr = new char[length + 1];
		charr[length] = '\0';
		std::cout << "length: " << length << std::endl;
		for (int i = start - 1; i < start + length-1; ++i){
			charr[i- start + 1] = arr[i];
		}
		return charr;	
	}
}