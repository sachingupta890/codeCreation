#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;


int main(){

    //creation
    unordered_map<string,int> m;


    //insertion 

    //method 1 
    pair<string,int> p1 = make_pair("a",1);
    m.insert(p1);

    //method 2 
    pair<string,int> p2("b",2);
    m.insert(p2);

    //method 3 
    m["c"] = 3;

    //if we create entry for existing key the entry will override

    m["c"] = 4;

    //size 
    cout<<m.size()<<endl;




    //searching 

    //method 1 
    //for existing keys
    cout<<m["a"]<<endl;
    //method 2 
    cout<<m.at("b")<<endl;



    //for non existing key if we use .at() method it we give error 
    //and if we use [] method it will create new entry and initialize value with 0

    cout<<m["unknown"]<<endl;
   // cout<<m.at("unknown")<<endl;    





    return 0;
}