//
//  1261.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/17.
//

#include <iostream>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

#define INF 987654321

int N, M; // N:가로, M:세로
char inputs[101][101];
int miro[101][101];
bool visited[101][101];
int cost[101][101];
int moveX[4] = {-1, 1, 0, 0};
int moveY[4] = {0, 0, 1, -1};
queue<pair<int, int>> q;

void sol(int x, int y){
    if(x==M && y==N) return;
    q.push(make_pair(x, y));
    
    while(!q.empty()){
        int nowX = q.front().first;
        int nowY = q.front().second;
        q.pop();
        //if(visited[nowX][nowY]) continue;
        //visited[nowX][nowY] = true;
        for(int i=0;i<4;i++){
            int newX = nowX+moveX[i];
            int newY = nowY+moveY[i];
            if(newX<=0 || newY<=0 || newX>M || newY>N) continue;
            if(miro[newX][newY] == 0){
                if(cost[newX][newY] > cost[nowX][nowY]){
                    cost[newX][newY] = cost[nowX][nowY];
                    q.push(make_pair(newX, newY));
                }
            }
            else if(miro[newX][newY] == 1){
                if (cost[newX][newY] > cost[nowX][nowY]+1){
                    cost[newX][newY] = cost[nowX][nowY] +1;
                    q.push(make_pair(newX, newY));
                }
            }
        }
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    scanf("%d %d", &N, &M);
    for(int i=0;i<M;i++){
        scanf("%s", inputs[i]);
        
    }
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            miro[i+1][j+1] = inputs[i][j]-'0';
        }
    }
    
    for(int i=0;i<=M;i++) {
        for(int j=0;j<=N;j++){
            visited[i][j] = false;
            cost[i][j] = INF;
        }
    }
     
    
    cost[1][1] = 0;
    sol(1, 1);
   
    printf("%d\n", cost[M][N]);
    
    
}
