#include<bits/stdc++.h>
using namespace std;
struct value{
    string name;
    int no;
    int tat;
    int ct;
    int bt;
    int at;
};
int main(){
    int np;
    cout<<"Number of processes :- ";
    cin>>np;
    vector<value> v(np+1);
    cout<<"Burst Times\n";
    for(int i=1;i<=np;++i){
        cin>>v[i].bt;
    }
    vector<int>ps(np+1,0);
    for(int i=1;i<=np;++i){
        ps[i]=ps[i-1]+v[i].bt;

    }
    for(int i=1;i<=np;++i){
        cout<<"Process No "<<i<<endl;
        cout<<"Burst Time "<<v[i].bt<<endl;
        cout<<"Completion Time "<<ps[i]<<endl;
        cout<<"Turn Around Time "<<ps[i]<<endl;
        cout<<"Waiting Time "<<ps[i]-v[i].bt<<endl<<endl;
    }

}