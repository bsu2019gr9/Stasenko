#include<iostream>
#include<fstream>  
using namespace std;
struct color { unsigned char r, g, b; };

int main() {
	ifstream fin("d:\\1.bmp", ios::binary); 
	ofstream fout("d:\\rez.bmp", ios::binary);
	if (!fin) { cout << "No file d:\\1.bmp. Can't open\n"; exit(1); }
	if (!fout) { cout << "   file d:\\rez.bmp. Can't create\n"; exit(1); }

	char buf[30];
	color c1,c2;
	unsigned int w, h;
	fin.read((char*)&buf, 18);    
	fout.write((char*)&buf, 18);    
	fin.read((char*)&buf, 8);
	w = 400;
	fout.write((char*)&w, 4);    
	h = 400; 
	fout.write((char*)&h, 4);    
	fin.read((char*)&buf, 28);   
	fout.write((char*)&buf, 28);   
	
	c1.r=0,c1.g=0,c1.b=0;
	c2.r=255,c2.g=200,c2.b=100;
	double stepR = (c2.r - c1.r)*1.0/(w*h);
	double stepG = (c2.g - c1.g)*1.0/(w*h);
	double stepB = (c2.b - c1.b)*1.0/(w*h);
	double cR = c1.r, cG = c1.g, cB = c1.b;
	for (int i = 1;i <= h;i++) {
		for (int j = 1;j <= w;j++) {
			fout.write((char*)&c1, 3);
			cR += stepR;
			
			c1.r = cR;
			

		}
		cB += stepB;
		cG += stepG;
		c1.g = cG;
		c1.b = cB;
	}
	fin.close();
	fout.close();
	return 1;
}