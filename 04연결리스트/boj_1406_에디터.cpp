#include <iostream>
#include <string>
#include <list>

using namespace std;

string s;
int n;


int main() {
    cin >> s >> n;
    list<char> li(s.begin(), s.end());
    auto now = li.end();   // 현재 커서의 위치 : 지금은 list의 제일 뒤를 가리키고 있음. (list<char>::iteratrot now = li.end() 와 같은 의미

    for (int i = 0; i < n; i++) {
        char command;
        cin >> command;

        if (command == 'L') {
            if(now != li.begin()){                // 커서 위치가 젤 앞에있으면 더이상 왼쪽으로 갈수 없으니까.
                now--;
            }
        }
        else if (command == 'D'){                 // 커서 위치가 젤 뒤에있으면 더이상 오른쪽으로 갈수 없으니까.
            if(now != li.end()){
                now++;
            }
        }
        else if (command == 'B'){                 // 커서 위치가 젤 앞에 있으면 삭제안하고 무시
            if(now != li.begin()){
                now--;                            // 커서 기준 오른쪽 값을 지워버림.
                now = li.erase(now);      // erase 함수는 삭제 이후 itearator를 반환하니까 꼭 반환 값을 받아 저장해야함.
            }
        }
        else if (command == 'P'){
            char str;
            cin >> str;
            li.insert(now, str);        // now가 가리키는 곳에 str을 추가함, 즉 커서 기준 왼쪽
        }
    }
    for (auto i : li){
        cout << i;
    }

    return 0;
}