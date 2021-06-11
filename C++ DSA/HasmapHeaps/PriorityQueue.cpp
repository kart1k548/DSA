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
class Pair
{
public: 
	int v1;
	int v2;
	int v3;
	Pair(){
		v1 = 0;
		v2 = 0;
		v3 = 0;
	}
};
bool operator<(const Pair&p1,const Pair&p2){
	return p1.v2 < p2.v2;						// '<' implies smaller element will stay in queue
}												// and greater will come on front and get popped
int main(){
	vector<int> v = {1,2,3,4,5,6,7,8,9,10};
	priority_queue<int> descpq; // default
	priority_queue<int,vector<int>,greater<int>> ascpq; // sorted
	for(int x : v){
		descpq.push(x);
		ascpq.push(x);
	}
	showdescpq(descpq);
	cout<<endl;
	showascpq(ascpq);
	priority_queue<Pair> pq;
	Pair p;
	p.v1 = 10;
	p.v2 = 8;
	p.v3 = -1;
	pq.push(p);
	p.v1 = 11;
	p.v2 = 4;
	p.v3 = 2;
	pq.push(p);
	p.v1 = 9;
	p.v2 = 6;
	p.v3 = 0;
	pq.push(p);
	while(pq.size() > 0){
		Pair p = pq.top();
		cout<<p.v1<<" "<<p.v2<<" "<<p.v3<<endl;
		pq.pop();
	}
	return 0;
}