//В тексте выбрать все слова - палиндромы и расположить их в порядке возрастания их длин
#include <fstream>
#include <iostream>
using namespace std;
bool isPalindrom(char* str) {
	int beg = 0; int end = strlen(str)-1;
	while (beg < end)
	{
		if (str[beg] != str[end])return false;
		++beg; --end;
	}
	return true;
}
void insertionsort(char** strs, int* lengths, int len) {
	for (int i = 1; i < len; i++)
		for (int j = i; j > 0 && lengths[j] < lengths[j - 1]; --j)
		{
			swap(lengths[j - 1], lengths[j]);
			swap(strs[j - 1], strs[j]);
		}
}
void Task() {
	ifstream fin("input.txt");
	ofstream fout("result.txt");
	int MAX_SIZE = 1000000;
	char* text = new char[MAX_SIZE];
	char** output = new char*[MAX_SIZE];
	int* len_output = new int [MAX_SIZE];
	int curr_size = 0;
	while (true)
	{
	
			fin.getline(text, MAX_SIZE);
			if (fin.eof())
				break;
			if (fin.fail()) fin.clear();
			char* word = strtok(text, " ,…–][:;*.( )«—»!? -\"\t0123456789");
			while (word)
			{

				if (isPalindrom(word)) {
					
					len_output[curr_size] = strlen(word);
					output[curr_size] = new char[len_output[curr_size]];
					strcpy(output[curr_size], word);
					++curr_size;
				}
				word = strtok(NULL, " ,…–[]:;*.( )«»—!? -\"\t0123456789");
			}
	}
	insertionsort(output, len_output, curr_size);
	for (size_t i = 0; i < curr_size; i++)
	{
		fout << len_output[i] << " : " << output[i] << "\n";
	}
}
int main() {
	setlocale(LC_ALL, "Russian");
	Task();
}
