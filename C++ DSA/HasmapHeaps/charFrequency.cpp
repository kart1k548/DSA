#include<bits/stdc++.h>
using namespace std;
int main(){
	unordered_map<char,int> umap;
	string s;
	cin>>s;
	unordered_map<char,int>:: iterator it;
	int maxi = INT_MIN;
	for(char ch : s){
		it = umap.find(ch);
		if(it == umap.end())
		{
			umap[ch] = 1;
		}
		else{
			it->second++;
			if(it->second > maxi) maxi = it->second;
		}
	}
	for(auto x : umap){
		if(x.second == maxi) cout<<x.first<<endl;
	}
	return 0;
}