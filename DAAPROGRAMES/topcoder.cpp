#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	vector<int> l;
	l.push_back(2);
	l.push_back(5);
	l.push_back(1);
	l.push_back(10);
	l.push_back(0);
	
		int k = *max_element(l.begin(), l.end());
		cout << k << endl;
		/*int count = 0;
		int a, b;
		for(int i = 0; i <= k; i++) {
			for(int j = 0; j < l.size(); j++) {
				a = i - t[j];
				b = i - t[j] - l[j];
				if(b <= 0 && a >= 0) {
					count++;
				}
			}
		}
			return count;
		}*/	
		return 0;
}					