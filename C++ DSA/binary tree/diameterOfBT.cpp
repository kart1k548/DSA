#include<bits/stdc++.h>
using namespace std;
class TreeNode{
public:
	int val = 0;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int val, TreeNode *left, TreeNode* right){
		this->val = val;
		this->left = left;
		this->right = right;
	}
};
void displayBT(TreeNode* node){
	if(node == NULL){
		return;
	}
	string str;
	str += node->left != NULL? to_string(node->left->val):" . ";
	str += " <- " + to_string(node->val) + " -> ";
	str += node->right != NULL? to_string(node->right->val):" . ";
	cout<<str<<endl;
	displayBT(node->left);
	displayBT(node->right);
}
int height(TreeNode* node){
	if(!node) return -1;
	int lh = height(node->left);
	int rh = height(node->right);
	int x = max(lh,rh) + 1;
	return x;
}
int diameterOfBT(TreeNode* node){
	if(node == NULL){
		return 0;
	}
	int ld = diameterOfBT(node->left);
	int rd = diameterOfBT(node->right);
	int f = height(node->left) + height(node->right) + 2;
	int dia = max(f,max(ld,rd));
	return dia;
}
pair<int,int> diameterOfBT2(TreeNode* node){
	if(node == NULL){				//first = height, second = diameter;
		pair<int,int> p1;
		p1.first = -1;
		p1.second = 0;
		return p1;
	}
	pair<int,int> lp;
	pair<int,int> rp;
	lp = diameterOfBT2(node->left);
	rp = diameterOfBT2(node->right);
	pair<int,int> mp;
	mp.first = max(lp.first,rp.first) + 1; 
	int f = lp.first + rp.first + 2;
	mp.second = max(f,max(lp.second,rp.second));
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
	pair<int,int> p;
	p = diameterOfBT2(root);
	cout<<p.first<<" "<<p.second<<endl;
	return 0;
}