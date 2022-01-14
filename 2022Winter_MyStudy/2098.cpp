//
//  2098.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/14.
//

/*
 dfs + dp + 비트 마스킹 방법
 16개 도시를 방문했다 / 방문하지 않았다를 비트로 표현할 수 있음.
 
 dfs를 푼다:
 dfs(n, bit) 방문여부를 저장한 bit를 갖다가, n번 해서 들어왔을 때 그 때 경로 최솟값을 dp 배열이 반환
    -> 어떤 경우에 탈출할 지 탈출조건 필요 (dp가 모든 노드를 방문하면 탈출) 모든 노드를 방문했다는 것은 모든 비트가 1로 채워진 경우.
    일단 노드들에서 방문 안한 노드를 체크해야 함. (방문 여부는 다 비트로 저장되어 있음) -> for문으로 다음 방문 노드들을 다 파악해야함
 dp[a][b] -> a, b에 어떤 값이 저장되어야 할지 정해야함
 
 */
#include <iostream>
using namespace std;

#define INF 987654321

int N;
int w[17][17];

//dp[k][visited] : k번째 마을, visited: 방문했던 도시들을 2진법으로 표시
// 현재도시에서, 방문했던 도시들 상태에서 순회를 마치는데 드는 최소 비용
int dp[16][1<<16];

int tsp(int current, int visited){
    int &ret = dp[current][visited];
    if(ret != -1)
        return ret;
    
    //모든 마을을 방문했는가
    if(visited == (1<<N)-1){
        //current -> 0 이동 가능한지
        if(w[current][0] != 0)
            return w[current][0];
        //가능하지 않으면
        return INF;
    }
    ret = INF;
    for(int i=0;i<N;i++){
        //방문했거나 current->i로 길이 없다면
        if(visited & (1<<i) || w[current][i] == 0)
            continue;
        ret = min(ret, tsp(i, visited|(1<<i))+w[current][i]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>w[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    
    //어떤 도시에서 출발하든 순회비용은 변화가 없기 때문에 1번 도시(인덱스는 0)부터 출발
    cout<<tsp(0, 1)<<endl;
    
}
