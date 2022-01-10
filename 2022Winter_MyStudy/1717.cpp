
//
//  main.cpp
//  2022winter_algo
//
//  Created by 최희연 on 2022/01/10.
//

#include <iostream>
#include <vector>

using namespace std;

int n, m;
int arr[1000001];

int Find(int n){
    if(arr[n] == n)
        return n;
    else{
       return arr[n] = Find(arr[n]);
       
    }
    
}

void Union(int n1, int n2){
    //n2을 조상으로
    arr[Find(n1)]=Find(n2);
}



int main() {
    scanf("%d %d", &n, &m);
    
    //자기자신으로 초기화
    for(int i=0;i<=n;i++){
        arr[i] = i;
    }
    
    for(int i=0;i<m;i++){
        int op, num1, num2;
        scanf(" %d %d %d", &op, &num1, &num2);
        if(op==0){ //union 연산
            Union(num1, num2);
        }
        else { //find 연산
            if(Find(num1) == Find(num2))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}
