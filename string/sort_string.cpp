#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

// Revise it once again, you wrote it on your own but after seeing logic so have a look.
/* input
3
92 022
82 12
77 13
2 false numeric

Expected Output
82 12
77 13
92 022

*/



int convertToInt(string s){
	int ans=0;
	int p=1;
	for(int i=0;i<s.length();i++){
		ans = ans*p + int(s[i]);
		p*=10;
	}
	return ans;
}

string extractKey(string str, int key){
	char *s = strtok((char *)str.c_str()," ");
	while(key>1){
		s = strtok(NULL, " ");
		key--;
	}

	return string(s);


}


// Sorting
bool numeric(pair<string,string> s1, pair<string,string> s2){
	string key1 = s1.second;
	string key2 = s2.second;

	return convertToInt(key2) > convertToInt(key1);

}

bool lexic(pair<string,string> s1, pair<string,string> s2){
	string key1 = s1.second;
	string key2 = s2.second;

	return key2 > key1;

}

void sort_strings(vector<string> v, int key, string reversal, string ordering){

	// Step 1 Extraction of Keys
	vector<pair<string,string> > vp;
	for(int i=0;i<v.size();i++){
		string k = extractKey(v[i], key);
		vp.push_back(make_pair(v[i],k));
	}

	// Step 2 Sorting
	if(ordering == "numeric"){
		sort(vp.begin(),vp.end(),numeric);
	}
	else{
		sort(vp.begin(),vp.end(),lexic);
	}

	// Reverse if required
	if(reversal=="true"){
		reverse(vp.begin(),vp.end());
	}

	for(pair<string,string> p: vp){
		for(char s: p.first){
			cout<<s;
		}
		cout<<endl;
	}



}

int main(){

	int n;
	cin>>n;

	cin.get(); // to consume \n
	
	string temp;
	vector<string> v;
	for(int i=0;i<n;i++){
		getline(cin,temp);
		v.push_back(temp);
	}

	int key;
	string reversal,ordering;
	cin >>key >>reversal >>ordering;

	sort_strings(v,key,reversal,ordering);



	// THis is what i did in first attempt, look & observe where you get wrong
	// int n;
	// cin>>n;
	
	// vector<char> input[1000];
	// for(int i=0;i<n;i++){
	// 	char c;
	// 	cin>>c;
	// 	input[i].push_back(c);
	// }

	// char actions[1000];
	// cin.getline(actions,1000);

	// sort_strings(input,actions,n);




	return 0;
}