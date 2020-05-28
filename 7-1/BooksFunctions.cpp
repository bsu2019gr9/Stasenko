#define _CRT_SECURE_NO_WARNINGS
#include "BooksFunctions.h"

void deleteBooksByCost( Book* books, size_t& size)
{
	if (!size) { cout << "Книг еще нет\n";return; }
	double cost;
	cout << "Введите цену\n";
	cin >> cost;
	for (int i = 0;i < size;i++) {
		if (books[i].getCost() > cost) {
			deleteBook(books, size, i);
			--i;
		}
	}
	cout << "Успешно!\n";
}

void printBooksByThemesAfterYear(const Book* books, const size_t size)
{
	if (!size) { cout << "Книг еще нет\n";return; }
	char theme[sizeStrings];
	size_t year;
	bool flag = true;
	cout << "Введите тему\n";
	cin.getline(theme, sizeStrings);
	cout << "Введите год\n";
	cin >> year;
	for (int i = 0;i < size;i++) {
		if (books[i].getYear() > year && !strcmp(books[i].getCipherThemes(),theme)) {
			cout << books[i];
			flag = false;
		}
	}
	if (flag) {
		cout << "Таких книг нет\n";
	}
}

void printBooksByAuthorAscendingYear(const Book* books, const size_t size)
{
	if (!size) { cout << "Книг еще нет\n";return; }
	char authorName[sizeStrings];
	char authorSurname[sizeStrings];
	cout << "Введите имя автора\n";
	cin.getline(authorName, sizeStrings);
	cout << "Введите фамилию автора\n";
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
	if (!currentSize) { cout << "Таких книг нет\n"; return; }
	printAllBooks(resBooks, currentSize);

}

void sortBookgetNumberOfBooksgetTotalCost(Book* books,const size_t size, size_t& totalQuantity, double& totalCost)
{
	if (!size) { cout << "Книг еще нет\n";return; }
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
	if (!in) { throw "Фаил не найден"; }
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
	if (!size) { cout << "Книг еще нет\n";return; }
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
	if (!size) { cout << "Книг еще нет\n";return; }
	double cost;
	char str[sizeStrings];
	int n;

	while (true)
	{
		cout << "Что вы хотите поменять?\n";
		cout << "1.Название\n";
		cout << "2.Имя автора\n";
		cout << "3.Фамилию автора\n";
		cout << "4.Стоимость книги\n";
		cout << "5.Количество экземпляров\n";
		cout << "6.Год издания\n";
		cout << "7.Шифр Темы\n";
		cout << "0.Выход\n";
		cin >> n;
		cin.ignore(1);
		switch (n)
		{
		case 0:return;
		case 1:cout << "Введите название\n";
			cin.getline (str,sizeStrings);
			books.setTitle(str);break;
		case 2:cout << "Введите имя\n";
			cin.getline(str, sizeStrings);
			books.setAuthorName(str);break;
		case 3:cout << "Введите фамилию\n";
			cin.getline(str, sizeStrings);
			books.setAuthorSurname(str);break;
		case 4:cout << "Введите стоимость\n";
			cin >> cost;
			books.setCost(cost);break;
		case 5:cout << "Введите количество экзкмпляров\n";
			cin >> n;
			books.setQuantity(n);break;
		case 6:cout << "Введите год\n";
			cin >> n;
			books.setYear(n);break;
		case 7:cout << "Введите шифр темы\n";
			cin.getline(str, sizeStrings);
			books.setCipherThemes(str);break;
		default:cout << "Неверный ввод.Операция прервана\n";return;
			break;
		}
		cout << "Успешно!\n";
	}
}
void createBook(Book& book) {

	cout << "Введите название книги,имя,фамилию автора,год издания,количество,стоимость,Шифр Темы(в данном порядке).Каждый обьект с новой строки!\n";
	cin >> book;
	cout << "Успешно!\n";
}
void deleteBook(Book* books, size_t& size,size_t index) {
	if (!size) { cout << "Книг еще нет\n";return; }
	if(index>=size)cout << "Неверный индекс.Операция прервана\n";
	books[index].remove();
	swap(books[index], books[size - 1]);
	--size;

}
void printAllBooks(const Book* books, const size_t size) {
	if (!size) { cout << "Книг еще нет\n";return; }
	int n;
	char filename[50];
	cout << "1-Записать в фаил\n2 - Вывести на экран\n";
	cout << "иная клавиша-отмена операции\n";
	cin >> n;
	if (n == 1) {
		cout << "Введите имя файла:\n";
		cin >> filename;
		writeArrayOfBooks(books, size, filename);
		cout << "Успешно!";
	}
	else if (n == 2) {
		for (int i = 0;i < size;i++) {
			cout << i + 1 << ".\n" << books[i];
		}
		cout << "\n";
	}
	else {
		cout << "ВВедена неверная клавиша.Операция прервана.\n";
	}

}
void editFile() {
	size_t size = 0;
	size_t indexes[3];
	int n;
	Book* books = new Book[3];
	char filename[50];
	cout << "Введите имя файла\n";
	cin.getline(filename, 50);
	try {
		size = readArrayOfBooks(books, 100, filename);
	}
	catch (...) {
		cout << "Фаил не найден\n";return;
	}
	printAllBooks(books, size);
	cout << "Что вы ходите сделать?\n";
	cout << "1-Добавить обьект(ы)\n";
	if (size) {
		cout << "2-Редактировать обьект(ы)?\n";
		cout << "3-удалить обьект(ы)\n";
	}
	cout << "иная клавиша-отмена операции\n";
	cin >> n;
	cin.ignore(1);
	if (n == 1)
	{
		cout << "Сколько книг вы хотите добавить?\n";
		cin >> n;
		for (int i = 0;i < n;i++)
			createBook(books[size + i]);
		size += n;
		cout << "Все книги добавлены!\n";
	}
	else if (n == 2 && size)
	{
			cout << "Введите индексы книг которые вы хотите отредактировать\n";
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
			cout << "Введите индексы книг которые вы хотите удалить\n";
			size_t s = 0;
			while (cin.peek() != '\n') {
				cin >> indexes[s];
				++s;
			}
			for (int i = 0;i < s;i++)
				deleteBook(books, size, i);
			cout << "Успешно!\n";
	}
	
	writeArrayOfBooks(books, size, filename);
	delete[] books;
}