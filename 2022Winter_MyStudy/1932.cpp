//
//  1932.cpp
//  2022Winter_MyStudy
//
//  Created by 최희연 on 2022/01/13.
//

#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[500][500];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cin>>arr[i][j];
        }
    }
    
    int Max = 0;
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            if (j == 0)
                arr[i][j] = arr[i-1][0] + arr[i][j];
            else if (j == i)
                arr[i][j] = arr[i-1][j-1] + arr[i][j];
            else
                arr[i][j] = max(arr[i-1][j-1] + arr[i][j], arr[i-1][j] + arr[i][j]);
                        
        }
    }
    
    for(int i=0;i<n;i++){
        Max = max(Max, arr[n-1][i]);
    }
    cout<<Max<<endl;
    return 0;
}
