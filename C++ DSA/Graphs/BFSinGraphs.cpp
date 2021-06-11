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
void BFSGraph(vector<vector<Edge*>> graph,int src,vector<bool> visited){
	queue<pair<int,string>> q;
    pair<int,string> p1;
    p1.first = src;
    p1.second = to_string(src);
	q.push(p1);
	while(q.size() > 0){
		int curr = q.front().first;
        string psf = q.front().second;
        q.pop();
        if(visited[curr] == true){
            continue;
        }
        visited[curr] = true;
        cout<<curr<<"@"<<psf<<endl;
		for(Edge *edge: graph[curr]){
			if(!visited[edge->nbr]){
                p1.first = edge->nbr;
                p1.second = psf + to_string(edge->nbr);
				q.push(p1);
			}
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
	BFSGraph(graph,src,visited);
	return 0;
}