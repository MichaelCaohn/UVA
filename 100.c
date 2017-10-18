#include <stdio.h>

int oper (int number){
    int count = 1;
    while(number != 1){
        if(number % 2 == 0)
            number = number / 2;
        else
            number = 3 * number + 1;
        count++;
    }
    return count;
}

int main(){
    int a, b, max, temp, c, i, f, e;
    while(scanf("%d %d", &a, &b) != EOF){
        max = 0;
        f = a;
        e = b;
        if(a > b){
            temp = a;
            a = b;
            b = temp;
        }
        for(i = a; i <= b; i++){
            c = oper(i);
            if(max < c)
                max = c;
        }
        printf("%d %d %d\n", f, e, max);
    }
    return 0;
}