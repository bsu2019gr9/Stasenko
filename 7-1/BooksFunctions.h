#pragma once
#include "Book.h"
void deleteBooksByCost(Book* books,size_t& size);
void printBooksByThemesAfterYear(const Book* books, const size_t size);
void printBooksByAuthorAscendingYear(const Book* books, const size_t size);
void sortBookgetNumberOfBooksgetTotalCost(Book* books, const size_t size, size_t& numberOfBooks, double& totalCost);
size_t readArrayOfBooks(Book* books, const size_t size, const char* filename);
void writeArrayOfBooks(const Book* books, const size_t size, const char* filename);
void editBook(Book& books, const size_t size);
void createBook(Book& book);
void printAllBooks(const Book* books, const size_t size);
void deleteBook(Book* books, size_t& size,size_t index);
void editFile();