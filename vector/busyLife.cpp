#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;


bool compare(pair<int,int> v1, pair<int,int> v2){
    return v1.second < v2.second;
}  

int busyLife(vector<pair<int,int>> p){
	sort(p.begin(),p.end(),compare);
	for(auto x: p){
		cout<<"{"<<x.first<<","<<x.second<<"}, ";
	}
	int max_act = 0;
	int n = p.size();
	for(int i=0;i<n;i++){
		int cnt=1;
		int end = p[i].second;
		for(int j=i+1;j<n;j++){
			if(p[j].first >= end){
				cout<<p[j].first<<"-";
				cnt++;
				end=p[j].second;
			}
		}
		cout<<endl;
		if(cnt>max_act) { max_act = cnt; }
	}

	return max_act;
}
// Coding Minutes SOlutions
int countActivites(vector<pair<int,int> > v){
    //Complete this method
    
	sort(v.begin(),v.end(),compare);
	for(auto x: v){
		cout<<"{"<<x.first<<","<<x.second<<"}, ";
	}
    int count = 1;
    int finish = v[0].second;
    
    for(int i=1;i<v.size();i++){
        if(v[i].first>=finish){
            count++;
            finish = v[i].second;
        }
    }
    return count;
    
    
    
}

int main(){

	vector<pair<int,int>> a = {{7,9},{0,10},{4,5},{8,9},{4,10},{5,7}};

	int output = busyLife(a);
	cout<<output;

	int o = countActivites(a);
	cout<<o;


	return 0;
}