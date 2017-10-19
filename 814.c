#include <iostream>
#include <cstring>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>

using namespace std;

void get_city(string s, string& tar_na, string & tar_ci){
    int k = s.find('@');
    tar_na = s.substr(0, k);
    tar_ci = s.substr(k + 1);
}

int main(){
    set <string> s;
    string city, name, tar, tar_na, tar_ci, obj, obj_na, obj_ci, word;
    int nu;
    char c;
    while(cin >> city && city != "*"){
        cin >> city >> nu;
        while(nu--){
            cin >> name;
            s.insert(name + "@" + city);
        }
    }
    while(cin >> tar && tar != "*"){
        get_city(tar, tar_na, tar_ci);
        map<string, vector<string>> dst;
        vector<string> mta;
        set<string> once;
        while(cin >> obj && obj != "*"){
            get_city(obj, obj_na, obj_ci);
            if(once.count(obj))
                continue;
            once.insert(obj);
            if(!dst.count(obj_ci)){
                mta.push_back(obj_ci);
                dst[obj_ci] = vector<string>();
            }
            dst[obj_ci].push_back(obj_na);
        }
        getchar();
        word = "";
        while(1){
            scanf("%c", &c);
            if(c == '*')
                break;
            word += c;
            if(c == '\n')
                word+= "     ";
        }
        //cout << city;
        for(int i = 0; i < mta.size(); i++){
            string k = mta[i];
            vector <string> another = dst[k];
            cout << "Connection between " << tar_ci << " and "<< mta[i] << endl;
            cout << "     HELO " << tar_ci << "\n"<<"     250\n";
            cout << "     MAIL FROM:<"<< tar <<">\n"<<"     250\n";
            int ok = 0;
            for(int j = 0; j < another.size(); j++){
                cout << "     RCPT TO:<" << another[j]<< "@" << mta[i] << ">\n";
                if(s.count(another[j] + "@"+ mta[i])){
                    ok = 1;
                    cout << "     250\n";
                }
                else
                    cout << "     550\n";
            }
            if(ok){
                cout <<"     DATA\n     354\n     " << word << ".\n";
                cout << "     250\n";
            }
            cout << "     QUIT\n     221\n";
        }
    }
    /*for(vector <string> :: iterator it = dst["1"].begin(); it != dst["1"].end(); it++){
        cout << *it << endl;
    }*/
    return 0;
}
