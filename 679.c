#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int kase, depth, no;
    scanf("%d", &kase);
    while(kase--){
        scanf("%d%d", &depth, &no);
        int k = 1;
        for(int i = 0; i < depth - 1; i++){
            if(no % 2){
                k = 2*k;
                no = (no + 1)/2;
            }
            else{
                k = 2*k + 1;
                no = no/2;
            }
        }
        printf("%d\n", k);
    }
    return 0;
}