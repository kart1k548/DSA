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
	int tim;
	int v;
	Pair(){
		v = -2;		
		tim = 0;
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
int spreadofInfection(vector<vector<Edge*>> &graph,int src,vector<int> &visited,int t){
   queue<Pair> q;
   Pair p;
   p.v = src;
   p.tim = 1;
   q.push(p);
   int cnt = 0;
	while(q.size() > 0){
	Pair p1 = q.front();
	q.pop();
	if(visited[p1.v] == -1){
		visited[p1.v] = p1.tim;
		if(p1.tim > t){
			return cnt;
		}
		cnt++;
	}
	else{
		continue;
	}
	for(Edge *edge: graph[p1.v]){
		if(visited[edge->nbr] == -1){
			Pair p2;
			p2.v = edge->nbr;
			p2.tim = p1.tim + 1;
 			q.push(p2);
			}
		}
    }
    return cnt;
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
	int src,t;
	cin>>src>>t;
	vector<int> visited(vces,-1);
	vector<vector<Edge*>> graph;
	graph = constructGraph(v,vces);
	int cnt1 = 0;
    cnt1 = spreadofInfection(graph,src,visited,t);
	cout<<cnt1<<endl;
	return 0;
}