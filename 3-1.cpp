//(8-9)Найти и вывести на экран все слова строки, 
//в которых все буквы различны. Вставить перед такими словами заданную подстроку.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>

using namespace std;
void Task(char*& str, char substr[]);
int main() {

	int size = 100000;
	char* substr = nullptr;
	char* str = nullptr;
	substr = new(nothrow) char[size];
	str = new(nothrow) char[size];
	for (int i(0); i < size; ++i)str[i] = 0;
	cout << "Enter substr\n";
	cin.getline(substr, size);
	cout << "Enter Str\n";
	cin.getline(str, size);
	cout << "Words with different letters:\n";
	Task(str,substr);
	cout << "New str:\n";
	cout << str << "\n";
	delete[] substr;
	delete[] str;
}
void Task(char*& str, char substr[]) {
	if (strlen(str) < 2)return;
	const int N = 26;
	int MAX_SIZE= 10 * strlen(str);
	bool letters[N] = { 0 };
	char* res = new(nothrow) char[MAX_SIZE];
	for (int i(0); i < MAX_SIZE; ++i)res[i] = 0;
	char* word = nullptr;
	word = strtok(str, " ");
	while (word) {
		int i = 0;
		while (word[i]) {
			//проверка все ли буквы в слове разные
			if (letters[word[i] - 'a'])  break;
			letters[word[i] - 'a'] = true;
			++i;
		}
		if (i == strlen(word)) {
			cout << word << "\n";
			strcat(res, substr);
			strcat(res, " ");
		}
		strcat(res, word);
		strcat(res, " ");
		for (size_t i = 0; i < N; i++)letters[i] = 0;
		word = strtok(NULL, " ");
	}

	delete[] str;
	str = res;
}