#include<map>
#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
	// creation 
	unordered_map<string,int>m;
	// INSERTION

	// 1:
	pair<string,int> p = make_pair("Kartik",4);
	m.insert(p);
	// 2:
	pair<string,int>pair2("love",2);
	m.insert(pair2);
	// 3:
	m["mera"] = 1;
	// What will happen
	m["mera"] = 2;

	// cout<<m.at("unknown")<<endl;
	cout<<m["mera"]<<endl;
	cout<<m["unknown"]<<endl; // this accesing feature make a entry for the corresoing values
	cout<<m.at("unknown")<<endl;
	cout<<m.size()<<endl;
	cout<<m.count("mera")<<endl; // if present : 1 else 0;
	cout<<m.erase("love")<<endl;
// Iterator
	//1
	unordered_map<string,int>::iterator it  = m.begin();

	while(it!=m.end()){
		cout<<it->first<<" "<<it->second<<endl;
		it++;
	}
	//2
	for(auto it:m){
		cout<<it.first<<" "<<it.second<<endl;
	}
	return 0;
}