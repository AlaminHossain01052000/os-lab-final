#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+10;
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
                
                isAllocated=true;
                allocatedIndex=j;
                break;

            }
        }
        if(!isAllocated){
           
           vector<int> distance(frames,-1);
           for(int j=i-1;j>=0;--j){
            for(int k=0;k<frames;++k){
                if(frameValue[k]==v[j]&&distance[k]==-1){
                    distance[k]=j;
                }
            }
           }
           int maxDistanceIndex=-1;
           int maxDistanceValue=INF;
           for(int j=0;j<frames;++j){
            if(distance[j]<maxDistanceValue){
                maxDistanceValue=distance[j];
                maxDistanceIndex=j;
                // if(distance[j]==INF)break;
            }
           }
            frameValue[maxDistanceIndex]=v[i];
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