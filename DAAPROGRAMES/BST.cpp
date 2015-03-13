#include<iostream>
#include<vector>
#include<string>

using namespace std;
	
int product()
{
	
}
	
void calculate_cost(int prob[], int n, int s[])
{
	int c[n + 1][n + 1];
	int pos[n + 1][n + 1];
	int q;
	int min;
	int mink;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= n; j++) {
			c[i][j] = 0;
			pos[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		c[i][i] = prob[i];
		pos[i][i] = i;
	}
	for(int i = 1; i < n; i++) {
		if((2*prob[i] + prob[i+1]) < (prob[i] + 2*prob[i+1])){
			c[i][i+1] = 2*prob[i] + prob[i+1];
			pos[i][i+1] = i+1;
		}else {
			c[i][i+1] = prob[i] + 2*prob[i+1];
			pos[i][i+1] = i;
		}
	}
	for(int i = 3; i <= n; i++) {
		for(int j = 1; j <= n - i + 1; j++) {
			int l = j;
			int m = i + j - 1;
			if(l - 1 > 0 && l + 1 < n) {
				 min = c[l][l - 1] + c[l+1][m] + s[m] - s[l - 1];
			}else if(l - 1 <= 0 && l + 1 < n){
				min = 0 + c[l+1][m] + s[m] - s[l - 1];
			}else if(l + 1 > n) {
				min = c[l][l - 1] + 0 + s[m]  - s[l - 1];
			}
			
			cout <<" value of min  " <<  min <<  "value of l " << l <<endl;
			mink = l;
			for(int k = l+1; k <= m; k++){
				if(k < n){
					q = c[l][k - 1] + c[k+1][m] + s[m] - s[l - 1];
				}else {
					q = c[l][k - 1] + 0 + s[m] - s[l - 1];
				}
				
				cout << "value of q " << q <<  " value of k " << k << endl;
				if(min > q){
					min = q;
					mink = k;
				}
			}
			c[l][m] = min;
			pos[l][m] = mink;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			
				cout << pos[i][j] << "  ";
			
		}
		cout << endl;
	}
	cout << c[1][n] << endl;
	
}


int main()
{
		int prob[101];
		int n;
		int sum[101];
		int node[101];
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> node[i] >> prob[i];
		}
		sum[0] = 0;
		for(int i = 1; i <= n; i++) {
			sum[i] = prob[i] + sum[i -1];
		}
		for(int i = 1; i <= n; i++) {
			cout << sum[i] << "  ";
		}
		cout << endl;
		calculate_cost(prob, n, sum);
		return 0;
}