#include<iostream>
#include<vector>
using namespace std;

int rain_water(vector<int> bar){
	int n = bar.size();
	vector<int> left_max;
	vector<int> right_max(n,0);

	int l_max=-1, r_max=-1, water=0;
	// Finding Left Max
	for(int i=0;i<n;i++){
		if(bar[i] > l_max ){
			l_max = bar[i];
		}
		left_max.push_back(l_max);
	}
	// Finding Right Max
	for(int i=n-1;i>=0;i--){
		if(bar[i] > r_max){
			r_max = bar[i];
		}
		right_max[i] = r_max;
	}
	cout<<"Left Max Array: ";
	for(int x: left_max){
		cout<<x<<",";
	}
	cout<<endl;
	cout<<"Right Max Array: ";
	for(int x: right_max){
		cout<<x<<",";
	}
	cout<<endl;
	
	// Calculating Rain water acumulation
	for(int i=0;i<n;i++){
		water += min(left_max[i],right_max[i]) - bar[i];
	}

	return water;

}


int main(){
	vector<int> bars = {0,1,0,2,1,0,1,3,2,1,2,1};

	cout<<"Rain Water Accumulates: ";
	cout<<rain_water(bars)<<endl;



	return 0;
}