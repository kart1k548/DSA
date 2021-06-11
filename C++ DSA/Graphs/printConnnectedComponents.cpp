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
void getConnectedComponents(vector<vector<Edge*>> &graph,int Src,vector<bool> &visited,vector<int> &comp){	
    	visited[Src] = true;
        comp.push_back(Src);
		for(Edge* edge: graph[Src]){
			if(!visited[edge->nbr]){
				getConnectedComponents(graph,edge->nbr,visited,comp);
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
	vector<bool> visited(vces,false);
	vector<vector<int>> comps;
	vector<vector<Edge*>> graph;
	graph = constructGraph(v,vces);
	for (int i = 0; i < vces; ++i)
	{
		if(!visited[i]){
		vector<int> comp = {};
		getConnectedComponents(graph,i,visited,comp);
		comps.push_back(comp);
		}
	}
	for (int i = 0; i < comps.size(); ++i)
	{
		for (int j = 0; j < comps[i].size(); ++j)
		{
			cout<<comps[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}