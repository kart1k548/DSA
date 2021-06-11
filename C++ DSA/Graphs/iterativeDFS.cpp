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
	string psf;
	int v;
	Pair(){
		v = -2;		
		psf = "";
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
void iterativeDFS(vector<vector<Edge*>> &graph,int src,vector<bool> &visited){
   stack<Pair> st;
   Pair p;
   p.v = src;
   p.psf = to_string(src);
   st.push(p);
   while(st.size() > 0){
   	Pair p1;
   	p1 = st.top();
   	st.pop();
   	if(visited[p1.v]){
   		continue;
   	}
   	else{
   		visited[p1.v] = true;
   		cout<<p1.v<<"@"<<p1.psf<<endl;
   	}
   	for(Edge * edge: graph[p1.v]){
   		if(!visited[edge->nbr]){
   			Pair p2;
   			p2.v = edge->nbr;
   			p2.psf = p1.psf + to_string(edge->nbr);
   			st.push(p2);
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
	iterativeDFS(graph,src,visited);
	return 0;
}