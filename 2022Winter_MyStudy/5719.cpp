//
//  5719.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/11.
//

/*
 거의 최단경로 문제:
 최단경로에 포함되지 않는 도로로만 이루어진 경로 중에서 최단 경로를 출력
 
 나의 아이디어:
 최단경로를 구해서 일단 저장해
 그담에 그 저장한 걸 가지고 그것보다 더 큰 것 중에서 최단 경로를 구해
 일단 최단 경로를 구해야 되니까 다익스트라 이용하자.
 
 쌤 아이디어:
 최단 경로 다 탐색하고 다음에 저장할 때 par배열을 만들자
 업데이트가 될 때 par[B]에다가 하나를 넣어, 'A로부터 왔다'
 최단 경로를 지우는 과정을 만든다.
 (N*N 매트릭스를 만들어서, 모든 배열의 값을 false로 만들고, 최단 경로 값을 true로
 매트릭스 값이 true면? 가지마 -> 지워진거나 마찬가지, 그 경로를 못가는것)
 */
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define INF 987654321

using namespace std;

struct Data {
    int n;
    int w;
    Data() {};
    Data(int n, int w) : n(n), w(w) {};

    bool operator< (const Data d) const {
        return w > d.w;
    }
};

int N, M;
int S, D;
int u, v, p;
vector<Data> path[500];
int dist[500];
bool isPath[500][500];
vector<int> par[500];

void dijkstra(int seq) {
    priority_queue<Data> pq;

    pq.push(Data(S, 0));
    dist[S] = 0;

    while (true) {
        if (pq.empty()) break;
        Data d = pq.top();
        pq.pop();

        Data nextD;
        for (int i = 0; i < path[d.n].size(); i++) {
            nextD = path[d.n].at(i);

            if (isPath[d.n][nextD.n]) continue;

            if (dist[nextD.n] > dist[d.n] + nextD.w) {
                dist[nextD.n] = dist[d.n] + nextD.w;
                pq.push(Data(nextD.n, dist[nextD.n]));
                if(seq == 1){
                    par[nextD.n].clear();
                    par[nextD.n].push_back(d.n);
                }
            }
            else {
                if (seq == 1){
                    if (dist[nextD.n] == dist[d.n] + nextD.w) {
                        par[nextD.n].push_back(d.n);
                    }
                }
            }
        }
    }
}

void removePath(int start, int node) {

    if (node == start) return;

    for (int i = 0; i < par[node].size(); i++) {
        if (isPath[par[node].at(i)][node]) continue;
        isPath[par[node].at(i)][node] = true;
        removePath(start, par[node].at(i));
    }
}

int main(int argc, char** argv) {

    while (true) {
        scanf("%d %d", &N, &M);

        if (N == 0 && M == 0) break;

        scanf("%d %d", &S, &D);

        for (int i = 0; i < N; i++) {
            dist[i] = INF;
            path[i].clear();
            for (int j = 0; j < N; j++) {
                isPath[i][j] = false;
            }
        }

        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &u, &v, &p);
            path[u].push_back(Data(v, p));
        }

        dijkstra(1);

        if (dist[D] == INF) {
            printf("%d\n", -1);
            continue;
        }

        removePath(S, D);

        for (int i = 0; i < N; i++) {
            dist[i] = INF;
        }

        dijkstra(2);

        if (dist[D] == INF) {
            printf("%d\n", -1);
        }
        else {
            printf("%d\n", dist[D]);
        }
    }

    return 0;
}
