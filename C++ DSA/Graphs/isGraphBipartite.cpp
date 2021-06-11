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
	int level;
	string psf;
	int v;
	Pair(){
		v = -2;		
		psf = "";
		level = 0;
	} 
};
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
bool isGraphBipartite(vector<vector<Edge*>> &graph,int src,vector<int> &visited){
   queue<Pair> q;
   Pair p;
   p.v = src;
   p.psf = to_string(src);
   p.level = 0;
   q.push(p);
	while(q.size() > 0){
	Pair p1 = q.front();
	q.pop();
	if(visited[p1.v] != -1){
		if(visited[p1.v] != p1.level) return false;
	}
	else{
		visited[p1.v] = p1.level;
	}
	for(Edge *edge: graph[p1.v]){
		if(visited[edge->nbr] == -1){
			Pair p2;
			p2.v = edge->nbr;
			p2.psf = p1.psf + to_string(edge->nbr);
			p2.level = p1.level + 1;
			q.push(p2);
			}
		}
    }
    return true;
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
	vector<int> visited(vces,-1);
	vector<vector<Edge*>> graph;
	graph = constructGraph(v,vces);
	bool flag = true;
	for (int i = 0; i < vces; ++i)
	{
		if(visited[i] == -1){
			bool f = isGraphBipartite(graph,i,visited);
			if(!f){
				flag = false;
				cout<<"false"<<endl;
				break;
			}
		}
	}
	if(flag) cout<<"true"<<endl;
	return 0;
}