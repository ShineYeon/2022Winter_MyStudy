//
//  2458.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/11.
//

/*
 이게 어떻게 플로이드 와샬인가?
 
 */
#include <iostream>
using namespace std;

#define INF 1e9

int N, M; //N은 학생 수, M은 키를 비교한 횟수
int a, b;
int answer = 0;
int compare[501][501];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=N;j++){
            compare[i][j]= INF;
        }
    }
    for(int i=0;i<M;i++){
        cin>>a>>b;
        compare[a][b] = 0;
    }
    
    for(int k=1;k<=N;k++){
        for(int i=1;i<=N;i++){
            for(int j=1;j<=N;j++){
                if(i==j) continue;
                if(compare[i][k]==INF||compare[k][j]==INF) continue;
                if(compare[i][j]>compare[i][k]+compare[k][j])
                    compare[i][j]=compare[i][k]+compare[k][j];
            }
        }
    }
    
    int cnt=0;
    
    for(int i=1;i<=N;i++){
        cnt=0;
        for(int j=1;j<=N;j++){
            if(i==j) cnt++;
            if(compare[i][j]==0 || compare[j][i]==0)
                cnt++;
        }
        if(cnt==N) answer++;
    }
    cout<<answer<<endl;
    
}
