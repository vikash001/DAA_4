#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<vector>
#define lli long long int
using namespace std;

int main()
{
	vector<lli> st;
	//vector<lli> p;
	lli t;
	lli max;
	lli ns;
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld%lld", &ns, &max);
		lli k;
		for(lli i = 0; i < ns; i++) {
			scanf("%lld", &k);
			st.push_back(k);
		}
		k = 0;
		lli start = st[k];
		lli end = st[k];
		lli sum = 0;
		sum += end;
		lli temp = 1;
		for(lli i = 1; i < ns; i++) {
			sum += st[i];
			temp++;
			if(sum > max) {
				sum -= start;
				k++;
				temp--;
				start = st[k];
			}
			//end = st[i];
		}
		printf("%lld %lld", sum, temp);
	}
}