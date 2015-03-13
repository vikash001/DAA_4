#include<iostream>
#include<cstdlib>
#include<algorithm>
#include<cmath>
using namespace std;

struct Point {
	int x;
	int y;

};
bool compareX(Point a,Point b) 
{
	return a.x < b.x;
}
bool compareY(Point a,Point b)
{
	return a.y < b.y;
}
double Dist(Point a, Point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double Distance(Point p[],int size) {
	
	double min = 1000000;
	for(int i = 0 ; i < size; i++) {
		for(int j = i+1; j < size, j++) {
			d = Dist(p[i],p[j]);
			if(d < min) {
				min = d;
			}
			
		}
	}
	return min;
}
double BoxClosest(Point Box[], int size,double d) 
{
	double min = d;
	sort(Box, Box + j,compareY);

	for(int i = 0 ; i < size; i++) {
		for(int j = i+1; j < size ; j++) {
			if(Box[j].y - Box[i].y < min) { 
				d = Dist(Box[i],Box[j]);
				if(d < min) {
					min = d;
				}
			}
		}
	}
	return min;
}
double min(double a ,double b) 
{
	if(a < b) {
		return a;
	}else {
		return b;
	}
}

void Closest(Point p[],int size)
{
	if(size <= 3) {
		return Distance(p,size);
	}else {
		int mid = size/2;
		double dl;
		double dr;
		Point midpoint = p[mid];

		dl = Closest(p , mid);
		dr = Closest(p + mid, size);

		int j = 0;
		double d = min(dl,dr);
		Point Box[size];

		for(int i = 0 ; i < size; i++)
 	 	{
			 if(abs(p[i].x - midpoint.x) < d) {
				Box[j] = p[i];
				j++;
			 }
		}
		return min(d, BoxClosest(Box, j ,d));
				
     }
}
int main()
{
	Point point[6];
	int n = 6;
	for(int i = 0 ; i < 6; i++) {
		cin >> point[i].x;
		cin >> point[i].y;
	}
	sort(point,point + 6, compareX);
	cout << "Smallest Closest Pair = " << Closest(point,n) << endl;
	return 0;
}

