#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

class item{
	public:
	int w;
	int p;
};
vector<item> v_item;
vector<bool> result;
int Cbest = 0;
int knap_w;
int n;
bool comp_i(item ob1, item ob2) 
{
	return (ob1.w*ob1.p > ob2.w*ob2.p);
}
double bestEval(int Litem)
{
	double best = 0;
	int w = knap_w;
	int temp;
	for(int i = Litem; i < n; i++) {
		if(w - v_item[i].w <= 0) {
			best += v_item[i].p;
			temp = i;
		}
	}
	if(temp + 1 < n)
	best += (w)*(v_item[temp+1].p/v_item[temp+1].w);
	return best;
}
	

bool feasible(vector<bool> v)
{
	int temp = 0;
	for(int i = 0; i < n; i++) {
		if(v[i]) {
			temp += v_item[i].w;
		}
	}
	if(temp <= knap_w){
		return true;
	}
	return false;
}

int boundAndBranch(vector<bool> pre, int Litem, int CP)
{
	if(Cbest > (CP + bestEval(Litem))) {
		return 0;
	}
	int a = 0;
	for(int i = Litem; i < n; i++) {
		pre[i] = true;
		if(feasible(pre)) {
			int temp = CP+ v_item[i].p;
			int next = boundAndBounce(pre, i+1,  temp);
			if(next + temp > Cbest) {
				Cbest = next + temp;
				result = pre;
			}
			if(a < next + v_item[i].p) {
				a  = next + v_item[i].p;
			}
		}
		pre[i] = false;
	}
	return a;
}
int main()
{
	scanf("%d%d", &knap_w, &n);
	vector<bool> pre(n);
	int a1, b;
	for(int i = 0; i < n; i++) {
		item ob1;
		scanf("%d%d", &a1, &b);
		ob1.w = a1;
		ob1.p = b;
		v_item.push_back(ob1);
		pre[i] = false;
	}
	//sort(v_item.begin(), v_item.end(), comp_i);
	int a = boundAndBranch(pre, 0, 0);
	cout << a << endl;
	return 0;
}

