//
//  0109_study.cpp
//
//
//  Created by 최희연 on 2022/01/09.
//

#include <iostream>
#include <vector>
using namespace std;

/*gcd 구하기*/
int gcd(int x, int y){
    if(x==0)
        return y;
    else
        return gcd(y%x, x);
}

/*오일러파이*/
int phi(int x){
    int result=1;
    for(int i=2;i<x;i++){
        if(gcd(i, x)==1)
            result++;
    }
    return result;
}

int extEuclid(int a, int b, int &x, int &y){
    int xx=y=0;
    int yy=x=1;
    while(b){
        int q=a/b;
        tie(a, b)=tuple(b, a%b);
        tie(x, xx)=tuple(xx, x-q*xx);
        tie(y, yy)=tuple(yy, y-q*yy);
        
    }
    return a;
}

/* 유클리드 호제법 */
int mod(int a, int m){ //a%m 을 반환
    return ((a%m)+m)%m;
}

int modPow(int b, int p, int m) { //b^p %m 을 반환
    if(p==0) return 1;
    int ans = modPow(b, p/2, m); //일단 반으로 나눠서
    ans=mod(ans*ans, m); // 반으로 나눴으니까 제곱해야됨
    if(p&1) //p가 홀수
        ans=mod(ans*b, m);
    return ans;
}


int modInverse(int b, int m) {
    int x, y;
    int d = extEuclid(b, m, x, y);
    if(d!=1)
        return -1;
    return mod(x, m);
}


/* 순열 로직  NCM 구현 */
#define MAXN 10
int n, m;
vector<int> vc; //내가 출력할 것
bool visit[10]; //그 숫자가 쓰는지 확인

void dfs() {
    if(vc.size() == m){
        for(auto i:vc)
            printf("%d ", i);
        printf("\n");
        return;
    }
    
    for(int i=1;i<=n;i++){
        if(!visit[i]){
            visit[i] = true;
            vc.push_back(i);
            dfs();
            vc.pop_back();
            visit[i] = false;
        }
    }
}


/* 조합 로직 */
void dfs(int cnt) {
    if(vc.size() == m){
        for(auto i:vc)
            printf("%d ", i);
        printf("\n");
        return;
    }
    
    for(int i=cnt;i<=n;i++){
        if(vc.size() < m){
            vc.push_back(i);
            dfs(i+1);
            vc.pop_back();
        }
    }
}
