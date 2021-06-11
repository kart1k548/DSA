#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin>>k;
	int n;
	vector<vector<int>> arr;
	for (int i = 0; i < k; ++i)
	{
		cin>>n;
		vector<int> v(n);
		for (int j = 0; j < n; ++j)
		{
			cin>>v[j];
		}
		arr.push_back(v);	
	}
	for (int i = 0; i < arr.size(); ++i)
	{
		for (int j = 0; j < arr[i].size(); ++j)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}