#include<iostream>
#include<string>
#include<vector>

int check(int i, int j, int l, string ss) 
{
	int l = i;
	int r = j;
	if( i >= 0 && j <= l-1){
		while(ss[l] == ss[r]) {
			l--;
			r++;
		}
	}
	return (r - l - 1);
}

int main()
{
	string ss1;
	cin >> ss1;
	int l = ss1.size();
	string ss = "";
	vector<int> vv((2*l+1), 0);
	int l, r;
	for(int i = 1; i < n; i++) {



