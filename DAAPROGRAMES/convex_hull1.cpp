#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class point {
	public :
		int x;
		int y;
};

bool compare (point a, point b)
{
	return a.x < b.x;
}

vector<point> convex_hull(point arr[], int xmin, int xmax, int n)
{
	int xmid=(xmin+xmax)/2;
	vector<point>v1,v2,v3;

	if (n == 1) {
		vector<point> v;
		point p;
		
		p.x = arr[xmin].x;
		p.y = arr[xmin].y;
		v.push_back(p);
		
		return v;
	}

	if (n == 2) {
		vector<point> v;
		point p;
		point p1;
		
		p.x = arr[xmin].x;
		p.y = arr[xmin].y;
		v.push_back(p);

		p1.x = arr[xmax].x;
		p1.y = arr[xmax].y;
		v.push_back(p1);
		
		return v;
	}

	if (n == 3) {
		vector<point> v;
		point p;
		point p1;
		point p2;
		
		p.x = arr[xmin].x;
		p.y = arr[xmin].y;
		v.push_back(p);
		
		p1.x = arr[xmin + 1].x;
		p1.y = arr[xmin + 1].y;
		v.push_back(p1);
		
		p2.x = arr[xmin + 2].x;
		p2.y = arr[xmin + 2].y;
		v.push_back(p2);
		
		return v;
	}
	int ymin=v[0].y,ymax=v[0].y;
	if(xmin==xmax){
		for(int i=1;i<n;i++){
			if(v[i].y>ymax){
				ymax=v[i].y;
			}
			if(v[i].y<y.min){
				ymin=v[i].y;
			}
		}

	}



	else{
		v1=convex_hull(arr,xmin,xmid,xmid-xmin+1);
            	v2=convex_hull(arr,xmid,xmax,xmax-xmid+1);
		v3=merge(v1,v2);
		return v3;
	}
}
vector<point> merge(vector<point>
int main()
{
	point arr[500];
	vector<point> v;
	int n;

	cout << "Enter no. of points : ";
	cin >> n;

	cout << "Enter " << n << " points" << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].x >> arr[i].y;
	}

	
	sort(arr, arr + n, compare);
	
	v = convex_hull(arr, 0, n - 1, n);
	
	cout << endl;
	for (int i = 0; i < v.size(); i++) {
		cout << v[i].x << " " << v[i].y << endl;
	}

	return 0;
}


