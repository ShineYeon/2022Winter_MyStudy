//
//  LCA.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/12.
//

/*
 LCA 기본 코드
 백준 11438번 (LCA 2)
 */

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

#define MAX 20
int N, M;
int a, b;
int dp[MAX + 1][100001];
int depth[100001];
bool isVisited[100001];
vector<int> v[100001];

//깊이 찾기
void dfs(int n, int d) {

    isVisited[n] = true;
    depth[n] = d;
    int vi;
    for (int i = 0; i < v[n].size(); i++) {
        vi = v[n].at(i);
        if (isVisited[vi]) continue;
        dp[0][vi] = n;
        dfs(vi, d + 1);
    }
}

// dp배열
void setDP(){
    for (int i = 1; i < MAX; i++) {
            for (int j = 1; j <= N; j++) {
                dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }
}

//lca코드
int lca(int x, int y){
    
    if (depth[x] > depth[y]) //일단 y의 depth가 더 크다고 설정
            swap(x, y);
        for (int i = MAX; i >= 0; i--) {
            if (depth[y] - depth[x] >= (1 << i))
                y = dp[i][y];
        }
        if (x == y) return x;

    //깊이를 맞춰줬는데 최소공통조상이 다르다면 찾아준다.
        for (int i = MAX; i >= 0; i--) {
            if (dp[i][x] != dp[i][y]) {
                x = dp[i][x];
                y = dp[i][y];
            }
        }
        return dp[0][x];
    
}

int main(){
    scanf("%d", &N);

        for (int i = 1; i < N; i++) {
            scanf("%d %d", &a, &b);
            v[a].push_back(b);
            v[b].push_back(a);
        }

        memset(isVisited, 0, sizeof(isVisited));
        dfs(1, 1);

        setDP();

        scanf("%d", &M);
        for(int i = 0; i < M; i++){
            scanf("%d%d", &a, &b);
            printf("%d\n", lca(a, b));
        }
        return 0;
}
