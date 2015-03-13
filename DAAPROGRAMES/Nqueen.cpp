#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

void print(int a[], int n);
bool check(vector<int> v1);
bool check2(vector<int> v1);
vector<int> check_ref(vector<int> v, int n);
vector<int> check_angle(vector<int> v, int n);
int a[100];
vector< vector<int> > vv;
int counter = 0;
int counter1 = 0;
bool isSafe(int a[], int row, int col)
{
	for(int i = 0; i < row; i++){
		if(a[i] == col || abs(i - row) == abs(a[i] - col)){
			return false;
		}
	}
	return true;
}
void solution(int a[], int n)
{
	vector<int> v(n , 0);
	vector<int> v1(n , 0);
	for(int i = 0; i < n; i++) {
		v[i] = a[i];
		v1[i] = a[i];
	}
	if(vv.size() == 0){
		vv.push_back(v);
		//print(a, n);
		counter++;
	} else {
		int count = 0;
		for(int i = 0; i < 4; i++){
			vector<int> b = check_angle(v, v.size());
			vector<int> c = check_ref(b, b.size());
			if(check2(b) && check2(c)){
				count++;
			}else {
				return;
			}
			v = b;
			
		}
		if(count == 4)
		vv.push_back(v1);
		counter++;
		//print(a, n);
	}
	
}
bool check2(vector<int> v)
{
	bool flag = binary_search(vv.begin(), vv.end(), v);
	if(flag) {
		return false;
	}
	return true;
}
bool check(vector<int> v1)
{
	vector<int> v3;
	int count;
	for(int i = 0; i < vv.size(); i++) {
		v3 = vv[i];
		count = 0;
		for(int j = 0; j < v1.size(); j++) {
			if(v1[j] == v3[j]) {
				count++;
			}
		}
		if(count == v1.size()){
			return false;
		}
	}
	return true;
}
	
vector<int> check_angle(vector<int> v, int n)
{	
	vector<int> b(n, 0);
	for(int i = 0; i < v.size(); i++){
		b[v[i]] = (n - i)-1;
		
	}
	return b;
}

vector<int> check_ref(vector<int> v, int n)
{
	vector<int> b(n, 0);
	for(int i = 0; i < v.size(); i++){
		b[i] = (n - v[i]) - 1;
	}
	return b;
}

void Nqueen(int a[], int n, int row)
{
	for(int i = 0; i < n; i++){
		if (row == 0 && i == n / 2) {
			return;
		}
		if(isSafe(a, row, i)){
			a[row] = i;
			if(row == n - 1){
				solution(a, n);
				counter1++;
				return;
			}
			Nqueen(a, n, row+1);
		}
	}
}

void print(int a[], int n)
{
	for(int i = 0; i < n; i++){
		cout << a[i]+1;
	}
	cout << endl;
}

int main()
{
	int n;
	cin >> n;
	Nqueen(a, n , 0);
	cout << "Total unique solution is :  " << counter << endl;
	cout << "Total Number Of solution is :  "<< counter1 << endl;
	return 0;
}
