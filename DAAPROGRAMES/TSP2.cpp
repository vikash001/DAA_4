#include<iostream>
#include<vector>
#include<string>
#include<climits>

using namespace std;

int a[101][101];
int N;
vector<int> result(N + 2);
bool visited[101];
int cb = INT_MAX;

void print()
{
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << "  ";
	}
	cout << endl;
}
void print2(vector<int>& path)
{
	for(int i = 0; i < path.size(); i++) {
		cout << path[i] << "  ";
	}
	cout << endl;
}

int path_dist(int s, int level, int cd, vector<int>& path, int k)
{
	int b = 9999999;
	if(level == N + 1){
		 visited[1] = false;
		//path[k] = 1;
		return 0;
	}
	if(level == N) {
		visited[1] = true;
	}
	for(int i = 1; i <= N; i++) {
		if(visited[i] && a[s][i] != 0) {
			cd = cd + a[s][i];
			visited[i] = false;
			path[k] = i;
			k++;
			
			int temp = path_dist(i, level + 1, cd, path, k);
			if(cb > temp + cd) {
				cb = temp + cd;
				result = path;
				cout << cb << " : ";
				print();
				cout << cb << " : ";
				print2(path);
			}
			if(b > temp + a[s][i]) {
				b = temp + a[s][i];
			}
			visited[i] = true;
			// path[k] = 0;
			k--;
			
		}
	}
	return b;
}
			

int main()
{
	
	cin >> N;
	vector<int> path(N + 2, 0);
	for(int i = 1; i <= N; i++) {
		visited[i] = true;
		for(int j = 1; j <= N; j++) {
			cin >> a[i][j];
			/*if (a[i][j] == 0)
			a[i][j] = 99999;*/
		}
	}
	int k = 0;
	int distance = path_dist(1, 1, 0, path, k);
	cout << distance << endl;
	cout << cb << endl;
	print();
	return 0;
}