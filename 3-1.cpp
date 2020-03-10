//(8-9)Найти и вывести на экран все слова строки, 
//в которых все буквы различны. Вставить перед такими словами заданную подстроку.
#include <iostream>
using namespace std;
void insertStr(char* dest, char src[]);
void Task(char*& str, char substr[]) {
	const int N = 26;
	int len = strlen(str);
	char* word = nullptr;
	bool letters[N] = { 0 };
	word = strtok(str, " ");
	while (word) {
		int i = 0;
		while (word[i]) {
			if (letters[word[i] - 'a'])  break;
			letters[word[i] - 'a'] = true;
			++i;
		}
		if (i == strlen(word)) {
			cout << word << "\n";
			insertStr(str + (word - str), substr);
			word = strtok(NULL, " ");
			len += strlen(substr)+1;
		}

		for (size_t i = 0; i < N; i++)
		{
			letters[i] = 0;
		}
		str[strlen(str)] = 32;
		word = strtok(NULL, " ");

	}
	str[len] = 0;
}
void insertStr(char* dest, char src[]) {
	int dest_len = strlen(dest);
	dest[dest_len] = ' ';
	int src_len = strlen(src);
	if (src_len > 0)for (int i = strlen(dest); i >= dest_len; --i) {
		dest[i + src_len+1] = dest[i];
	}
	strcpy(dest+dest_len+1, src);
	dest[dest_len + src_len+1] = 32;
}
int main() {


	int size = 100000;
	char* substr=new char [size];
	char* str=new char[size];
	for (int i(0); i < size; ++i)
		str[i] = 0;
	cout << "Enter str\n";
	cin.getline(str, size);
	cout << "Enter substr\n";
	cin >> substr;
	cout << "Words with different letters:\n";
	Task(str,substr);
	cout << "New str:\n";
	cout << str << "\n";


}