#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<sstream>
#include<fstream>

using namespace std;

int main()
{
	ostringstream ss;
	ifstream f("vv.txt");

	string s;
	map<string, bool> mm;

	while(f.good()) {
		f >> s;
		mm[s] = true;
		s.clear();
	}
	map<string, bool> :: iterator it = mm.begin();

	for(int i = 0; i < mm.size(); i++) {
		cout << (*it).first << "  " << (*it).second << endl;
		it++;
	}
	f.close();
	f.open("vv.txt");
	vector<string> s1;
	vector<vector<string> > s2;
	while(f.good()) {
		
		if(s[s.length() - 1] == ".") {
			s1.push_back(s);
			s2.push_back(s1);
			s1.clear();
		}else {
			s1.push_back(s);
		}
	}
	cout << "\n Now vector is staritng " << endl;
	for(int i = 0; i < s2.size(); i++){
		s1 = s2[i];
		for(int j = 0; j < s1.size(); j++) {
			cout << s1[j] << "  ";
		}
		cout << endl;
	}

		
	return 0;
}
			
	
