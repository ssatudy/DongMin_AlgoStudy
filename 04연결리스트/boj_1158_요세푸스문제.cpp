#include <iostream>
#include <list>

using namespace std;

int N, K;
list<int> li;

int main() {
    cin >> N >> K;
    for (int i=1; i <=N; i++) {
        li.push_back(i);
    }
    auto now = li.begin();

    cout << '<';

    while (li.size() > 1) {
        for (int i = 0; i < K-1; i++){
            now++;
            if (now == li.end()) {
                now = li.begin();
            }
        }
        cout << *now << ", ";

        now = li.erase(now);

        if (now == li.end()) {
            now = li.begin();
        }
    }

    cout << *now << '>';

    return 0;
}

