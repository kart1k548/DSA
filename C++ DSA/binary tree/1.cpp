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
	return 0;
}