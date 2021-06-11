#include<bits/stdc++.h>
using namespace std;
void showdescpq(priority_queue<int> descpq){
	while(descpq.size() > 0){
		cout<<descpq.top()<<" ";
		descpq.pop();
	}
}
void showascpq(priority_queue<int,vector<int>,greater<int>> ascpq){
	while(ascpq.size() > 0){
	cout<<ascpq.top()<<" ";
	ascpq.pop();
	}
}
int main(){
	int n;
	cin>>n;
	int k;
	vector<int> v(n);
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	cin>>k;
	int i = 0;
	priority_queue<int,vector<int>,greater<int>> ascpq; // default
	for(int x: v){
		if(i <= k){
		ascpq.push(x);
		i++;
		}
		else if(x > ascpq.top()){
		cout<<ascpq.top()<<" ";
		ascpq.push(x);
		ascpq.pop();
		}
	}
	while(ascpq.size() > 0){
		cout<<ascpq.top()<<" ";
		ascpq.pop();
	}
	return 0;
}