#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#define MAX 1000;

using namespace std;

int pi[1000];
int pj[1000];


int product(int i, int k, int j) 
{
	int p;
	if(i != 0){
		p = pj[i]*pj[k]*pj[j];
	}else {
		p = pi[k]*pj[k]*pj[j];
	}
	return p;
}

void print(int *a, int n)
{
	for(int i = 1; i <= n; i++ ) {
		for(int j = 1; j <= n; j++) {
			cout << "  ";
		}
		cout << endl;
	}
}
void chain_order(int p )
{
	int n = p;
	int m[n+1][n+1];
	int s[n +1][n +1];
	int j;
	int q;
	for(int i = 1; i <= n; i++) {
		m[i][i] = 0;
		s[i][i] = 0;
	}
	for(int l = 2; l <= n; l++) {
		for(int i = 1; i <= n - l + 1; i++) {
			j = (i + l) - 1;
			//cout << j << endl;
			m[i][j] = INT_MAX;
			for(int k = i; k <= j - 1; k++) {
				q = m[i][k] + m[k+1][j] + product(i-1, k, j);
				if(q < m[i][j]) {
					m[i][j] = q;
					
					s[i][j] = k;
				}
				//cout << "value of i " << i << " value of k " << k << " value of j " << j << " value of q " << q << endl;
			}
		}
	}
	for(int i = 1; i <= n;  i++ ) {
		for(int k = i; k <= n; k++) {
			cout << m[i][k] << "  ";
		}
		cout << endl;
	}
	cout << endl;
	for(int i = 1; i <= n ;  i++ ) {
		for(int k = i; k <= n ; k++) {
			if(i != k)
			cout << s[i][k] << "  ";
		}
		cout << endl;
	}
	
	//print(s, n);
}

int main()
{
	int n;
	cin >> n;
	pi[0] = 1;
	pj[0] = 1;
	for(int i = 1; i <= n; i++) {
		cin >> pi[i] >> pj[i];
	}
	chain_order(n);
	return 0;
}