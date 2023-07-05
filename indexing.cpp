#include<bits/stdc++.h>
using namespace std;
int main(){
    int nf;
    cin>>nf;
    map<string,vector<int>>mp;
    for(int i=0;i<nf;++i){
        string fn;
        cout<<"Enter File name :- ";
        cin>>fn;
       
        cout<<"Number of  Blocs of file "<<fn<<" :- ";
        int nb;
        cin>>nb;
        for(int j=0;j<nb;++j){
            int x;
            cin>>x;
            mp[fn].push_back(x);
        }
    }
    string fn;
    cout<<"Enter file name :- ";
    cin>>fn;
    cout<<mp[fn].size()<<endl;
    
    for(auto ele:mp[fn])cout<<ele<<" ";
    cout<<endl;
}