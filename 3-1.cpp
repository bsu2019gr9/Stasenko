//(8-9)Найти и вывести на экран все слова строки, 
//в которых все буквы различны. Вставить перед такими словами заданную подстроку.
#include <iostream>
using namespace std;
void insertStr(char* dest, char src[]);
char* findWord(char*& word_pos, char separator = ' ');
void Task1(char*& str, char substr[]);
int main() {

	int size = 10000;
	char* substr=new char [size];
	char* str=new char[size];
	for (int i(0); i < size; ++i)
		str[i] = 0;
	cout << "Enter str\n";
	cin.getline(str, size);
	cout << "Enter substr\n";
	cin.getline(substr, size);
	cout << "Words with different letters:\n";
	Task1(str,substr);
	cout << "New str:\n";
	cout << str << "\n";


}
void Task1(char*& str, char substr[]) {
	const int N = 26;
	bool letters[N] = { 0 };// для всех букв в алфавите
	char* word_pos = str;//указатель на слово
	char* word = findWord(word_pos);
	while (word) {
		int i = 0;
		//проверка,являются ли все буквы разными
		while (word[i]) {
			if (letters[word[i] - 'a'])  break;
			letters[word[i] - 'a'] = true;
			++i;
		}
		if (i == strlen(word)) {
			cout << word << "\n";
			insertStr(word_pos, substr);
			word_pos[strlen(word_pos)] = ' ';
			word_pos += strlen(substr) + 1;//после вставки указатель указывает на вставленное слово
										//возвращаем его обратно на слово с разными буквами									
		}
		for (size_t i = 0; i < N; i++)letters[i] = 0;
		word_pos += strlen(word) + 1;
		word = findWord(word_pos);

	}
}
char* findWord(char*& word_pos, char separator) {
	/* ищет первое слово,пропуская разделители,
	запоминает начало слова,идет дальше,пока не найдет разделитель,
	копирует данное слово в отдельную память и возвращает указатель на эту память
	*/
	char* word = nullptr;
	char* p = word_pos;
	if (strlen(word_pos) < 1) {
		word_pos = nullptr; return nullptr;
	}
	while (*p && *p == separator)++p;
	word_pos = p;
	while (*p && *p != separator)++p;
	word = new char[p - word_pos + 1];
	strncpy(word, word_pos, p - word_pos);
	word[p - word_pos] = 0;
	return word;
}
void insertStr(char* dest, char src[]) {
	int size_src = strlen(src);
	for (int i = strlen(dest); i >= 0; --i)//сдвиг на n символов
		dest[i + size_src + 1] = dest[i];
	strcpy(dest, src);
}