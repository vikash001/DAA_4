#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<climits>

using namespace std;


void print(vector<int> result)
{
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << "  ";
	}
	cout << endl;
}

int bnb(int a[][101], int N, bool visited[], vector<int> &result, int *k, int *CB, int path, int CD, int level, vector<int>& p, float *est, int est_min[])
{
	if(level == N + 1) {
		p[(*k)] = path;
		visited[1] = false;
		//cout << "value of path " << path  << " in n + 1 " << level << endl; 
		return 0;
	}
	if(*CB < CD + (*est)){
		//cout << *CB << "  " << CD + *est <<  " level " << level << " path " << path << endl;
		return 9999999;
	}
	if(level == N) {
		//cout << "level " << level << " path " << path << endl;
		if(a[path][1] != 0)
			visited[1] = true;
	}
	
	
	int b = 999999;
	for(int i = 1; i <= N; i++) {
		visited[path] = false;
		p[(*k)] = path;
		(*k)++;
		*est = *est - (float)est_min[path]/2;
		if(visited[i] && a[path][i] != 0){
			//cout << "value of path " << path << " value of index : " << i << "  "  << endl;
			CD = CD + a[path][i];
			
			int temp = bnb(a, N, visited, result, k, CB, i, CD, level + 1, p, est, est_min);
			
			if(*CB > temp + CD) {
				*CB = temp + CD;
				result = p;
				cout << *CB << " : " ;
				print(result);
				
			}
			CD = CD - a[path][i];
			if(b >= temp + a[path][i]) {
				b = temp + a[path][i];
			}
			
		}
		visited[path] = true;
		(*k)--;
		*est = *est + (float)est_min[path]/2;
	}
	return b;
	
}



int main()
{
	int a[101][101];
	bool visited[101];
	int N;
	int k = 0;
	vector<int> result;
	int CB = INT_MAX;
	int min_est[101];
	cin >> N;
	float total = 0;
	int c;
	vector<int> path(N + 1, -1);
	for(int i = 1; i <= N; i++) {
		int min2 = 9999999;
		int min1 = 9999999;
		visited[i] = true;
		for(int j = 1; j <= N; j++) {
			cin >> a[i][j];
			if(a[i][j] < min1 && i != j && a[i][j] != 0){
				min2 = min1;
				min1 = a[i][j];
			}else if(a[i][j] < min2 && i != j && a[i][j] != 0) {
				min2 = a[i][j];
			}
		}
		min_est[i] = min1 + min2;
		total += (min1 + min2);
	}
	for(int i = 1; i <= N; i++) {
		cout << min_est[i] << endl;
	}
	k = 0;
	total = total/2;
	//cout << total << endl;
	int distance = bnb(a, N, visited, result, &k, &CB, 1, 0, 1, path, &total, min_est);
	cout << distance << endl;
	print();
	//cout << "\n" << CB << endl;
	return 0;
}
