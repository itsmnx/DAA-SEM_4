#include<bits/stdc++.h>
using namespace std;

void floydwarshall(vector<vector<int>>&dist){
    for(int k=0;k<dist.size();k++){
        for(int i=0;i<dist.size();i++){
            for(int j=0;j<dist.size();j++){
                if(dist[i][j]>dist[i][k]+ dist[k][j]){
                    dist[i][j]=dist[i][k]+ dist[k][j];
                }
            }
        }
    }

}


int main(){
    int INF=1e9;
    vector<vector<int>> matrix = {
        {0, 3, INF, 7},
        {8, 0, 2, INF},
        {5, INF, 0, 1},
        {2, INF, INF, 0}
    };
    
    floydwarshall(matrix);   
    for(int i = 0; i<matrix.size(); i++) {
        for(int j = 0; j<matrix.size(); j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

