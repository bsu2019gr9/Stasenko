#define _CRT_SECURE_NO_WARNINGS
#include "Book.h"

using namespace std;


Book::Book():title("undefined"),authorName("undefined" ),authorSurname("undefined"),
cipherThemes(new char[10]),year(0),quantity(0),cost(0),cipherBook(new char[10])
{
	strcpy(this->cipherThemes, "undefined");
	setCipherBook();


}

Book::Book(const char* title, const char* authorName, const char* authorSurname, const int year, const int quantity, const double cost, const char* cipherThemes="other"):
	cipherBook(new char[10]),cipherThemes(new char[strlen(cipherThemes)+1]),
	year(year),quantity(quantity),cost(cost)
{
	if (!strlen(title))throw "Wrong title";
	if (!strlen(authorName))throw "Wrong authorName";
	if (!strlen(authorSurname))throw "Wrong authorSurname";
	if (!strlen(cipherThemes))throw "Wrong chipherThemes";
	if (quantity<=0) throw "Wrong quantityOfExamples";
	if (year<0) throw "Wrong yearOfPublishing";
	if (cost<0) throw "Wrong cost";

	strcpy(this->title, title);
	strcpy(this->authorName, authorName);
	strcpy(this->authorSurname, authorSurname);
	strcpy(this->cipherThemes, cipherThemes);
	setCipherBook();
	
}

Book::Book(const Book& book):year(book.year), cost(book.cost), quantity(book.quantity),
cipherBook(new char[10]), cipherThemes(new char[strlen(book.cipherThemes) + 1])
{
	strcpy(title, book.title);
	strcpy(authorName,book.authorName);
	strcpy(authorSurname, book.authorSurname);
	strcpy(cipherThemes, book.cipherThemes);
	strcpy(cipherBook, book.cipherBook);
}


void Book::setTitle(const char* title)
{
	if (!strlen(title))throw "Wrong title";
	strcpy(this->title, title);
}

void Book::setAuthorName(const char* authorName)
{
	if (!strlen(authorName))throw "Wrong authorName";
	strcpy(this->authorName, authorName);
}

void Book::setAuthorSurname(const char* authorSurname)
{
	if (!strlen(authorSurname))throw "Wrong authorSurname";
	strcpy(this->authorSurname, authorSurname);
}

void Book::setCipherBook()
{


	srand(time(NULL));
	for (size_t i = 0; i < 9; i++)
	{
		cipherBook[i] = 65 + rand() % 26;
	}
	cipherBook[9] = 0;
}

void Book::setCipherThemes(const char* cipherThemes)
{
	if (!strlen(cipherThemes))throw "Wrong cipherThemes";
	delete[] this->cipherThemes;
	this->cipherThemes = new char[strlen(cipherThemes) + 1];
	strcpy(this->cipherThemes, cipherThemes);
}

void Book::setYear(const int year)
{
	if (year < 0)throw "Wrong yearOfPublishing";
	this->year = year;
}

void Book::setQuantity(const int quantity)
{
	if (quantity <= 0)throw  "Wrong quantityOfExamples";
	this->quantity = quantity;

}

const char* Book::getTitle() const
{
	return &title[0];
}

const char* Book::getAuthorName() const
{
	return &authorName[0];
}

const char* Book::getAuthorSurname() const
{
	return &authorSurname[0];
}

 char* Book::getCipherBook() const
{
	return cipherBook;
}

 char* Book::getCipherThemes() const
{
	return cipherThemes;
}

size_t Book::getYear() const
{
	return year;
}

size_t Book::getQuantity() const
{
	return quantity;
}



double Book::getCost() const
{
	return cost;
}

void Book::setCost(const double cost)
{
	if (cost < 0)throw "Wrong cost";
	this->cost = cost;
}

Book& Book::operator=(const Book& book)
{
	delete[]cipherBook;
	delete[]cipherThemes;
	cipherBook= new char[10];
	cipherThemes = new char[strlen(book.cipherThemes) + 1];
	strcpy(title, book.title);
	strcpy(authorName,book.authorName);
	strcpy(authorSurname, book.authorSurname);
	strcpy(cipherThemes, book.cipherThemes);
	strcpy(cipherBook, book.cipherBook);
	quantity = book.quantity;
	year = book.year;
	cost = book.cost;
	return *this;
}

void Book::remove()
{
	delete[]cipherThemes;
	delete[]cipherBook;
	cipherBook = new char[10];
	cipherThemes = new char[10];
	strcpy(title, "undefined");
	strcpy(cipherThemes, "undefined");
	strcpy(cipherBook, "undefined");
	strcpy(authorName, "undefined");
	strcpy(authorSurname, "undefined");
	year = 0;
	cost = 0;
	quantity = 0;
	
}

Book::~Book()
{
	delete[] cipherThemes;cipherThemes = nullptr;
	delete[] cipherBook;cipherBook = nullptr;

}

ostream& operator<<(ostream& os, const Book& book)
{
	os <<"Title: "<< book.title << "\n";
	os <<"Author: " <<book.authorName <<" "<< book.authorSurname << "\n";
	os <<"yearOfPublishing: " <<book.year << "\n";
	os <<"quantityOfExamples: "<<book.quantity << "\n";
	os <<"Cost: "<<book.cost << "\n";
	os << "cipherThemes: " << book.cipherThemes << "\n";
	os <<"cipherBook: "<<book.cipherBook<<"\n";
	return os;
}

istream& operator>>(istream& is, Book& book)
{
	char buffer[sizeStrings];
	double tmpcost;
	size_t tmp;
	if(is.peek()=='\n')is.ignore(1);
	is.getline(buffer,sizeStrings);
	book.setTitle(buffer);
	is.getline(buffer, sizeStrings);
	book.setAuthorName(buffer);
	is.getline(buffer,sizeStrings);
	book.setAuthorSurname(buffer);
	is >> tmp;
	book.setYear(tmp);
	is >> tmp;
	book.setQuantity(tmp);
	is >> tmpcost;
	book.setCost(tmpcost);
	is.ignore(1);
	is.getline(buffer, sizeStrings);
	book.setCipherThemes(buffer);
	book.setCipherBook();
	return is;
}
ifstream& operator>>(ifstream& is, Book& book)
{
	char buffer[sizeStrings];
	double tmpcost;
	size_t tmp;
	is.getline(buffer, sizeStrings);
	book.setTitle(buffer);
	is.getline(buffer, sizeStrings);
	book.setAuthorName(buffer);
	is.getline(buffer, sizeStrings);
	book.setAuthorSurname(buffer);
	is >> tmp;
	book.setYear(tmp);
	is >> tmp;
	book.setQuantity(tmp);
	is >> tmpcost;
	book.setCost(tmpcost);
	is.ignore(1);
	is.getline(buffer, sizeStrings);
	book.setCipherThemes(buffer);
	book.setCipherBook();
	return is;
}

ofstream& operator<<(ofstream& os, Book& book)
{
	os << book.title << "\n";
	os << book.authorName << "\n";
	os << book.authorSurname << "\n";
	os << book.year<< "\n";
	os << book.quantity<< "\n";
	os << book.cost << "\n";
	os << book.cipherThemes << "\n";
	return os;
}


void swap(Book& book1, Book& book2)
{
	swap(book1.authorName, book2.authorName);
	swap(book1.authorSurname, book2.authorSurname);
	swap(book1.cipherBook, book2.cipherBook);
	swap(book1.cipherThemes, book2.cipherThemes);
	swap(book1.cost, book2.cost);
	swap(book1.year,book2.year);
	swap(book1.title, book2.title);
	swap(book1.quantity, book2.quantity);
}
