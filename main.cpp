#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <iomanip>

using namespace std;

ifstream in_file;
ofstream out_file;

const int BUFFER_SIZE = 20;
struct Book{
	int Id;
	char Title[BUFFER_SIZE];
	char Author[BUFFER_SIZE];
	float Price;
	int Quantity;
};

Book buffer;

int menuStr = 0;

string menu_text[] = { "добавить книгу", "редактировать книгу (по id)", "искать книгу (по названию)", "просмотреть список книг", "показать статистику","выйти" };
ostream& operator << (ostream& out, Book book){
	out << "Id: " << book.Id << ", Title: " << book.Title << ", Author: " 
		<< book.Author << ", Price: " << book.Price << ", Quantity" << book.Quantity;
	return out;
}
void swap(Book& a, Book& b){
	Book buffer;
	buffer = b;
	b = a;
	a = buffer;
}
void cursor(bool visibility) {
	CONSOLE_CURSOR_INFO cursor = { 1, visibility };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor);
}
Book* sort(Book *mass, int size)
{
	for (int i = 1; i<size; i++) {
		for (int j = 0; j<size - 1; j++) {
			if (strcmp(mass[i].Author, mass[j].Author) < 0) { 
				swap(mass[i], mass[j]);
			}
		}
	}
	for (int i = 1; i<size; i++) {
		for (int j = 0; j<size - 1; j++) {
			if ((mass[i].Author == mass[j].Author) && (strcmp(mass[i].Title, mass[j].Title) < 0)) {
				swap(mass[i], mass[j]);
			}
		}
	}
	return mass;
}
int keyboard_controlling() {
	for (;;) {
		switch (_getch()) {
		case 72:
			return 4;
			break;
		case 80:
			return 3;
			break;
		case 13:
			return 2;
			break;
		case 27:
			return 1;
			break;
		}
	}
}
int draw_menu() {
	cursor(false);
	system("cls");
	int i = 0;
	for ( i; i < menuStr; i++) {
		cout << "  " << menu_text[i] << endl; 
	}
	cout << "=>" << menu_text[i] << endl;
	i += 1;
	for (i; i < sizeof(menu_text) / sizeof(string); i++) {
		cout << "  " << menu_text[i] << endl;
	}
	return 0;

}
void add_book() {
	system("cls");
	cursor(true);

	cout << "Введите название книги: ";
	cin >> buffer.Title;
	cout << "Введите автора книги: ";
	cin >> buffer.Author;
	cout << "Введите цену книги: ";
	cin >> buffer.Price;
	cout << "Введите кол-во книг: ";
	cin >> buffer.Quantity;

	cursor(false);

	ifstream fin("books.bin", istream::in | istream::binary);

	fin.seekg(0, ios_base::end);
	int size = fin.tellg();
	int count = size / sizeof(Book);
	fin.seekg(0, ios_base::beg);

	Book* books = new Book[count];
	fin.read(reinterpret_cast<char*>(books), sizeof(Book) * count);
	fin.close();

	buffer.Id = count + 1;

	ofstream fout("books.bin", istream::out | istream::binary);
	fout.write(reinterpret_cast<char*>(&books[0]), sizeof(Book) * count);
	fout.write(reinterpret_cast<char*>(&buffer), sizeof(Book));
	fout.close();
}
void redact_book(){
	system("cls");
	cursor(true);

	ifstream fin("books.bin", istream::in | istream::binary);

	fin.seekg(0, ios_base::end);
	int size = fin.tellg();
	int count = size / sizeof(Book);
	fin.seekg(0, ios_base::beg);

	Book* books = new Book[count];
	fin.read(reinterpret_cast<char*>(books), sizeof(Book) * count);
	fin.close();

	int ID;
	cout << "Введите ID книги: ";
	cin >> ID;

	Book* ptr = nullptr;
	for (int i = 0; i < count; ++i) {
		int temp(books[i].Id);
		if (ID == temp) {
			ptr = &books[i];
			break;
		}
	}

	cursor(false);
	system("cls");

	if (ptr == nullptr) {
		cout << "Книги с названием " << ID << " не найдено" << endl;
	}
	else {
		cout << "ID: " << ptr->Id << endl << "Название: " << ptr->Title << endl << "Автор: "
			<< ptr->Author << endl << "Цена: " << ptr->Price << endl << "Количество: "
			<< ptr->Quantity << endl;
	}

	cout << endl << "Нажмите <Enter>, чтобы изменить или <ESC>, чтобы вернуться.";
	if (keyboard_controlling() == 2) { 
		cursor(true);
		system("cls");
		cout << "ID: " << ptr->Id << endl << "Название: " << ptr->Title << endl << "Автор: "
			<< ptr->Author << endl << "Цена: " << ptr->Price << endl << "Количество: "
			<< ptr->Quantity << endl << endl;
		cout << "Введите название книги: ";
		cin >> ptr->Title;
		cout << "Введите автора книги: ";
		cin >> ptr->Author;
		cout << "Введите цену книги: ";
		cin >> ptr->Price;
		cout << "Введите кол-во книг: ";
		cin >> ptr->Quantity;

		ofstream fout("books.bin", istream::out | istream::binary);
		fout.write(reinterpret_cast<char*>(&books[0]), sizeof(Book) * count);
		fout.close();
	} 
}
void find_book() {
	system("cls");
	cursor(true);
	
	ifstream fin("books.bin", istream::in | istream::binary);

	fin.seekg(0, ios_base::end); 
	int size = fin.tellg();
	int count = size / sizeof(Book);
	fin.seekg(0, ios_base::beg);

	Book* books = new Book[count];
	fin.read(reinterpret_cast<char*>(books), sizeof(Book) * count);
	fin.close();

	string name;
	cout << "Введите название книги: ";
	cin >> name;

	Book* ptr = nullptr;
	for (int i = 0; i < count; ++i){
		string temp(books[i].Title);
		if (name == temp){
			ptr = &books[i];
			break;
		}
	}

	cursor(false);
	system("cls");
	
	if (ptr == nullptr){
		cout << "Книги с названием " << name << " не найдено" << endl;
	}
	else{
		cout << "ID: " << ptr->Id << endl << "Название: " << ptr->Title << endl << "Автор: " 
			<< ptr-> Author << endl << "Цена: " << ptr->Price << endl << "Количество: " 
			<< ptr->Quantity << endl;
	}

	cout << endl << "Нажмите <Enter>, чтобы продолжить";
	for (;;) { if (keyboard_controlling() == 2) { break; } }
}
void show_list() {
	system("cls");

	ifstream fin("books.bin", istream::in | istream::binary);

	fin.seekg(0, ios_base::end);
	int size = fin.tellg();
	int count = size / sizeof(Book);
	fin.seekg(0, ios_base::beg);

	Book* books = new Book[count];
	fin.read(reinterpret_cast<char*>(books), sizeof(Book) * count);
	fin.close();

	books = sort(books, count);
	cout << setw(5) << left << "ID" << setw(20) << left << "Название" << setw(20) << left << "Автор"
		<< setw(15) << left << "Цена" << "Количество" << endl 
		<< "----------------------------------------------------------------------" << endl;
	for (int i = 0; i < count; i++){
		cout << setw(5) << left << books[i].Id << setw(20) << left << books[i].Title << setw(20) 
			<< left << books[i].Author << setw(15) << left << books[i].Price  << books[i].Quantity << endl;
	}

	cout << "----------------------------------------------------------------------";

	cout << endl << "Нажмите <Enter>, чтобы продолжить";
	for (;;) { if (keyboard_controlling() == 2) { break; } }
}
void show_statistics() {
	system("cls");

	int cost = 0;
	int amount = 0;

	ifstream fin("books.bin", istream::in | istream::binary);

	fin.seekg(0, ios_base::end);
	int size = fin.tellg();
	int count = size / sizeof(Book);
	fin.seekg(0, ios_base::beg);

	Book* books = new Book[count];
	fin.read(reinterpret_cast<char*>(books), sizeof(Book) * count);
	fin.close();

	for (int i = 0; i < count; i++){
		amount += books[i].Quantity;
		cost += books[i].Quantity * books[i].Price;
	}
	cout << "Общее число книг: " << amount << endl << "Стоимость всех книг: " << cost << endl;
	cout << endl << "Нажмите <Enter>, чтобы продолжить";
	for (;;) { if (keyboard_controlling() == 2) { break; } }
}
int main(){
	setlocale(LC_ALL, "Russian");
	draw_menu();
	for (;;) {
		switch (keyboard_controlling()) {
		case 1:
			return 0;
		case 2:
			switch (menuStr) {
				case 0: 
					add_book();
					break;
				case 1: 
					redact_book();
					break;
				case 2: 
					find_book();
					break;
				case 3: 
					show_list();
					break;
				case 4: 
					show_statistics();
					break;
				case 5:
					return 0;
			}
			draw_menu();
			break;
		case 3:
			if (menuStr < sizeof(menu_text) / sizeof(string) - 1) { menuStr += 1; }
			draw_menu();
			break;
		case 4:
			if (menuStr > 0) {menuStr -= 1; }
			draw_menu();
			break;
		}
	}

}
