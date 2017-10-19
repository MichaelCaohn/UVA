#include <iostream>
#include <set>
#include <string>

using namespace std;

int main(){
    set <string> source;
    set <string> target;
    string s;
    while(getline(cin, s)){
        source.insert(s);
    }
    for(set <string>:: iterator it = source.begin(); it != source.end(); it++){
        s = *it;
        for(int i = 0; i < s.length() -1; i++){
            string a = s.substr(0, i + 1);
            string b = s.substr(i + 1, s.length() - (i  + 1));
            if(source.count(a) != 0 && source.count(b) != 0)
                target.insert(s);
        }
    }
    for(set <string> :: iterator it = target.begin(); it != target.end(); it++)
        cout << *it << endl;
    return 0;
}