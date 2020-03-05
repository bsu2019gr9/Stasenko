#define _CRT_SECURE_NO_WARNING
#include <iostream>
#include <cstring>
using namespace std;
void strcut(char* begin,char* end) {
	if (begin == end)return;
	char* p = nullptr;
	p = new(nothrow) char[strlen(end)+1];
	if (!p) {
		cout << "Bad alloc";exit(0);
	}
	strcpy(p, end);
	*begin = 0;
	strcat(begin, p);
	for (char* ptr = begin+strlen(begin);*ptr;++ptr) *ptr = 0;
	delete[] p;
	p = nullptr;
}
int main() {

	char str[]="BABA ORT";
	strcut(str+5,str+8);

}