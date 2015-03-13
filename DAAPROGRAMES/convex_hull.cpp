#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#define pi pair<int, int>

using namespace std;

class convex{
	public:
	list<pi> points;
	pi r;
	void getPoints(int n) {
		int x,y;
		for(int i = 0; i < n; i++) {
			cin >> x >> y;
			points.push_back(pi(x, y));
		}
	}
	
	bool comp1(pi x, pi y){
		return (x.first < y.first);
	}
	bool comp2(pi x, pi y) {
		return (x.second < y.second);
	}
	int crossProduct(pi x1, pi x2, pi x3){
		int y1 = x3.first - x1.first;
		int y2 = x3.second - x3.second;
		int y3 = x2.first - x1.first;
		int y4 = x2.second - x2.second;
		int l = y1*y4 - y2*y3;
		return l;
	}
	void arrange(vector<pi> &v, bool comp){
		sort();
	}
	void cHull(){
		vector<pi> vx;
		vector<pi> vy;
		vx.copy(points.begin(), points.end());
		vy.copy(points.begin(), points.end());
		vy.arrange(vy, comp2);
		r = vy[0];
		
	}
	pi nextToTop(vector<pi> s){
		return s[s.size() - 2];
	}
	pi top(vector<pi> s){
		return s[s.size() - 1];
	}
	bool slope(pi x, pi y) {
		int m1 = (r.second - x.second)/(r.first - y.second);
		int m2 = (r.second - y.second)/(r.first - y.first);
		return (m1 < m2);
	}