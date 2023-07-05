#include<bits/stdc++.h>
using namespace std;
int main(){
    cout<<"Enter Length of the string :- ";
    int n;
    cin>>n;
    cout<<"Enter Reference String as space separted integers :- ";
    vector<int>v(n);
    for(int i=0;i<n;++i)cin>>v[i];
    cout<<"Enter Number of Frames :- ";
    int frames;
    cin>>frames;
    int hit=0;
    int miss=0;
    vector<int>frameAge(frames,0);
    vector<int>frameValue(frames,-1);
    
    for(int i=0;i<n;++i){
        cout<<v[i]<<endl;
        bool isHitted=false;
        for(int j=0;j<frames;++j){
            if(v[i]==frameValue[j]){
                hit++;
                isHitted=true;
                break;
            }
        }
        if(isHitted){
            for(int j=0;j<frames;++j){
                if(frameValue[j]!=-1)frameAge[j]++;
            }
            for(int j=0;j<frames;++j){
                cout<<"Frame "<<j+1<<" :- "<<frameValue[j]<<endl;
            }
            cout<<"HIT !!!"<<endl;
            continue;
        }
        bool isAllocated=false;
        int allocatedIndex;
        for(int j=0;j<frames;++j){
            if(frameValue[j]==-1){
                frameValue[j]=v[i];
                frameAge[j]=1;
                isAllocated=true;
                allocatedIndex=j;
                break;

            }
        }
        if(!isAllocated){
           
           int oldestFrameIndex=-1;
           int oldestFrameAge=0;
           for(int j=0;j<frames;++j){
                if(frameAge[j]>oldestFrameAge){
                    oldestFrameAge=frameAge[j];
                    oldestFrameIndex=j;
                }
           }
            frameValue[oldestFrameIndex]=v[i];
            frameAge[oldestFrameIndex]=1;
            allocatedIndex=oldestFrameIndex;

        }
        for(int j=0;j<frames;++j){
            if(j!=allocatedIndex&&frameValue[j]!=-1)frameAge[j]++;
        }
        miss++;
        for(int j=0;j<frames;++j){
            cout<<"Frame "<<j+1<<" :- "<<frameValue[j]<<endl;
        }
        cout<<"MISS!!!"<<endl;
        
    }
    cout<<"Total Hit "<<hit<<endl;
    cout<<"Total Miss "<<miss<<endl;
}
// 12
// 2 3 2 1 5 2 4 5 3 2 5 2
// 3