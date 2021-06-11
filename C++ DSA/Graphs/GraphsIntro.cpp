#include<bits/stdc++.h>
using namespace std;
class Edge
{
public:
	int val = 0;
	int src;
	int dest;
	Edge(int src,int dest,int val){
		this->val = val;
		this->src = src;
		this->dest = dest;
	}
};
int main(){
	int vces = 7;
	vector<vector<Edge*>> graph(vces);
	graph[0].push_back(new Edge(0,1,10));
	graph[1].push_back(new Edge(1,2,10));
	graph[2].push_back(new Edge(2,3,10));
	graph[0].push_back(new Edge(0,3,10));
	graph[3].push_back(new Edge(3,4,10));
	graph[4].push_back(new Edge(4,5,10));
	graph[5].push_back(new Edge(5,6,10));
	graph[4].push_back(new Edge(4,6,10));
	graph[2].push_back(new Edge(2,5,10));
	for (int i = 0; i < graph.size(); ++i)
	{
		for (int j = 0; j < graph[i].size(); ++j)
		{
			cout<<graph[i][j]->src<<" "<<graph[i][j]->dest<<" "<<graph[i][j]->val<<endl;
		}
	}
	return 0;
}