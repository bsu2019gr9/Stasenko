#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#include <time.h>
using namespace std;
const size_t sizeStrings = 40;
class Book
{
private:
	char* cipherThemes;
	char* cipherBook;
	char authorSurname[sizeStrings];
	char authorName[sizeStrings];
	char title[sizeStrings];
	size_t year;
	size_t quantity;
	double cost;
	void setCipherBook();
public:
	Book();
	Book(const char* title, const char* authorName, const char* authorSurname, const int yearOfPublishing, const int quantityOfExamples, const double cost, const char* cipherThemes);
	Book(const Book& book );
	friend ostream& operator<<(ostream& os,const Book& book);
	friend istream& operator>>(istream& is, Book& book);
	friend ifstream& operator>>(ifstream& is, Book& book);
	friend ofstream& operator<<(ofstream& is, Book& book);
	void setTitle(const char * title);
	void setAuthorName(const char * authorName);
	void setAuthorSurname(const char * authorSurname);
	void setCipherThemes(const char* cipherThemes);
	void setYear(const int year);
	void setQuantity(const int quantity);
	void setCost(const double cost);
	const char* getTitle() const;
	const char* getAuthorName()const ;
	const char* getAuthorSurname() const;
	char* getCipherBook()const;
	char* getCipherThemes()const;
	size_t getYear()const;
	size_t getQuantity()const;
	friend void swap( Book& book1, Book& book2);
	double getCost() const;
	Book& operator=(const Book& book);
	void remove();
	
	~Book();
};


