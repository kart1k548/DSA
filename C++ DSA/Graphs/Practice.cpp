#include <bits/stdc++.h>
using namespace std;
vector<string> getSubs(string str){
	if(str.size() == 0){
		vector<string> bres;
		bres.push_back("");
		return bres;
	}
	char ch = str[0];
	string ros = str.substr(1);
	vector<string> rres = getSubs(ros); 
	vector<string> mres;
	for(string s: rres){
		mres.push_back(ch + s);
		mres.push_back("" + s);
	}
	return mres;
}
int main(){
	string str;
	cin>>str;
	unordered_map<char,int> umap;
	vector<string> gss;
	gss = getSubs(str);
	for(string s: gss){
		for (int i = 0; i < s.size(); ++i)
		{
			umap[s[i]] = 0;
		}
	}
	return 0;
}