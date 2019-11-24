#pragma once
using char_array = char*;
namespace ext{
	int len(char_array arr);
	void concatenate(char_array& first, char_array second);
	char characterAt(char_array arr, int position);
	void append(char_array& arr, char input);
	char_array substring(char_array arr, int start, int length);
}