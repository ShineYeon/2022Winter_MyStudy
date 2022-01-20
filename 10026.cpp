//
//  10026.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/20.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;
int N;
char inputs[101][101];
bool visited[101][101];

int moveX[4]={0, 0, 1, -1};
int moveY[4] ={1, -1, 0, 0};

int newX, newY;
char prevChar;

void bfs(int x, int y) {
    
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        newX = x+moveX[i];
        newY = y+moveY[i];
            
        if((newX<0)||(newY<0)||(newX>=N)||(newY>=N))
            continue;
        
        if(!visited[newX][newY] && inputs[x][y]==inputs[newX][newY])
            bfs(newX, newY);
        
           
    }
}

int main(){
    cin>>N;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            scanf(" %c", &inputs[i][j]);
    }
    
    int cnt = 0;
    //평범한 사람
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]){
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    //적록색약인 사람
    //초기화
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(inputs[i][j] == 'G')
                inputs[i][j] = 'R';
            visited[i][j] = false;
        }
    }
    int forCnt = 0;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]){
                bfs(i, j);
                forCnt++;
            }
        }
    }
    
    cout<<cnt<<" "<<forCnt<<endl;
}
