#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#define pi pair<float, float>


using namespace std;


struct tree{
	int x;
	struct tree *left;
	struct tree *right;
};
typedef struct tree node;

void BST(int pos[][102], int n, int i, int j , node **head, vector<pi> prob);

void insert(node **head, int k)
{
	if(*head == NULL) {
		*head = new node;
		(*head)->x = k;
		(*head)->left = NULL;
		(*head)->right = NULL;
	}else if((*head)->x > k) {
		insert(&(*head)->left, k);
	}else if((*head)->x < k) {
		insert(&(*head)->right, k);
	}
}

void print_bst(node *head)
{
	if(head != NULL) {
		print_bst(head->left);
		cout << head->x << " ---> " ;
		print_bst(head->right);
	}
}

void calculate_cost(vector<pi> prob, int n, float s[], node **head)
{
	float c[n + 1][n + 1];
	int pos[102][102];
	float q;
	float min;
	int mink;
	for(int i = 1; i <= n; i++) {
		c[i][i] = prob[i].first;
		pos[i][i] = i;
	}
	for(int i = 1; i < n; i++) {
		if((2*prob[i].first + prob[i+1].first) < (prob[i].first + 2*prob[i+1].first)){
			c[i][i+1] = 2*prob[i].first + prob[i+1].first;
			pos[i][i+1] = i+1;
		}else {
			c[i][i+1] = prob[i].first + 2*prob[i+1].first;
			pos[i][i+1] = i;
		}
	}
	for(int i = 3; i <= n; i++) {
		for(int j = 1; j <= n - i + 1; j++) {
			int l = j;
			int m = i + j - 1;
			if(l - 1 > 0 && l + 1 < n) {
				 min = c[l][l - 1] + c[l+1][m] + s[m] - s[l - 1];
			}else if(l - 1 <= 0 && l + 1 < n){
				min = 0 + c[l+1][m] + s[m] - s[l - 1];
			}else if(l + 1 > n) {
				min = c[l][l - 1] + 0 + s[m]  - s[l - 1];
			}
			mink = l;
			for(int k = j; k <= m; k++){
				q = c[l][k - 1] + c[k+1][m] + s[m] - s[l - 1];if(k < n){
					q = c[l][k - 1] + c[k+1][m] + s[m] - s[l - 1];
				}else {
					q = c[l][k - 1] + 0 + s[m] - s[l - 1];
				}
				if(min > q){
					min = q;
					mink = k;
				}
			}
			c[l][m] = min;
			pos[l][m] = mink;
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			
				cout << pos[i][j] << "  ";
			
		}
		cout << endl;
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i; j <= n; j++) {
			
				cout << c[i][j] << "  ";
			
		}
		cout << endl;
	}
	BST(pos, n+1, 1, n, &(*head), prob);
}

void BST(int p[][102], int n, int i , int j, node **head, vector<pi> prob)
{
	if(i > j) {
		return;
	}
	int x = p[i][j];
	int y = prob[x].second;
	insert(&(*head), y);
	BST(p, n, x + 1, j, &(*head), prob);
	BST(p, n, i,  x - 1, &(*head), prob);
	
}
bool com(pi x, pi y)
{
	return (x.second < y.second);
}
	
int main()
{
		node *head;
		head = NULL;
		int n;
		cin >> n;
		vector<pi> v;
		float sum[101];
		v.push_back(make_pair(-1, -1));
		float x, y;
		for(int i = 0; i < n; i++) {
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		sort(v.begin(), v.end(), com);
		sum[0] = 0;
		for(int i = 1; i <= n; i++) {
			sum[i] = sum[i - 1] + v[i].first;
		}
		calculate_cost(v, n, sum, &head);
		print_bst(head);
		return 0;
}