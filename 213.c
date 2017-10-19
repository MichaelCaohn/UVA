#include <iostream>

using namespace std;
int store[8][1<<8];

int readchar(){
    int c;
    while(1){
        c = getchar();
        if(c != '\n' && c != '\r'){
            return c;
        }
    }
}

int readtarget(){
    int a;
    memset(store, 0 , sizeof(store));
    store[1][0] = readchar();
    for(int i = 2; i <= 7; i++){
        for(int j = 0; j < (1 << i) - 1; j++){
            a = getchar();
            if(a == EOF)
                return 0;
            if(a == '\n' || a == '\r')
                return 1;
            store[i][j] = a;
        }
    }
    return 1;
}


int convert(int num){
    int val = 0;
    while(num > 0){
        val = val * 2 + readchar() - '0';
        num--;
    }
    return val;
}

int main(){
    int len, val;
    while(readtarget()){
        while(1){
            len = convert(3);
            if(len == 0)
                break;
            while(1){
                val = convert(len);
                if(val == (1 << len) - 1){
                    break;
                }
                putchar(store[len][val]);
            }
        }
        printf("\n");
    }
    return 0;
}