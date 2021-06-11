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
	string psf;
	int v;
	Pair(){
		v = -2;		
		psf = "";
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
void djikstra(vector<vector<Edge*>> &graph,int src,vector<bool> &visited){
  priority_queue<Pair> pq;
  Pair p;
  p.v = src;
  p.psf = to_string(src);
  p.wt = 0;
  pq.push(p);
  while(pq.size() > 0){
    Pair p2;
  	p2 = pq.top();
  	pq.pop();
  	if(visited[p2.v]){
  		continue;
  	}
  	else{
  		visited[p2.v] = true;
  		cout<<p2.v<<" via "<<p2.psf<<"@"<<p2.wt<<endl;
  	}
  	for(Edge* edge: graph[p2.v]){
  		Pair p1;
  		p1.v = edge->nbr;
  		p1.psf = p2.psf + to_string(edge->nbr);
  		p1.wt = p2.wt + edge->val;
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
	djikstra(graph,src,visited);
	return 0;
}