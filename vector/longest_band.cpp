#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

int longest_band(vector<int> v){
	int largest = 0;
	int n = v.size();
	unordered_set<int> s;
	for(int x: v){
		s.insert(x);
	}	

	for(int i=0;i<n;i++){
		int num=v[i];
		int len =1;
		if(s.find(num-1)==s.end()){
			while(s.find(num+1)!=s.end()){
				num++;
				len++;
				// s.erase(num+1);
			}
			largest= max(largest,len);
		}
	}
	return largest;

}

int main(){
	vector<int> arr {1,9,3,0,18,5,2,4,10,7,12,6};
	cout<<longest_band(arr);

	return 0;
}