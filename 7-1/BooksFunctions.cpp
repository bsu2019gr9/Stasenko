#define _CRT_SECURE_NO_WARNINGS
#include "BooksFunctions.h"

void deleteBooksByCost( Book* books, size_t& size)
{
	if (!size) { cout << "���� ��� ���\n";return; }
	double cost;
	cout << "������� ����\n";
	cin >> cost;
	for (int i = 0;i < size;i++) {
		if (books[i].getCost() > cost) {
			deleteBook(books, size, i);
			--i;
		}
	}
	cout << "�������!\n";
}

void printBooksByThemesAfterYear(const Book* books, const size_t size)
{
	if (!size) { cout << "���� ��� ���\n";return; }
	char theme[sizeStrings];
	size_t year;
	bool flag = true;
	cout << "������� ����\n";
	cin.getline(theme, sizeStrings);
	cout << "������� ���\n";
	cin >> year;
	for (int i = 0;i < size;i++) {
		if (books[i].getYear() > year && !strcmp(books[i].getCipherThemes(),theme)) {
			cout << books[i];
			flag = false;
		}
	}
	if (flag) {
		cout << "����� ���� ���\n";
	}
}

void printBooksByAuthorAscendingYear(const Book* books, const size_t size)
{
	if (!size) { cout << "���� ��� ���\n";return; }
	char authorName[sizeStrings];
	char authorSurname[sizeStrings];
	cout << "������� ��� ������\n";
	cin.getline(authorName, sizeStrings);
	cout << "������� ������� ������\n";
	cin.getline(authorSurname, sizeStrings);
	Book* resBooks = new Book[size];
	int currentSize = 0;
	for (int i = 0;i < size;i++) {
		if (!strcmp(books[i].getAuthorSurname(), authorSurname) && !strcmp(books[i].getAuthorName(), authorName)){
			resBooks[currentSize] = books[i];
			currentSize++;
		}
	}
	for (int i = 1;i < currentSize;i++) {
		for (int j = i;j > 0 && resBooks[j].getYear() < resBooks[j - 1].getYear();j--) {
			swap(resBooks[j - 1], resBooks[j]);
		}
	}
	if (!currentSize) { cout << "����� ���� ���\n"; return; }
	printAllBooks(resBooks, currentSize);

}

void sortBookgetNumberOfBooksgetTotalCost(Book* books,const size_t size, size_t& totalQuantity, double& totalCost)
{
	if (!size) { cout << "���� ��� ���\n";return; }
	totalQuantity = 0;
	totalCost = 0;
	for (int i = 0;i < size;i++) {
		totalQuantity += books[i].getQuantity();
		totalCost += books[i].getCost();
	}
	for (int i = 1;i < size;i++) {
		for (int j = i;j > 0 && books[j].getYear() < books[j - 1].getYear();j--) {
			swap(books[j - 1], books[j]);
		}
	}

}


size_t readArrayOfBooks(Book* books, const size_t size, const char* filename)
{
	ifstream in(filename,ios::binary);
	if (!in) { throw "���� �� ������"; }
	char tmp[sizeStrings];
	double cost;
	size_t tmpsize_t;
	size_t readed = 0;
	while (readed<size)
	{
		in.read((char*)&tmp, sizeStrings);
		if (in.eof())break;
		books[readed].setTitle(tmp);
		in.read((char*)&tmp, sizeStrings);
		books[readed].setAuthorName(tmp);
		in.read((char*)&tmp, sizeStrings);
		books[readed].setAuthorSurname(tmp);
		in.read((char*)&tmpsize_t, sizeof(size_t));
		books[readed].setYear(tmpsize_t);
		in.read((char*)&tmpsize_t, sizeof(size_t));
		books[readed].setQuantity(tmpsize_t);
		in.read((char*)&cost,sizeof(double));
		books[readed].setCost(cost);
		in.read((char*)&tmpsize_t,sizeof(size_t));
		in.read((char*)&tmp, tmpsize_t);
		books[readed].setCipherThemes(tmp);
		readed++;
	}
	in.close();
	return readed;
}
void writeArrayOfBooks(const Book* books, const size_t size, const char* filename)
{
	if (!size) { cout << "���� ��� ���\n";return; }
	ofstream out(filename,ios::binary);
	char tmp[sizeStrings];
	double cost;
	size_t tmpsize_t;

	for (int i = 0;i < size;i++)
	{
		strcpy(tmp, books[i].getTitle());
		out.write((char*)&tmp, sizeStrings);
		strcpy(tmp,books[i].getAuthorName());
		out.write((char*)&tmp, sizeStrings );
		strcpy(tmp, books[i].getAuthorSurname());
		out.write((char*)&tmp,sizeStrings);
		tmpsize_t = books[i].getYear();
		out.write((char*)&tmpsize_t, sizeof(size_t));
		tmpsize_t = books[i].getQuantity();
		out.write((char*)&tmpsize_t, sizeof(size_t));
		cost = books[i].getCost();
		out.write((char*)&cost, sizeof(double));
		strcpy(tmp, books[i].getCipherThemes());
		tmpsize_t = strlen(tmp)+1;
		out.write((char*)&tmpsize_t,sizeof(size_t));
		out.write((char*)&tmp,tmpsize_t);

	}
	out.close();
}
void editBook(Book& books, const size_t size) {
	if (!size) { cout << "���� ��� ���\n";return; }
	double cost;
	char str[sizeStrings];
	int n;

	while (true)
	{
		cout << "��� �� ������ ��������?\n";
		cout << "1.��������\n";
		cout << "2.��� ������\n";
		cout << "3.������� ������\n";
		cout << "4.��������� �����\n";
		cout << "5.���������� �����������\n";
		cout << "6.��� �������\n";
		cout << "7.���� ����\n";
		cout << "0.�����\n";
		cin >> n;
		cin.ignore(1);
		switch (n)
		{
		case 0:return;
		case 1:cout << "������� ��������\n";
			cin.getline (str,sizeStrings);
			books.setTitle(str);break;
		case 2:cout << "������� ���\n";
			cin.getline(str, sizeStrings);
			books.setAuthorName(str);break;
		case 3:cout << "������� �������\n";
			cin.getline(str, sizeStrings);
			books.setAuthorSurname(str);break;
		case 4:cout << "������� ���������\n";
			cin >> cost;
			books.setCost(cost);break;
		case 5:cout << "������� ���������� �����������\n";
			cin >> n;
			books.setQuantity(n);break;
		case 6:cout << "������� ���\n";
			cin >> n;
			books.setYear(n);break;
		case 7:cout << "������� ���� ����\n";
			cin.getline(str, sizeStrings);
			books.setCipherThemes(str);break;
		default:cout << "�������� ����.�������� ��������\n";return;
			break;
		}
		cout << "�������!\n";
	}
}
void createBook(Book& book) {

	cout << "������� �������� �����,���,������� ������,��� �������,����������,���������,���� ����(� ������ �������).������ ������ � ����� ������!\n";
	cin >> book;
	cout << "�������!\n";
}
void deleteBook(Book* books, size_t& size,size_t index) {
	if (!size) { cout << "���� ��� ���\n";return; }
	if(index>=size)cout << "�������� ������.�������� ��������\n";
	books[index].remove();
	swap(books[index], books[size - 1]);
	--size;

}
void printAllBooks(const Book* books, const size_t size) {
	if (!size) { cout << "���� ��� ���\n";return; }
	int n;
	char filename[50];
	cout << "1-�������� � ����\n2 - ������� �� �����\n";
	cout << "���� �������-������ ��������\n";
	cin >> n;
	if (n == 1) {
		cout << "������� ��� �����:\n";
		cin >> filename;
		writeArrayOfBooks(books, size, filename);
		cout << "�������!";
	}
	else if (n == 2) {
		for (int i = 0;i < size;i++) {
			cout << i + 1 << ".\n" << books[i];
		}
		cout << "\n";
	}
	else {
		cout << "������� �������� �������.�������� ��������.\n";
	}

}
void editFile() {
	size_t size = 0;
	size_t indexes[3];
	int n;
	Book* books = new Book[3];
	char filename[50];
	cout << "������� ��� �����\n";
	cin.getline(filename, 50);
	try {
		size = readArrayOfBooks(books, 100, filename);
	}
	catch (...) {
		cout << "���� �� ������\n";return;
	}
	printAllBooks(books, size);
	cout << "��� �� ������ �������?\n";
	cout << "1-�������� ������(�)\n";
	if (size) {
		cout << "2-������������� ������(�)?\n";
		cout << "3-������� ������(�)\n";
	}
	cout << "���� �������-������ ��������\n";
	cin >> n;
	cin.ignore(1);
	if (n == 1)
	{
		cout << "������� ���� �� ������ ��������?\n";
		cin >> n;
		for (int i = 0;i < n;i++)
			createBook(books[size + i]);
		size += n;
		cout << "��� ����� ���������!\n";
	}
	else if (n == 2 && size)
	{
			cout << "������� ������� ���� ������� �� ������ ���������������\n";
			size_t s = 0;

			while (cin.peek() != '\n') {
				cin >> indexes[s];
				--indexes[s];
				++s;
			}
			for (int i = 0;i < s;i++)
				editBook(books[indexes[i]], s);
	}
	else if (n == 3 && size)
	{
			cout << "������� ������� ���� ������� �� ������ �������\n";
			size_t s = 0;
			while (cin.peek() != '\n') {
				cin >> indexes[s];
				++s;
			}
			for (int i = 0;i < s;i++)
				deleteBook(books, size, i);
			cout << "�������!\n";
	}
	
	writeArrayOfBooks(books, size, filename);
	delete[] books;
}