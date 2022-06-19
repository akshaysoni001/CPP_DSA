#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int findPeak(vector<int> a){
	int n = a.size();
	int max_peak_len=0;
	int begin = 1;
	while(begin<n-1){

		if(a[begin-1] < a[begin] and a[begin] > a[begin+1]){
			int peak = a[begin];
			int back_word = begin;
			int len=0;
			while(a[back_word-1] < a[back_word] and back_word>=1){
				len++;
				back_word--;
			}
			while(a[begin] > a[begin+1] and begin<n-1){
				len++;
				begin++;
			}
			max_peak_len = max(max_peak_len,len+1);
		}
		else{
		begin++;
	}

	}
	return max_peak_len;


}



int main(){
	vector<int> v = {0,1,2,3,4,5,4,3,2,1,0};

	int output = findPeak(v);
	cout<<output<<endl;


	return 0;
}