#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int x=1;

class v{
public:
	int x;
	int y;
	
};
class v1{
	public:
		int x1;
		int x2;
		int y1;
		int y2;
		
};
v1 k;
v1 s2;
//vector<v1> s3;
bool sort_x(v a,v b){
	if(a.x < b.x){
		return true;
	}
	else{
		return false;
	}
}
bool sort_y(v a,v b){
	if(a.y > b.y){
		return true;
	}
	else{
		return false;
	}
}
float dis(v a,v b){
	float f = ((a.x - b.x)*(a.x - b.x))+((a.y - b.y)*(a.y - b.y));
	return (sqrt(f));
}
float dist(v1 a){
	float f = ((a.x1 - a.x2)*(a.x1 - a.x2))+((a.y1 -a.y2)*(a.y1 - a.y2));
	return (sqrt(f));
}
v1 merge(v a[],v1 b,v1 c,int left,int right){
	v1 s;
	float d;
	vector<v>m;
	int mid=(left+right)/2;
	if(x>1){
		if(k.x1==b.x1 && k.x2==b.x2 && k.y1==b.y1 && k.y2==b.y2){

		//if(s2.x1==b.x1 && s2.x2==b.x2 && s2.y1==b.y1 && s2.y2==b.y2){
			int f2 = dist(c);
			d = f2;
			s = c;
		}
		//}
		else if(k.x1==c.x1 && k.x2==c.x2 && k.y1==c.y1 && k.y2==c.y2){
			//if(s2.x1==b.x1 && s2.x2==b.x2 && s2.y1==b.y1 && s2.y2==b.y2){
			int f1 = dist(b);
			d = f1;
			s = b;	
		}
		//}
		
		else{	
		float f1 = dist(b);
		float f2 = dist(c);
		//float d;
		if(f1<f2){
			d = f1;
			s = b;
		}
		else if(f2>f1){ 
			d = f2;
			s = c;
		}
		else if(f1==f2){
			s = b;
			s2 = c;
		}
	}
		
	}
	else{	
		float f1 = dist(b);
		float f2 = dist(c);
		//float d;
		if(f1<f2){
			d = f1;
			s = b;
		}
		else if(f2>f1){ 
			d = f2;
			s = c;
		}
		else if(f1==f2){
			s = b;
			s2 = c;
		}
	}
	/*cout<<"saA";
	cout<<"D="<<d;
	cout<<a[mid].x << "V"<<a[mid+1].x<<endl;*/
	int q = a[mid+1].x + d;
	int q1=a[mid].x-d;
	for(int i = left;i<=right;i++){
		if(a[i].x > q1 && a[i].x < q){
			m.push_back(a[i]);
		}
		else if(a[i].x == q1 ){
				m.push_back(a[i]);
		}
		else if(a[i].x == q ){
				m.push_back(a[i]);
		}
		
	}
	/*for(int i=0;i<m.size();i++){
	cout<<m[i].x<<m[i].y<<" ";
	}
	cout<<endl;*/
	sort(m.begin(),m.end(),sort_y);
	for(int i=0;i<m.size();i++){
		if(i+6 < m.size()){
			for(int j=i+1;j<6;j++){
			//	cout<<"A";
				float h = dis(m[i],m[j]);
				if(h < d){
				if(k.x1!=m[i].x && k.x2!=m[j].x && k.y1!=m[i].y && k.y2!=m[j].y){	
					if(s2.x1!=m[i].x || s2.x2!=m[j].x || s2.y1!=m[i].y || s2.y2!=m[j].y){
						
					d=h;
					s.x1=m[i].x;
					s.x2=m[j].x;
					s.y1=m[i].y;
					s.y2=m[j].y;
				}
				}}
				else if(h==d){
					s2.x1=m[i].x;
					s2.x2=m[j].x;
					s2.y1=m[i].y;
					s2.y2=m[j].y;	
				}
			}
	/*			cout<<"a1"<<endl;
						cout<<s2.x1<<","<<s2.y1<<" and ";
		cout<<s2.x2 <<","<<s2.y2<<endl;*/
		}
		else{
				for(int j=i+1;j<m.size();j++){
				//cout<<"A";
				float h = dis(m[i],m[j]);
				if(h < d){
					if(k.x1!=m[i].x || k.x2!=m[j].x || k.y1!=m[i].y || k.y2!=m[j].y){
						if(s2.x1!=m[i].x || s2.x2!=m[j].x || s2.y1!=m[i].y || s2.y2!=m[j].y){
							
							
					d=h;
					s.x1=m[i].x;
					s.x2=m[j].x;
					s.y1=m[i].y;
					s.y2=m[j].y;
				
				}
				}}
				
					else if(h==d){
					s2.x1=m[i].x;
					s2.x2=m[j].x;
					s2.y1=m[i].y;
					s2.y2=m[j].y;	
				}
				
				}
			}	
			/*	cout<<"A"<<endl;
				cout<<s2.x1<<","<<s2.y1<<" and ";
		cout<<s2.x2 <<","<<s2.y2<<endl;*/
		}
	
		return s;
}

v1 close_pair(v a[],int left,int right){
 	int n = right-left+1;
	v1 cp_left,cp_right,cp;
	if(n==2 ){
		//if(a[left].x != k.x1 || a[left].y != k.y1 || a[left+1].x != k.x2 || a[left+1].y != k.y2){
			
		v1 p;
		p.x1=a[left].x;
		p.x2=a[left+1].x;
		p.y1=a[left].y;
		p.y2=a[left+1].y;
		return (p);
	}
	if(n==3){
		float f1=(dis(a[left],a[left+1]));
		float f2=(dis(a[left+1],a[left+2]));
		float f3=(dis(a[left],a[left+2]));
		vector<float>j;
		j.push_back(f1);
		j.push_back(f2);
		j.push_back(f3);
		sort(j.begin(),j.end());
		if(a[left].x != k.x1 || a[left].y != k.y1 || a[left+1].x != k.x2 || a[left+1].y != k.y2){
			v1 p;
			p.x1=a[left].x;
			p.x2=a[left+1].x;
			p.y1=a[left].y;
			p.y2=a[left+1].y;
			return (p);
		}
		else if(a[left +1].x != k.x1 || a[left+1].y != k.y1 || a[left+2].x != k.x2 || a[left+2].y != k.y2){
			v1 p;
			p.x1=a[left+1].x;
			p.x2=a[left+2].x;
			p.y1=a[left+1].y;
			p.y2=a[left+2].y;
			return (p);
		}
		else if(a[left].x != k.x1 || a[left].y != k.y1 || a[left+2].x != k.x2 || a[left+2].y != k.y2){
			v1 p;
			p.x1=a[left].x;
			p.x2=a[left+2].x;
			p.y1=a[left].y;
			p.y2=a[left+2].y;
			return (p);
		}
		/*	//if(a[left].x != k.x1 || a[left].y != k.y1 || a[left+1].x != k.x2 || a[left+1].y != k.y2){
			if(f1<f2 && f1<f3){
			v1 p;
			p.x1=a[left].x;
			p.x2=a[left+1].x;
			p.y1=a[left].y;
			p.y2=a[left+1].y;
			return (p);
		}
		else if(f2<f1 && f2<f3){
			v1 p;
			p.x1=a[left+1].x;
			p.x2=a[left+2].x;
			p.y1=a[left+1].y;
			p.y2=a[left+2].y;
			return (p);
		}
		else if(f3<f1 && f3<f2){
			v1 p;
			p.x1=a[left].x;
			p.x2=a[left+2].x;
			p.y1=a[left].y;
			p.y2=a[left+2].y;
			return (p);
		}*/
		}
		int mid;
		mid=(left+right)/2;
		cp_left=close_pair(a,left,mid);
		cp_right=close_pair(a,mid+1,right);
		cp=merge(a,cp_left,cp_right,left,right);
		return cp;
}
int main(){
	int n;
	v a[100];
	v1 r;
	cout<<"enter the value of n -> ";
	cin>>n;
	cout<<"enter the values ->"<<endl;
	for(int i=0;i<n;i++){
		cin>>a[i].x;
		cin>>a[i].y;
	}
		sort(a,a+n,sort_x);
		/*for(int i=0;i<n;i++){
		cout<<a[i].x<<" "<<a[i].y<<endl;
		}*/
		r=close_pair(a,0,n-1);
		cout<<"points are - "<<endl;
		cout<<r.x1<<","<<r.y1<<" and ";
		cout<<r.x2 <<","<<r.y2<<endl;
		cout<<"distance is -> ";
		cout<<dist(r);
		if(dist(s2)==dist(r)){
		cout<<"points are - "<<endl;
		cout<<s2.x1<<","<<s2.y1<<" and ";
		cout<<s2.x2 <<","<<s2.y2<<endl;
		cout<<"distance is -> ";
		cout<<dist(s2);	
		}
		x++;
		k = r;
		//while(i<n) i==1 
		r=close_pair(a,0,n-1);
		cout<<"points are - "<<endl;
		cout<<r.x1<<","<<r.y1<<" and ";
		cout<<r.x2 <<","<<r.y2<<endl;
		cout<<"distance is -> ";
		cout<<dist(r);
		return 0;
		//5,4 7,9 2,3 1,6 -> 1,6 2,3 3.16228
}
