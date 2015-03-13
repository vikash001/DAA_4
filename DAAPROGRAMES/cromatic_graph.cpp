#include<iostream>
#include<vector>

using namespace std;
int a[100][100];
int n;
bool color(int c[], int count, int l) 
{
	if(n == l) {
		return true;
	}
	bool flag = true;
	for(int i = 0; i < count; i++) {
		flag = true;
		for(int j = 0; j < l; j++) {
			if(c[j] == i && a[j][l] == 1) {
				flag = false;
				break;
			}
		}
			if(flag == true) {
				c[l] = i;
				if(color(c, count, l+1)) {
					return true;
				}
			}
		
	}
	return false;
}

int main()
{
	int col[100];
	int counter = 1;
	int level = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	while(!color(col, counter, level)) {
		counter++;
	}
	cout << counter << endl;
	return 0;
}