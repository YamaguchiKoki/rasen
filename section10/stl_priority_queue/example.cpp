include<bits/stdc++.h>
using namespace std;

int main() {
    char com[20];
    //デフォルトでは値の大きいものから優先度付けされている
    priority_queue<int> PQ;

    while(1) {
        scanf("%s", com);
        if(com[0] == 'i') {
            int key; scanf("%d", &key);
            PQ.push(key);
        } else if(com[1] == 'x') {
            printf("%d\n", PQ.top());
            PQ.pop();
        } else if(com[0] == 'e') {
            break;
        }
    }

    return 0;
}