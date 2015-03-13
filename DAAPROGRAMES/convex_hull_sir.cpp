#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

class point{
	public:
	int x;
	int y;
};
class node{
	public:
	point p;
	node(){}
	node(point x){
		p = x;
	}
	node *next;
	node *prev;
};

void merge(node *lhull, node *rhull);

bool com_x(point a, point b)
{
	if(a.x == b.x) {
		return (a.y < b.y);
	}
	return (a.x < b.x);
}	
bool com_y(point a, point b)
{
	return (a.y < b.y);
}

//typedef  Points node;
int check_online(point a, point b, point c)
{
	int e = (b.x - a.x)*(c.y - b.y) - (b.y - a.y)*(c.x - b.x);
	if(e == 0) {
		return 0; //on the line
	}else if (e > 0){
		return 1; //anticlock wise
	}else {
		return -1; //clock wise
	}
}
void print(node *temp)
{
	node *head = temp;
	cout << (head->p).x << "  " << (head->p).y << "  ";
	head = head->next;
	while(head != temp){
		cout << (head->p).x << "  " << (head->p).y << "  ";
		head = head->next;
	}
	cout << endl;
}

node *make_insert(node *head, point p)
{
		if(head == NULL) {
			head = new node(p);
			
			head->next = head->prev = head;
			//cout << (head->p).x << "  " << (head->p).y << endl;
			return head;
		}else {
			node *temp = new node(p);
			
			temp->next = head->next;
			head->next->prev = temp;
			head->next = temp;
			temp->prev = head;
			return temp;
		}
		
}	

node *hull(vector<point> vv, int left, int right, node **rmhull, node **lmhull)
{
	if(left > right) {
		cout << "Error" << endl;
		return NULL;
	}
	if(left ==right) {
		node *head = NULL;
		head = make_insert(head, vv[left]);
		*rmhull = head;
		*lmhull = head;
		return head;
	}
	if(left+1 == right){
			node *head = NULL;
			head = make_insert(head, vv[left]);
			*lmhull = head;
			head = make_insert(head, vv[right]);
			*rmhull = head;
			return head;
		
	}
	if(left+2 == right) {
		int k = check_online(vv[left], vv[left+1], vv[right]);
		if(k == 0){
				node *head = NULL;
				head = make_insert(head, vv[left]);
				*lmhull = head;
				head = make_insert(head, vv[right]);
				*rmhull = head;
				//cout << "hello 6 "<< endl;
				return head;
		}else if(k > 0){
			node *head = NULL;
			head = make_insert(head, vv[right]);
			*rmhull = head;
			head = make_insert(head, vv[left+1]);
			head = make_insert(head, vv[left]);
			//print(head);
			*lmhull = head;
			//cout << "hello 7 " << endl;
			return head;
		}else {
			node *head = NULL;
			head = make_insert(head, vv[left]);
			*lmhull = head;
			head = make_insert(head, vv[left+1]);
			head = make_insert(head, vv[right]);
			*rmhull = head;
			//print(head);
			//cout << "hello 8" << endl;
			return head;
		}
	}
	int mid = (left+right)/2;
	node *llmhull;
	node *lrmhull;
	node *rlmhull;
	node *rrmhull;
	node *lhull = hull(vv, left, mid, &lrmhull, &llmhull);
	node *rhull = hull(vv, mid+1, right, &rrmhull, &rlmhull);
	//print(llmhull);
	//print(rlmhull);
	merge(lrmhull, rlmhull);
	*lmhull = llmhull;
	*rmhull = rrmhull;
	return *lmhull;
		
}


void merge(node *lhull, node *rhull)
{
	node *lhulltop;
	node *rhulltop;
	rhulltop = rhull;
	lhulltop = lhull;
	node *temp1 = rhulltop->next;
	node *temp2 = lhulltop->prev;
	while(check_online(lhulltop->p, rhulltop->p, temp1->p) >= 0 || check_online(rhulltop->p, lhulltop->p, temp2->p) <= 0){
		while((temp1 != rhull) && check_online(lhulltop->p, rhulltop->p, temp1->p ) >= 0){
			rhulltop = temp1;
			temp1 = rhulltop->next;
		}
		while((temp2 != lhull) && check_online(rhulltop->p, lhulltop->p, temp2->p) <= 0){
			lhulltop = temp2;
			temp2 = lhulltop->prev;
		}
		if(temp1 == rhull || temp2 == lhull){
			break;
		}
		
	}
	node *rhullbot = rhull;
	node *lhullbot = lhull;
	temp1 = rhullbot->prev;
	temp2 = lhullbot->next;
	while(check_online(lhullbot->p, rhullbot->p, temp1->p) <= 0 || check_online(rhullbot->p, lhullbot->p, temp2->p) >= 0){
		while((temp1 != rhull) && check_online(lhullbot->p, rhullbot->p, temp1->p) <= 0){
			rhullbot = temp1;
			temp1 = rhullbot->prev;
		}
		while((temp2 != lhull) && check_online(rhullbot->p, lhullbot->p, temp2->p) >= 0){
			lhullbot = temp2;
			temp2 = lhullbot->next;
		}
		if(temp1 == rhull || temp2 == lhull){
			break;
		}
	}
	lhulltop->next = rhulltop;
	rhulltop->prev = lhulltop;
	rhullbot->next = lhullbot;
	lhullbot->prev = rhullbot;
	
}
int main()
{
	vector<point> vv;
	int n;
	cout << "Enter the number of points" << endl;
	cin >> n;
	point ob;
	for(int i = 0; i < n; i++){
		cin >> ob.x >> ob.y;
		vv.push_back((ob));
	}
	cout << "I am in main " << endl;
	sort(vv.begin(), vv.end(), com_x);
	node *temp1;
	node *temp2;
	node *head = hull(vv, 0, n - 1, &temp1, &temp2);
	cout << " out of hull " << endl;
	print(head);
	return 0;	
}
