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
void hamiltonianPaths(vector<vector<Edge*>> graph,int src,unordered_map<int,int> visited, string psf,int osrc){
	if(visited.size() == graph.size() - 1){
		bool foundCycle = false;
		for(Edge *edge : graph[src]){
			if(edge->nbr == osrc){
				foundCycle = true;
			}
		}
		if(foundCycle){
			cout<<psf<<"*"<<endl;
		}
		else{
			cout<<psf<<endl;
		}
		return;
	}
    visited[src] = -1;
	for(Edge* edge: graph[src]){
		if(visited.find(edge->nbr) == visited.end()){
			hamiltonianPaths(graph,edge->nbr,visited,psf + to_string(edge->nbr),osrc);		
		}
	}
	visited.erase(src);
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
	vector<vector<Edge*>> graph;
	graph = constructGraph(v,vces);
	unordered_map<int,int> visited;
	hamiltonianPaths(graph,src,visited,to_string(src),src);
	return 0;
}