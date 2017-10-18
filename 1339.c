#include <istream>
#include <algorithm>
#include <cstring>
using namespace std;

int main(){
    char source[128];
    char tar[128];
    int i, flag;
    int set1[26], set2[26];
    while(scanf("%s %s", source, tar) != EOF){
        i = 0;
        flag = 0;
        memset(set1, 0, sizeof(set1));
        memset(set2, 0, sizeof(set2));
        while(source[i] != '\0'){
            set1[source[i] - 'A']++;
            set2[tar[i] - 'A']++;
            i++;
        }
        sort(set1, set1 + 26);
        sort(set2, set2 + 26);
        for(int j = 0; j < 26; j++){
            if(set1[j] != set2[j]){
                flag = 1;
                break;
            }
        }
        if(flag == 1){
            printf("NO\n");
        }
        else
            printf("YES\n");
    }
    return 0;
}