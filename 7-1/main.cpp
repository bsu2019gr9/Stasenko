#include "Book.h"
#include "BooksFunctions.h"
using namespace std;
int chooseAction();
int chooseAction() {

	cout << "��� �� ������ �������?\n";
	cout << "1.������� ������ ����\n";
	cout << "2.������� �����\n";
	cout << "3.������������� �����\n";
	cout << "4.������� �����\n";
	cout << "5.������� ����� ���� �������� ����\n";
	cout << "6.������� ������ ���� �� �������� ����, ���������� ����� ��������� ����.\n";
	cout << "7.������� ������ ���� ��������� ������ � ������� ����������� ���� �������\n";
	cout << "8.�������� ������ ���� ����, ������������� �� ���� �������, ���������� ����, ����� ��������� ����\n";
	cout << "9.�������������� �����\n";
	cout << "10.������� ������ ���� �� �����\n";
	cout << "0.�����\n";
	int n;
	cin >> n;
	cin.ignore(1);
	return n;


}

int main() {
	setlocale(LC_ALL, "Russian");
	cout << "������������ ��� � ����� ����������! ";
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
			if (!size) { cout << "���� ��� ���\n";break; }
			cout << "������� ������\n";
			cin >> index;
			editBook(library[index - 1], size);break;
		case 4:
			if (!size) { cout << "���� ��� ���\n";break; }
			cout << "������� ������\n";
			cin >> index;
			deleteBook(library, size, index - 1);cout << "�������!";break;
		case 5:deleteBooksByCost(library, size);break;
		case 6:printBooksByThemesAfterYear(library, size);break;
		case 7:printBooksByAuthorAscendingYear(library, size);break;
		case 8:if (!size) { cout << "���� ��� ���\n";break; }sortBookgetNumberOfBooksgetTotalCost(library, size, totalQuantity, totalCost);printAllBooks(library, size);
			cout << "����� �����: " << totalCost << "\n����� ���������� ����: " << totalQuantity << "\n";
			break;
		case 9:editFile();break;
		case 10:
			cout << "������� ��� �����\n";
			cin.getline(filename, 50);
			try {
				size = readArrayOfBooks(library, 100, filename);
			}
			catch (...) {
				cout << "���� �� ������\n";break;
			}
			cout << "�������!\n";
			break;
		default:cout << "�������� ����\n";
		}
	}
}