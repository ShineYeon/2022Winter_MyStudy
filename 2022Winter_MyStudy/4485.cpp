//
//  4485.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/18.
//

#include <iostream>
#include <queue>
using namespace std;

#define INF 987654321

int N;
int cave[126][126];
int moveX[4] = {-1, 1, 0, 0};
int moveY[4] = {0, 0, 1, -1};
int cost[126][126];
int nowX, nowY, newX, newY;
queue<pair<int, int>> q;
int k;
int cnt=1;
int ret = INF;
int Min = INF;

int main(){
    while(1){
        scanf("%d", &N); // 동굴의 크기
        if(N==0) break;
        
        for(int i=0;i<=N;i++){
            for(int j=0;j<=N;j++){
                cost[i][j] = INF;
                cave[i][j] = 0;
            }
        }
        
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                scanf("%d", &k);
                cave[i][j] = k;
            }
        }
       
        q.push(make_pair(0, 0));
        cost[0][0] = cave[0][0];
        
        while(!q.empty()){
            
            nowX = q.front().first;
            nowY = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++){
                newX = nowX + moveX[i];
                newY = nowY + moveY[i];
                
                if(newX<0 || newY<0 || newX>=N || newY>=N)
                    continue;
                if(cost[newX][newY] > cost[nowX][nowY] + cave[newX][newY]){
                    cost[newX][newY] = cost[nowX][nowY] + cave[newX][newY];
                    q.push(make_pair(newX, newY));
                }
                
            }
           
        }
        cout<<"Problem "<<cnt<<": "<<cost[N-1][N-1]<<endl;
        cnt++;
        
    }
    return 0;
}
