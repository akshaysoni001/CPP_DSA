#include <iostream>
#include <vector>
#include<climits>
using namespace std;

// Copmplexity is bit higher, need more optimization
vector<int> maxInWindow(vector<int> input, int k){
	int i=0,max=INT_MIN;
	vector<int> result;                     
	int q=k;
	for(int i=0;i<=input.size()-k;i++){
		int p = i;
		while(p < q){
			if(input[p] > max){
				max=input[p];
			}
			p++;
		}
		result.push_back(max);
		max=INT_MIN;
		q++;
	}
	
	return result;

}

int main(){
	vector<int> v = {1,3,-1,-3,5,3,6,7};
	int k = 3;
	vector<int> output = maxInWindow(v,k);
	for(int x: output){
		cout<<x<<",";
	}
	cout<<endl;


	return 0;
}