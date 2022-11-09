#include <iostream>
#include <string>
#include <list>
#include <algorithm>

using namespace std;

int tc;

int main() {
    cin >> tc;
    for(int i = 0; i < tc; i++){
        string pwd;
        cin >> pwd;
        pwd.erase(remove(pwd.begin(), pwd.end(), ' '), pwd.end());

        list<char> li;
        auto now = li.begin();

        for (int i = 0; i < pwd.length(); i++){
            if (pwd[i] == '<') {
                if (now != li.begin()) {
                    now--;
                }
            }
            else if (pwd[i] == '>') {
                if (now != li.end()) {
                    now++;
                }
            }
            else if (pwd[i] == '-') {
                if (now != li.begin()){
                    now--;
                    now = li.erase(now);
                }
            }
            else {
                li.insert(now, pwd[i]);
            }
        }
        for (auto i : li){
            cout << i;
        }
        cout << '\n';

    }
    return 0;
}