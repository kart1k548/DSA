#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
	int src;
	int nbr;
	Edge(int src,int nbr){
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
			graph[vrtx1].push_back(new Edge(vrtx1,vrtx2));
	}
	return graph;
}
void topologicalSort(vector<vector<Edge*>> &graph,int src,vector<bool> &visited,stack<int> &st){
	visited[src] = true;
	for(Edge *edge: graph[src]){
		if(!visited[edge->nbr]){
			topologicalSort(graph,edge->nbr,visited,st);
		}
	}
	st.push(src);
}
int main(){
	int vces;
	cin>>vces;
	int edges;
	cin>>edges;
	vector<vector<int>> v(edges,vector<int>(2));
	for (int i = 0; i < edges; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cin>>v[i][j];
		}
	}
	vector<bool> visited(vces,false);
	vector<vector<Edge*>> graph;
	graph = constructGraph(v,vces);
	stack<int> st;
	for (int i = 0; i < vces; ++i)
	{
		if(!visited[i]){
			topologicalSort(graph,i,visited,st);
		}
	}
	while(st.size() > 0){
		cout<<st.top()<<" ";
		st.pop();
	}
	return 0;
}