#include <iostream>
#include <string>
#include <string.h>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;

struct library {
    string aur;
    string tit;
    bool operator < (const library &str1)const{
        if(this->aur == str1.aur)
            return this->tit < str1.tit;
        return this->aur < str1.aur;
    }
}Lib[1005];
map <string, int> value;

int get_pos(int pos){
    for(int i = pos - 1; i >= 0; i--){
        if(value[Lib[i].tit] == 1)
            return i;
    }
    return -1;
}
int main(){
    char c;
    string s, au, ti;
    int count = 0;
    while(1){
        getline(cin, s);
        if(s[0] == 'E')
            break;
        else{
            int pos = s.find('"');
            au = s.substr(pos + 1);
            pos = au.find('"');
            //cout << s <<" " << pos << endl;
            ti = s.substr(0, pos + 2);
            au = s.substr(pos + 5);
            Lib[count].aur = au;
            Lib[count].tit = ti;
            value[Lib[count].tit] = 1;
            count++;
        }
    }
    sort(Lib, Lib + count);
    /*for(int i = 0; i < count; i++){
        cout << Lib[i].tit  << value[Lib[i].tit] << endl;
    }*/
    while(cin >> s){
        if(s[0] == 'E')
            break;
        else if(s[0] == 'B'){
            getchar();
            getline(cin, s);
            value[s] = 0;
        }
        else if(s[0] == 'R'){
            getchar();
            getline(cin, s);
            //cout << s << endl;
            value[s] = 2;

        }
        else if(s[0] == 'S'){
            /*cout << endl;
            for(int i = 0; i < count; i++){
                cout << Lib[i].tit  << value[Lib[i].tit] << endl;
            }*/
            for(int j = 0; j < count; j++){
                if(value[Lib[j].tit] == 2){
                    int poss = get_pos(j);
                    if(poss == -1)
                        cout << "Put " << Lib[j].tit << " first" << endl;
                    else
                        cout << "Put "<< Lib[j].tit << " after "<< Lib[poss].tit<<endl;
                    value[Lib[j].tit] = 1;
                }
            }
            printf("END\n");
        }
    }
    return 0;
}