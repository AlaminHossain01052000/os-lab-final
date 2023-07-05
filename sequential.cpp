#include<bits/stdc++.h>
using namespace std;
int main(){
    int nf;
    cin>>nf;
    map<string,pair<int,int>>mp;
    for(int i=0;i<nf;++i){
        string fn;
        cout<<"Enter File name :- ";
        cin>>fn;
        cout<<"Start Block of file "<<fn<<" :- ";
        int sb;
        cin>>sb;
        cout<<"Number of  Blocs of file "<<fn<<" :- ";
        int nb;
        cin>>nb;
        mp[fn]={sb,nb};


    }
    string fn;
    cout<<"Enter file name :- ";
    cin>>fn;
    for(int i=mp[fn].first;i<mp[fn].first+mp[fn].second;++i)cout<<i<<" ";cout<<endl;
}