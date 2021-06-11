#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
	int val = 0;
	int src;
	int nbr;
	Edge(int src,int nbr,int val){
		this->val = val;
		this->src = src;
		this->nbr = nbr;
	}
};
class Pair
{
public: 
	int wt;
	int v1;
	int v;
	Pair(){
		v = -2;		
		v1 = -1;
		wt = 0;
	} 
};
bool operator<(const Pair&p1,const Pair&p2){
	return p1.wt > p2.wt;
}
vector<vector<Edge*>> constructGraph(vector<vector<int>> v,int vces){
	vector<vector<Edge*>> graph(vces);
	for (int i = 0; i < v.size(); ++i)
	{
			int vrtx1 = v[i][0];
			int vrtx2 = v[i][1];
			int wt = v[i][2];
			graph[vrtx1].push_back(new Edge(vrtx1,vrtx2,wt));
			graph[vrtx2].push_back(new Edge(vrtx2,vrtx1,wt));
	}
	return graph;
}
void prims(vector<vector<Edge*>> &graph,int src,vector<bool> &visited){
  priority_queue<Pair> pq;
  Pair p;
  p.v = src;
  p.v1 = -1;
  p.wt = 0;
  pq.push(p);
  bool flag = false;
  while(pq.size() > 0){
    Pair p2;
  	p2 = pq.top();
  	pq.pop();
  	if(visited[p2.v]){
  		continue;
  	}
  	else{
  		visited[p2.v] = true;
  		if(flag){
  		cout<<p2.v<<"-"<<p2.v1<<"@"<<p2.wt<<endl;
  		}
  	}
  	flag = true;
  	for(Edge* edge: graph[p2.v]){
  		Pair p1;
  		p1.v = edge->nbr;
  		p1.v1 = p2.v;
  		p1.wt = edge->val;
  		pq.push(p1);
  	}
  }
}	
int main(){
	int vces;
	cin>>vces;
	int edges;
	cin>>edges;
	vector<vector<int>> v(edges,vector<int>(3));
	for (int i = 0; i < edges; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			cin>>v[i][j];
		}
	}
	int src;
	cin>>src;
	vector<bool> visited(vces,false);
	vector<vector<Edge*>> graph;
	graph = constructGraph(v,vces);
	prims(graph,src,visited);
	return 0;
}