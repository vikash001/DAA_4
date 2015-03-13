#include<iostream>
#include<string>
using namespace std;
int v[100][100] = {0};
int min_side(int a,int b,int c) 
{
	//cout << a << " " << b << " " << c << endl;
	if(a <= b && a <= c) {
		//cout << " return " << a << endl;
		return 1;
	}else if(b <= a && b <= c) {
		//cout << " return " << b << endl;
		return 2;
	}else if(c <= a && c <= b) {
		//cout << " return " << c << endl;
		return 3;
	}
}
void Hack_print(string s1,string s2)
{
	int k1 = 0;
	int i = s1.length();
	int j = s2.length();
	int k = i - 1;
 	while( i != 0 && j != 0) {
 		k1 = 0;
		k1 = min_side(v[i-1][j-1],v[i-1][j],v[i][j-1]);
		//cout << "k1 = " << k1 << endl;
		//cout << " i , j " << i <<" , " <<  j << endl;// << v[i][j] << endl;
		if(k1 == 1) {
          if(v[i - 1][j - 1] == v[i][j]) {
				cout << s1[k] << " ";
				i = i - 1;
				j = j - 1;
				k--;
			}else {
			    cout  << " _ ";
				k--;
				i = i - 1;
				j = j - 1;
			}
		}else if(k1 == 2) {
			if(v[i - 1][j] == v[i][j]){
				cout << s1[k] << " ";
				i = i - 1;
				k--;
			}else {
			  cout  << " _ ";
			//    k--
				i = i - 1;
			}
		}else if(k1 == 3) {
			if(v[i][j - 1] == v[i][j]){
				cout << s1[k] << " ";
				j = j - 1;
				k--;
			}else {
		        cout  << " _ ";
				k--;
				j = j - 1;
			}
	    }
 	
 	}
	
}
void print(int m,int n,string s1,string s2)
{
	cout << "  _ v i k a s h\n";
	for(int i = 0; i <= n; i++) {
		if(i == 0){
				cout << "_"<< " ";
			}else{
				cout << s2[i - 1] << " "; 
			}
		for(int j = 0; j <= m; j++) {
				cout << v[j][i] << " ";
			
		}cout << endl;
	}
}

int count(string s1, string s2)
{
        int m = s1.length();
        int n = s2.length();
        for (int i = 0; i <= m; i++) {
                v[i][0] = i;
        }
        for (int j = 0; j <= n; j++) {
                v[0][j] = j;
        }
		int d = 0; 
        for (int i = 1; i <= m; i++) {
                for (int j = 1; j <= n; j++) {
                	  	
                        	if (s1[i - 1] == s2[j - 1]){
								//v[i][j] = v[i-1][j-1];
								d = 0;
                        	}else{
                      			d = 2;
							}
                       		v[i][j] = min(min(v[i][j-1] + 1,v[i-1][j] + 1),v[i-1][j-1] + d);
                        	
                        
                }
        }
        
 		print(m,n,s1,s2);
 		Hack_print(s1,s2);
        return v[m][n];
}
int main()
{
	cout << count("vikash", "atul");
	return 0;
}