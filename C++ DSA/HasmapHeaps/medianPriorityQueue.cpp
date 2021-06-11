#include<bits/stdc++.h>
using namespace std;
void showascpq(priority_queue<int,vector<int>,greater<int>> ascpq){
	while(ascpq.size() > 0){
	cout<<ascpq.top()<<" ";
	ascpq.pop();
	}
}
void showMid(priority_queue<int,vector<int>,greater<int>> ascpq){
	if(ascpq.size() == 0) {
		cout<<"empty"<<endl;
		return;
	}
	int l = 0;
	int h = ascpq.size() - 1;
	int mid = (l + h)/2;
	int i = 0;
	vector<int> v;
		while(i < mid){
			v.push_back(ascpq.top());
			ascpq.pop();
			i++;
		}
		cout<<ascpq.top()<<endl;
		for (int i = 0; i < v.size(); ++i)
		{
			ascpq.push(v[i]);
		}
}
void removeMid(priority_queue<int,vector<int>,greater<int>> ascpq){
	if(ascpq.size() == 0) cout<<"empty"<<endl;
	int l = 0;
	int h = ascpq.size() - 1;
	int mid = (l + h)/2;
	int i = 0;
	vector<int> v;
	while(i<mid){
		v.push_back(ascpq.top());
		ascpq.pop();
		i++;
	}
	ascpq.pop();
	for (int i = 0; i < v.size(); ++i)
	{
		ascpq.push(v[i]);
	}
	showascpq(ascpq);
}
int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	priority_queue<int,vector<int>,greater<int>> ascpq; // sorted
	for(int x : v){
		ascpq.push(x);
	}
	showMid(ascpq);
	removeMid(ascpq);
	return 0;
}