#include<bits/stdc++.h>
using namespace std;
void getIslands(vector<vector<int>> &v,int i,int j, vector<int> &comp,vector<vector<bool>> &visited){
	if(i < 0 || i >= v.size() || j < 0 || j >= v[0].size() || v[i][j] == 1 || visited[i][j] == true){
		return;
	}
	visited[i][j] = true;
	comp.push_back(v[i][j]);
	getIslands(v,i,j-1,comp,visited);
	getIslands(v,i+1,j,comp,visited);
	getIslands(v,i,j+1,comp,visited);
	getIslands(v,i-1,j,comp,visited);
}
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>> v(n,vector<int>(m,0));
	for (int i = 0; i < n; ++i)
	{
		for (int j= 0; j < m; ++j)
		{
			cin>>v[i][j];
		}
	}
	vector<vector<int>> comps;
	vector<vector<bool>> visited(n,vector<bool>(m,false));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if(v[i][j] == 0 && !visited[i][j]){
				vector<int> comp = {};
				getIslands(v,i,j,comp,visited);
				comps.push_back(comp);
			}
		}
	}
	cout<<comps.size()<<endl;
	return 0;
}