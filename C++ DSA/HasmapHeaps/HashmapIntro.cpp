#include<bits/stdc++.h>
using namespace std;
int main(){
	unordered_map<string,int> umap;
	umap["US"] = 20;
	umap["India"] = 120;
	umap["China"] = 300;
	umap["Pak"] = 40;
	umap.insert(make_pair("Aus",10));
	umap.insert(make_pair("Fra",15));
	umap.insert(make_pair("Can",12));
	umap.insert(make_pair("Aus",25)); // this doesnt work!!
	for(auto x: umap){
		cout<<x.first<<" "<<x.second<<endl;
	}
	string key = "Utopia";
	if(umap.find(key) == umap.end()){ //umap.find(key) is a ptr
		cout<<"not found"<<endl;	
	}
	else{
		cout<<"found "<<key<<endl;
	}
	unordered_map<string,int>:: iterator itr;
	for(itr = umap.begin(); itr != umap.end(); itr++){
		cout<<itr->first<<" "<<itr->second<<endl;
	}
	return 0;
}