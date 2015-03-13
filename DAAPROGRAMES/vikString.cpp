#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<sstream>

using namespace std;

int main()
{
	string s;
	map<string , int> mm;
	istringstream ss;
	
	ss("kk.txt");
	while(ss.good()){
		s << ss;
		mm[s]++;
		s.clear();
	}
	return 0;
}