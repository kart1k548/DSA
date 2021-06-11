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
	unordered_map<int,int> umap1;
	unordered_map<int,int>:: iterator it1;
	unordered_map<int,int> umap2;
	unordered_map<int,int>:: iterator it2;
	for (int x: v1)
	{
		it1 = umap1.find(x);
		if(it1 == umap1.end()) umap1[x] = 1;
		else it1->second++;
	}
	for (int x: v2)
	{
		it2 = umap2.find(x);
		if(it2 == umap2.end()) umap2[x] = 1;
		else it2->second++;
	}
	for(it1 = umap1.begin();it1 != umap1.end();it1++){
		it2 = umap2.find(it1->first);
		if(it2 == umap2.end()){
			continue;
		}
		else{
			int x = min(it1->second,it2->second);
			while(x > 0){
				cout<<it1->first<<endl;
				x--;
			}
			umap2.erase(it2->first);
		}
	}
	return 0;
}