#include<iostream>
#include<fstream>

using namespace std;

int main()
{
	
	ifstream in;
	in.open("kk.txt");
	int n;
	int a[100][100];
		in >> n;
	
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			in >> a[i][j];
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << a[i][j] << "  ";
		}
		cout << endl;
	}
	return 0;
}
	