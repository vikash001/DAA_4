#include<iostream>
#include<vector>
#include<string>
#include<cmath>
#include<climits>
#include<algorithm>

using namespace std;

class point{
	public:
	int x;
	int y;
};

bool com_x(point a, point b)
{
	return (a.x < b.x);
}
bool com_y(point a, point b) 
{
	return (a.y > b.y);
}
float dist(point a, point b)
{
	float di = sqrt((a.x - b.x)*(a.x - b.x) - (a.y - b.y)*(a.y - b.y));
	return di;
}

pair<point, point> close_pair(vector<point> vv, int left, int right)
{
		if(left == right) {
			point a;
			a.x = a.y = INT_MAX;
			return make_pair(vv[left], a);
		}
		if(left + 1 == right) {
			return make_pair(vv[left], vv[right]);
		}
		int mid = (left + right)/2;
		pair<point, point> pl = close_pair(vv, left, mid);
		pair<point, point> pr = close_pair(vv, mid+1, right);
		float dl = dist(pl.first, pl.second);
		float dr = dist(pr.first, pr.second);
		float dis = dl < dr ? dl : dr ;
		float dnew = dl+dr+1;
		pair<point, point> pnew;
		vector<point> v;
		int i = mid;
		while((vv[mid].x - vv[i].x) <= (dis)) {
			v.push_back(vv[i]);
			i--;
		}
		i = mid+1;
		while((vv[i].x - vv[mid].x) <= (dis)) {
			v.push_back(vv[i]);
			i++;
		}
		int count = 1;
		sort(v.begin(), v.end(), com_y);
		for(int j = 0; j < v.size() - 1; j++) {
			count = 1;
			for(int k = 0; k < v.size() && count <= 6; k++) {
				if((dist(v[j], v[k])) <= dis){
					dis = dist(v[j], v[k]);
					pnew = make_pair(v[j], v[k]);
				}
				count++;
			}
		}
		cout << dis << endl;
		return pnew;
		
}
int main()
{
	int n;
	cin >> n;
	vector<point> vv;
	point ob;
	for(int i = 0; i < n; i++) {
		cin >> ob.x >> ob.y;
		vv.push_back(ob);
	}
	sort(vv.begin(), vv.end(), com_x);
	pair<point, point> p = close_pair(vv, 0, n - 1);
	cout << (p.first).x << "  " << (p.first).y << "  " << (p.second).x << "  " << (p.second).y << endl;
	return 0;
}