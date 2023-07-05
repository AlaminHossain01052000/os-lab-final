#include<bits/stdc++.h>
using namespace std;
int main(){
    int totalMemory;
    cout<<"Enter total Memory Available :- ";
    cin>>totalMemory;
    int i=0;
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
// 400
// y
// 275
// y
// 550