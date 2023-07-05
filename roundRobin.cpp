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
};
bool cmp(value v1,value v2){
    return v1.bt<v2.bt;
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
    map<int,value>mp;
    for(int i=1;i<=np;++i){
        cin>>v[i].bt;
        v[i].no=i;
        mp[i].bt=v[i].bt;
    }
    int quantam;
    cout<<"Quantam :- ";    cin>>quantam;

    
    queue<value>q;
    for(int i=1;i<=np;++i)q.push(v[i]);
    int x=0;
    
    while(!q.empty()){
        auto process=q.front();
        q.pop();
        if(process.bt<quantam){
            x+=process.bt;
        }
        else x+=quantam;
        process.bt-=quantam;
        if(process.bt>0)q.push(process);
        else{
            mp[process.no].ct=x;

        }


    }
    for(int i=1;i<=np;++i){
        cout<<"Process No "<<i<<endl;
        cout<<"Burst Time "<<mp[i].bt<<endl;
        
        cout<<"Turn Around Time "<<mp[i].ct<<endl;
        cout<<"Waiting Time "<<mp[i].ct-mp[i].bt<<endl<<endl;
    }

}