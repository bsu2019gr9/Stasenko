#include "Book.h"
#include "BooksFunctions.h"
using namespace std;
int chooseAction();
int chooseAction() {

	cout << "Что вы хотите сделать?\n";
	cout << "1.Вывести список книг\n";
	cout << "2.Создать книгу\n";
	cout << "3.Редактировать книгу\n";
	cout << "4.Удалить книгу\n";
	cout << "5.Удалить книги выше заданной цены\n";
	cout << "6.Вывести список книг по заданной теме, выпущенных после заданного года.\n";
	cout << "7.Вывести список книг заданного автора в порядке возрастания года издания\n";
	cout << "8.Получить список всех книг, упорядоченный по году издания, количество книг, общую стоимость книг\n";
	cout << "9.Редактирование файла\n";
	cout << "10.Считать массив книг из файла\n";
	cout << "0.Выход\n";
	int n;
	cin >> n;
	cin.ignore(1);
	return n;


}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "Приветствуем вас в нашей библиотеке! ";
	const size_t N = 100;
	double totalCost = 0;
	int index;
	size_t totalQuantity=0;
	size_t size = 0;
	Book* library = new Book[N];
	int num;
	char filename[50];
	while (true)
	{
		num = chooseAction();
		switch (num) {
		case 0:return 0;
		case 1: printAllBooks(library, size);break;
		case 2: createBook(library[size]); ++size;break;
		case 3:
			if (!size) { cout << "Книг еще нет\n";break; }
			cout << "Введите индекс\n";
			cin >> index;
			editBook(library[index - 1], size);break;
		case 4:
			if (!size) { cout << "Книг еще нет\n";break; }
			cout << "Введите индекс\n";
			cin >> index;
			deleteBook(library, size, index - 1);cout << "Успешно!";break;
		case 5:deleteBooksByCost(library, size);break;
		case 6:printBooksByThemesAfterYear(library, size);break;
		case 7:printBooksByAuthorAscendingYear(library, size);break;
		case 8:if (!size) { cout << "Книг еще нет\n";break; }sortBookgetNumberOfBooksgetTotalCost(library, size, totalQuantity, totalCost);printAllBooks(library, size);
			cout << "Общая сумма: " << totalCost << "\nОбщее количество книг: " << totalQuantity << "\n";
			break;
		case 9:editFile();break;
		case 10:
			cout << "Введите имя файла\n";
			cin.getline(filename, 50);
			try {
				size = readArrayOfBooks(library, 100, filename);
			}
			catch (...) {
				cout << "Фаил не найден\n";break;
			}
			cout << "Успешно!\n";
			break;
		default:cout << "Неверный ввод\n";
		}
	}
}