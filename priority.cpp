#include<bits/stdc++.h>
using namespace std;
struct value{
    string name;
    int no;
    int tat;
    int ct;
    int bt;
    int at;
    int wt;
    int pt;
};
bool cmp(value v1,value v2){
    return v1.pt<v2.pt;
}
bool cmp2(value v1,value v2){
    return v1.no<v2.no;
}
int main(){
    int np;
    cout<<"Number of processes :- ";
    cin>>np;
    vector<value> v(np+1);
    cout<<"Burst Times\n";
    for(int i=1;i<=np;++i){
        cin>>v[i].bt;
        v[i].no=i;
    }
    cout<<"Priority\n";
    for(int i=1;i<=np;++i){
        cin>>v[i].pt;
        
    }
    sort(v.begin(),v.end(),cmp);
    vector<int>ps(np+1,0);
    // map<int,value>mp;
    for(int i=1;i<=np;++i){
        ps[i]=ps[i-1]+v[i].bt;
        v[i].ct=ps[i];
        v[i].tat=ps[i];
        v[i].wt=ps[i]-v[i].bt;
    }
    sort(v.begin(),v.end(),cmp2);
    for(int i=1;i<=np;++i){
        cout<<"Process No "<<i<<endl;
        cout<<"Burst Time "<<v[i].bt<<endl;
        
        cout<<"Turn Around Time "<<v[i].tat<<endl;
        cout<<"Waiting Time "<<v[i].wt<<endl<<endl;
    }

}