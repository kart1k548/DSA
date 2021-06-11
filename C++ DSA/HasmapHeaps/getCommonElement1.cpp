#include<bits/stdc++.h>
using namespace std;
int main(){
	int n1,n2;
	cin>>n1;
	vector<int> v1(n1);
	for (int i = 0; i < n1; ++i)
	{
		cin>>v1[i];
	}
	cin>>n2;
	vector<int> v2(n2);
	for (int i = 0; i < n2; ++i)
	{
		cin>>v2[i];
	}
	unordered_map<int,int> umap;
	unordered_map<int,int>:: iterator it;
	for (int i = 0; i < n2; ++i)
	{
		umap[v2[i]] = i;
	}
	for(int i = 0; i < n1; i++){
		it = umap.find(v1[i]);
		if(it == umap.end()){
			continue;
		}
		else{
			cout<<it->first<<endl;
			umap.erase(it->first);
		}
	}
	return 0;
}