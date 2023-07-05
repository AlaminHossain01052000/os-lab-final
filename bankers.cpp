#include<bits/stdc++.h>
using namespace std;
bool isSuitable(vector<int>&availabe,vector<int> &need){
    int nr=availabe.size();
    for(int i=0;i<nr;++i){
        if(availabe[i]<need[i])return false;
    }
    return true;
}
int main(){
    cout<<"Number of processes :- ";
    int np;
    cin>>np;
    cout<<"Number of Resouces :- ";
    int nr;
    cin>>nr;
    vector<vector<int>>allocatedMatrix(np,vector<int>(nr));
    vector<vector<int>>maxValueMatrix(np,vector<int>(nr));
    vector<vector<int>>needMatrix(np,vector<int>(nr));
    cout<<"Allocated Matrix\n";
    for(int i=0;i<np;++i){
        for(int j=0;j<nr;++j){
            cin>>allocatedMatrix[i][j];
        }
    }
    cout<<"max Matrix\n";
    for(int i=0;i<np;++i){
        for(int j=0;j<nr;++j){
            cin>>maxValueMatrix[i][j];
        }
    }
    cout<<"Availabe Array :- ";
    vector<int>available(nr);
    for(int i=0;i<nr;++i)cin>>available[i];
    for(int i=0;i<np;++i){
        for(int j=0;j<nr;++j){
            needMatrix[i][j]=maxValueMatrix[i][j]-allocatedMatrix[i][j];
        }
    }
    int i=0;
    int iterC=nr*np;
    vector<bool> finishedProcess(np,false);
    int processFinishC=0;
    vector<int>sequence;
    while(iterC--){
        int j=i;
        for(;j<np;++j){

            if(!finishedProcess[j]&&isSuitable(available,needMatrix[j])){
                finishedProcess[j]=true;
                processFinishC++;
                for(int k=0;k<nr;++k){
                    available[k]+=allocatedMatrix[j][k];
                }
                sequence.push_back(j);

            }

        }
        i=j%np;
        if(processFinishC==np)break;

    }
    for(auto ele:sequence)cout<<ele<<" ";

}
// 5
// 4
// 0 1 1 0
// 1 2 3 1
// 1 3 6 5
// 0 6 3 2
// 0 0 1 4
// 0 2 1 0
// 1 6 5 2
// 2 3 6 6
// 0 6 5 2
// 0 6 5 6
// 1 5 2 0