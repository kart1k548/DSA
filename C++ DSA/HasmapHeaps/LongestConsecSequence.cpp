#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	vector<int> v(n); 
	for (int i = 0; i < n; ++i)
	{
		cin>>v[i];
	}
	unordered_map<int,bool> umap;
	unordered_map<int,bool>:: iterator it;
	unordered_map<int,bool>:: iterator it1;

	for(int x : v) umap[x] = true;
	for(int x : v){
		it = umap.find(x - 1);
		if(it == umap.end())
		{
			umap[x] = true;
		}
		else{
			umap[x] = false;
		}
	}
	// for(auto x: umap){
	// 	cout<<x.first<<" "<<x.second<<endl;
	// }
	vector<int> maxarr = {};
	vector<int> temparr = {};
	for(it = umap.begin(); it != umap.end();it++){
		if(it->second){
			int key = it->first;
			it1 = umap.find(key);
			while(it1 != umap.end()){
			temparr.push_back(it1->first);
			key = key + 1;
			it1 = umap.find(key);
			}
			if(temparr.size() >= maxarr.size()){
			maxarr = temparr;	
			}
			temparr = {};
		}
	}
	for(auto x : maxarr){
		cout<<x<<" ";
	}
	return 0;
}