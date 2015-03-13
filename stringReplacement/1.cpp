#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
#include <set>
#include <queue>
#include <climits>

using namespace std;

int cost[100][100] = {0};
string A, B;

void func(int x, int y)
{
		char ch1, ch2;
		int a,b,c;

		a = cost[x-1][y] + 1;
		b = cost[x][y-1] + 1;

		if (A[y] == B[x])
				c = cost[x-1][y-1];
		else
				c = cost[x-1][y-1] + 2;
		
		cost[x][y] = min( min(a,b), c);
}

int main()
{
	int d, i, j, r, n, m, c;

	cin >> A >> B;
	
	A = " " + A;
	B = " " + B;
	
	// n = no. of rows
	// m = no. of cols
	
	m = A.size();
	n = B.size();

	for (i = 0; i < m; i++)
			cost[0][i]  = i;
	for (i = 0; i < n; i++)
			cost[i][0] = i;
	
	cout << n << " " << m << endl;		
	for (d = 1; d < min(n, m); d++) {
			
			for (j = d; j < m; j++) {
					r = d;
					c = j;
					func(r,c);
			}

			for (j = d+1; j < n; j++) {
					r = j;
					c = d;
					func(r,c);
			}

	}

	cout << "Cost = " <<  cost[n-1][m-1] << endl << "  ";
	
	for (i = 0; i < m; i++)
			cout << A[i] << " ";
	cout << endl;		
	for (i = 0; i < n; i++) {
			cout << B[i] << " ";
			for (j = 0; j < m; j++)
					cout << cost[i][j] << " ";
					cout << endl;
	}

	return 0;
}
