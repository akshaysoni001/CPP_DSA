#include<iostream>
#include<vector>
#include <algorithm>
#include<climits>
using namespace std;

int maxSubArraySum(vector<int> arr){
	int n = arr.size();
	vector<int> arr_sum(n,0);
	int sumTillNow = 0;
	for(int i=0;i<n;i++){
		sumTillNow += arr[i];
		if(sumTillNow < 0){
			arr_sum[i]=arr[i];
			sumTillNow=0;
		}
		else
		{
			arr_sum[i]=sumTillNow;
		}

	}
	int x = *max_element(arr_sum.begin(),arr_sum.end()); 
	return x;

}


int maxSubArraySum_2(vector<int> arr){

	int n=arr.size();
	for(int i=1;i<n;i++){
		if (arr[i-1] > 0){
			arr[i]+=arr[i-1];
		}
	}
	return *max_element(arr.begin(),arr.end());
}

int maxSubArraySum_3(vector<int> arr){

	int n=arr.size();
	int cs=0,ms=INT_MIN;
	for(int i=0;i<n;i++){
		cs += arr[i];
		ms = max(cs,ms);
		cout<<ms<<",";
		if(cs<0){ cs = 0; }
	}
	return ms;
}

int main(){
	vector<int> arr = {-1,-2,-3,-4,-2,-6,-8,-3};
	cout<< maxSubArraySum(arr);
	cout<< maxSubArraySum_2(arr);
	cout<<endl;
	cout<< maxSubArraySum_3(arr);
	cout<<endl;
	return 0;
}