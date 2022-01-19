//
//  11401.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/19.
//

/*
 페르마의 소정리, 분할 정복 문제
 */
#include <iostream>
using namespace std;

long long N, K, A, B, half;
long long divider = 1000000007;

// B^x 과정 (분할정복)
long long sol(int x){
    //0승이면 1을 반환
    if(x==0) return 1;
    // 홀수승이면 B하나 * B짝수승 반환 (B짝수승은 홀수승에서 -1한것)
    if(x%2 == 1) return B*sol(x-1)%divider;
    //짝수승이면 두개로 쪼개서 반환
    else{
        half = sol(x/2);
        return half*half%divider;
    }
}



int main(){
    scanf("%lld %lld", &N, &K);
    
    A=1;
    // A=N*(N-1)*(N-2)*...*(N-K+1)
    for(long long i=N; i>=N-K+1; i--)
        A = (A*i)%divider;
    
    B=1;
    // B=K!
    for(long long i=1; i<=K; i++)
        B = (B*i)%divider;
    
    //B=(K!)^(p-2)
    B = sol(divider-2);
    
    //(AB^(-1)%p = AB^(p-2)%p = (A%p)(B^(p-2)%p)
    
    printf("%lld\n", A*B%divider);
}
