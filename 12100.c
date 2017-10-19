#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#include <string.h>

using namespace std;
int arr[105];

int find(int size){
    int j = 0;
    for(int i = 0; i < size; i++){
        if(arr[j] < arr[i])
            j = i;
    }
    return j;
}
int main(){
    int tot, val;
    scanf("%d", &tot);
    while(tot--){
        queue <int> q;
        int num, pos, tar, count = 0;
        scanf("%d%d", &num, &pos);
        for(int i = 0; i < num; i++){
            scanf("%d", &val);
            if(i == pos){
                val += 9;
                tar = val;
            }
            q.push(val);
        }
        //printf("size %d    ", q.size());
        while(1){
            memset(arr, 0, sizeof(arr));
            queue <int> s;
            s = q;
            /*for(int j = 0; j < num; j++){
                printf("%d ", q.front());
                q.pop();
            }
            printf("\n");*/
            int k = s.size();
            for(int i = 0; i < k; i++){
                if(s.front() > 9)
                    arr[i] = s.front() - 9;
                else
                    arr[i] = s.front();
                s.pop();
            }
            /*for(int i = 0; i < k; i++){
                printf("%d ", arr[i]);
            }
            printf("\n");*/
            int iter = find(k), flag = 0, vl;
            //printf("%d   %d\n", iter, tar);
            while(iter--){
                vl = q.front();
                q.pop();
                q.push(vl);
            }
            vl = q.front();
            q.pop();
            if(tar == vl)
                flag = 1;
            count++;
            if(flag == 1){
                printf("%d\n", count);
                break; // not real break, need to edit
            }
        }

    }
    return 0;
}