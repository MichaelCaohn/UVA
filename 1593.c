//#define LOCAL    
#include<iostream>    
#include<iomanip>    
#include<string>    
#include<vector>    
#include<ctime>    
#include<sstream>    
#include<algorithm>    
using namespace std;    
vector<string> s[1005];    
int len[185];    
    
int main(){    
#ifdef LOCAL    
    freopen("in.txt", "r", stdin);    
    freopen("out.txt", "w", stdout);    
#endif    
    string line,buf;    
    int i = 0,j=0;    
    while (getline(cin, line)){    
        istringstream stream(line);    
        while (stream >> buf){    
            len[j] = max(len[j], (int)buf.length());    
            j++;    
            s[i].push_back(buf);    
        }    
        i++; j = 0;    
    }    
    cout << setiosflags(ios::left);    
    for (int k = 0; k < i; k++){    
        int l = 0;    
        for ( l; l < s[k].size()-1; l++){    
            cout << setw(len[l] + 1) << s[k][l];    
        }    
        cout << s[k][l]<< endl;                 //每行单词最后一个单词后面不应该有空格输出    
    }    
    //printf("Time used=%.3f\n", (double)clock() / CLOCKS_PER_SEC);    
    return 0;    
}    