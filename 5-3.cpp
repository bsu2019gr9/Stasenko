#include<iostream>
#include<fstream>  
using namespace std;
struct color { unsigned char r; unsigned char g; unsigned char b; };

int main() {
	ifstream fin("d:\\1.bmp", ios::binary); 
	ofstream fout("d:\\rez.bmp", ios::binary);
	if (!fin) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!fout) { cout << "   file d:\\rez.bmp. Can't create\n"; exit(1); }

	char buf[30];
	color c;
	unsigned int w, h;

	fin.read((char*)&buf, 18);    
	fout.write((char*)&buf, 18);    
	fin.read((char*)&buf, 8);
	w = 64;
	fout.write((char*)&w, 4);    
	h = 64; 
	fout.write((char*)&h, 4);    
	fin.read((char*)&buf, 28);   
	fout.write((char*)&buf, 28);   
	int step1 = 4;
	int step2 = 4;
	c.r=0,c.g=0,c.b=0;
	for (int i = 1;i <= h ;i++) {
		for(int j=1;j<=w;j++){
	    fout.write((char *)&c, 3);     
	    c.g+=step1;
	}
		c.r+=step2;

	}	

	

	fin.close();
	fout.close();
	return 1;
}