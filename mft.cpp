#include<bits/stdc++.h>
using namespace std;
int main(){
    int totalMemory;
    cout<<"Enter total Memory Available :- ";
    cin>>totalMemory;
    cout<<"Enter Block Size :- ";
    int bs;
    cin>>bs;
     cout<<"Enter Number of Processes :- ";
     int np;
     cin>>np;
     vector<int>v(np);
     for(int i=0;i<np;++i)cin>>v[i];
     int i=0;
     int intFrag=0;
     int nb=totalMemory/bs;
     cout<<"Number of blocks available :- "<<nb<<endl;
     cout<<"Block No\tMemory Required\tAllocated\tFragment\n";
     int exFrag=0;
     for( i=0;i<np;++i){
        if(nb==0){
            exFrag+=v[i];
            continue;
        }
        if(v[i]<=bs){
            cout<<i+1<<"\t\t"<<v[i]<<"\t\t"<<"YES\t\t"<<bs-v[i]<<endl;
            intFrag+=bs-v[i];
            nb--;
        }
        else{
            cout<<i+1<<"\t\t"<<v[i]<<"\t\t"<<"NO\t\t----"<<endl;
            
        }
     }
     cout<<"Internal Fragments :- "<<intFrag<<endl;
     cout<<"External Fragments :- "<<exFrag<<endl;
     return 0;
    // int i=0;
    int memoryUsed=0;
    vector<int> processes;
    while(1){
        cout<<"Enter Memory Required for process "<<++i<<" :- ";
        int memoryRequired;
        cin>>memoryRequired;
        if(memoryUsed+memoryRequired<=totalMemory){
            memoryUsed+=memoryRequired;
            processes.push_back(memoryRequired);

        }
        else{
            cout<<"Memory is full !!!\n";
            break;
        }
        cout<<"Memory is allocated for process "<<i<<" do you wan to continue?(y/n) :- ";
        string doesContinue;
        cin>>doesContinue;
        
        if(doesContinue=="n")break;
    }
    cout<<"Total Memory Available "<<totalMemory<<endl;
    cout<<"Process No\tAllocated\n";
    for(i=0;i<processes.size();++i){
        cout<<i+1<<"\t\t"<<processes[i]<<endl;
    }
    cout<<"Total memory Allocated :- "<<memoryUsed<<endl;
    cout<<"Total External Fragmentation :- "<<totalMemory-memoryUsed<<endl;

}
// 1000
// 300
// 5
// 275
// 400
// 290
// 293
// 100
