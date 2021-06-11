#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
	int val = 0;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val, TreeNode *left, TreeNode *right){
		this->val = val;
		this->left = left;
		this->right = right;
	}
};
class BTRPair{
	public:
		bool isBTR;
		int lh;
		int rh;
	BTRPair(){
		isBTR = true;
		lh = -1;
		rh = -1;
	}
};
BTRPair isbtr(TreeNode* node){
	if(node == NULL){
		BTRPair bp;
		return bp;
	}
	BTRPair lp;
	BTRPair rp;
	lp = isbtr(node->left);
	rp = isbtr(node->right);
	BTRPair mp;
	int diff = lp.lh - rp.rh;
	int d = abs(diff);
	mp.isBTR = lp.isBTR && rp.isBTR && d <= 1;
	mp.lh = lp.lh + 1;
	mp.rh = rp.rh + 1;
	return mp;
}
int main(){
	int n;
	cin>>n;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	stack<pair<TreeNode*,int>> st;
	pair<TreeNode*,int> p1;
	TreeNode *root;
	for (int i = 0; i < v.size(); ++i)
	{
		if(v[i] != -1){
			TreeNode *node = new TreeNode(v[i],NULL,NULL);
			if(i == 0){
				root = node;
				p1.first = node;
				p1.second = 1;
				st.push(p1);
			}	
			else if(st.size() > 0 && st.top().second == 1) {
				st.top().first->left = node; 
				st.top().second++;
				p1.first = node;
				p1.second = 1;
				st.push(p1);
			}
			else if(st.size() > 0 && st.top().second == 2) {
				st.top().first->right = node; 
				st.pop();
				p1.first = node;
				p1.second = 1;
				st.push(p1);
			}
			else {
				st.pop();
			}
		}
		else
		{
			if(i == 0){
				cout<<"Root cannot be -1"<<endl;
				break;
			}
			st.top().second++;
			if(st.top().second == 3){
				st.pop();
			}
		}
	}
	BTRPair	p = isbtr(root);
	cout<<p.isBTR<<endl;
	return 0;
}