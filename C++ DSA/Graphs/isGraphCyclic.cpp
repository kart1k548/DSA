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
void isGraphCyclic(vector<vector<Edge*>> &graph,int src,vector<bool> &visited,vector<bool> &isCompCyclic){
   queue<int> q;
	q.push(src);
	while(q.size() > 0){
	int curr = q.front();
        q.pop();
        if(visited[curr] == true){
           isCompCyclic.push_back(true);
           return;
        }
        visited[curr] = true;
	for(Edge *edge: graph[curr]){
		if(!visited[edge->nbr]){
		q.push(edge->nbr);
	    }
	}
    }
    isCompCyclic.push_back(false);
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
	vector<bool> isCompCyclic = {};
	vector<bool> visited(vces,false);
	vector<vector<Edge*>> graph;
	graph = constructGraph(v,vces);
	for (int i = 0; i < vces; ++i)
	{
		if(!visited[i]){
		isGraphCyclic(graph,i,visited,isCompCyclic);
		}
	}
	for (int i = 0; i < isCompCyclic.size(); ++i)
	{
		cout<<isCompCyclic[i]<<" ";
	}
	cout<<endl;
	return 0;
}