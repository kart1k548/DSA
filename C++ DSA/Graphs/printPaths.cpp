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
void printAllPaths(vector<vector<Edge*>> graph,int src,int dest,vector<bool> visited, string psf){
	if(src == dest){
		cout<<psf<<endl;
		return;
	}
    visited[src] = true;
	for(Edge* edge: graph[src]){
		if(!visited[edge->nbr]){
			printAllPaths(graph,edge->nbr,dest,visited,psf + to_string(edge->nbr));		
		}
	}
	visited[src] = false;
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
	int src,dest;
	cin>>src;
	cin>>dest;
	vector<vector<Edge*>> graph;
	graph = constructGraph(v,vces);
	printAllPaths(graph,src,dest,visited,to_string(src));
	return 0;
}