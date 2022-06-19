#include<iostream>
#include<vector>
using namespace std;

// Brute Force
vector<int> ArrayProduct(vector<int> v){
	int n = v.size();
	vector<int> result(n,1);

	int all_prod=1;
	for(int x: v){
		all_prod*=x;
	}
	for(int i=0;i<n;i++){
		result[i] = all_prod/v[i];
	}
	return result;
}

// WithOut Division
vector<int> OptArrayProduct(vector<int> v){
	int n = v.size();
	vector<int> prod(n,1);
	// Logic: Find prod of left side & prod of right side and multiply
	int temp =1 ;

	// Left side Product
	for(int i=0;i<n;i++){
		prod[i] = temp;
		temp *= v[i];
	}

	temp = 1;
	// Right side Prod & Multiply with left side
	for(int i=n-1;i>=0;i--){
		prod[i] *= temp;
		temp *= v[i]; 
	}
	
	return prod;
}

int main(){
	vector<int> arr = {1,2,3,4,5};
	vector<int> output = ArrayProduct(arr);
	for(int x: output){
		cout<<x<<",";
	}
	cout<<endl;
	vector<int> output_2 = OptArrayProduct(arr);
	for(int x: output_2){
		cout<<x<<",";
	}
	return 0;
}