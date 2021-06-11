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
TreeNode *constructBT(vector<int> v){
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
	return root;
}
TreeNode* constructBST(vector<int> v,int lo,int hi){
	if(lo > hi) return NULL;
	int mid = (lo + hi)/2;
	TreeNode* lc = constructBST(v,lo,mid-1);
	TreeNode* rc = constructBST(v,mid+1,hi);
	TreeNode *node = new TreeNode(v[mid],lc,rc);
	return node;
}
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
int size = 0;
int sum = 0;
int maxi = INT_MIN;
int mini = INT_MAX;
int multiSolver(TreeNode* node){
	if(!node) return -1;
	int lch = multiSolver(node->left);
	int rch = multiSolver(node->right);
	sum += node->val;
	size += 1;
	maxi = max(maxi,node->val);
	mini = min(mini,node->val);
	int ch = max(lch,rch) + 1;
	return ch;
}
bool findinBST(TreeNode* node,int key){
	if(!node) return false;
	if(key == node->val){
		return true;
	}
	else if(key < node->val){
		bool lfind = findinBST(node->left,key);
		if(lfind) return true;
	}
	else{
		bool rfind = findinBST(node->right,key);
		if(rfind) return true;
	}
	return false;
}
int main(){
	int n;
	cin>>n;
	int key;
	vector<int> v(n);
	for (int i = 0; i < n; ++i) cin>>v[i];
	cin>>key;
	TreeNode* root = constructBT(v);
	cout<<"Height: "<<multiSolver(root)<<endl;
	cout<<"Size: "<<size<<endl;
	cout<<"Sum: "<<sum<<endl;
	cout<<"Maximum: "<<maxi<<endl;
	cout<<"Minimum: "<<mini<<endl;
	cout<<findinBST(root,key)<<endl;
	return 0;
}