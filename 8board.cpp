#include <bits/stdc++.h>

using namespace std;


int manhatan(string s) {

    int sum = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i] == '0') {
            continue;
        }
        int x = s[i] - '1';
        sum += abs(x/3 - i/3) + abs(x%3 - i%3);
    }
    return sum;
}

void print(string s) {
    for (int i=0; i<9; i++) {
        cout << s[i] << " ";
        if (i%3 == 2) {
            cout << "\n";
        }
    }
    cout << "\n";
}

int main() {
    // String board = input.nextLine();
    
    map<string, pair<int, char>> closed;
    priority_queue<pair<int, pair<pair<int, char>, string>>> open;

    string board = "867254301";
    // string board = "724506831";
    // string board = "123456087";
    // string board = "647850321";
    // string board = "182043765";

    int g = 0;
    int h = manhatan(board);

    open.push({-(g+h), {{g, 's'}, board}});

    pair<int, pair<pair<int, char>, string>> ans;

    int steps = 0;
    int f = 0;
    bool flag = false;
    while (!open.empty()) {
        pair<int, pair<pair<int, char>, string>> p = open.top();
        open.pop();
        steps++;
        if (closed.find(p.second.second) != closed.end() && closed[p.second.second].first <= -p.first) {
            continue;   
        }

        // cout << p.second.second << "    " << closed.size() << "\n";
        closed[p.second.second] = p.second.first;

        if (manhatan(p.second.second) == 0) {
            cout << "Found in "<< steps << " steps" << endl;
            flag = true;
            ans = p;
            break;
        }

        int x, y; 
        for (int i=0; i<9; i++) {
            if (p.second.second[i] == '0') {
                x = i/3;
                y = i%3;
                break;
            }
        }

        if (x > 0) {
            string s = p.second.second;
            swap(s[x*3+y], s[(x-1)*3+y]);
            open.push({-(p.second.first.first+1+manhatan(s)), {{p.second.first.first+1, 'U'}, s}});
        }
        if (x < 2) {
            string s = p.second.second;
            swap(s[x*3+y], s[(x+1)*3+y]);
            open.push({-(p.second.first.first+1+manhatan(s)), {{p.second.first.first+1, 'D'}, s}});
        }
        if (y > 0) {
            string s = p.second.second;
            swap(s[x*3+y], s[x*3+y-1]);
            open.push({-(p.second.first.first+1+manhatan(s)), {{p.second.first.first+1, 'L'}, s}});
        }
        if (y < 2) {
            string s = p.second.second;
            swap(s[x*3+y], s[x*3+y+1]);
            open.push({-(p.second.first.first+1+manhatan(s)), {{p.second.first.first+1, 'R'}, s}});
        }
    }
    
    if (!flag) {
        cout << "Not found" << endl;
        return 0;
    }

    string s = ans.second.second;
    string final = "";

    while (s != board) {
        final = closed[s].second+ final;

        print(s);

        int x, y; 
        for (int i=0; i<9; i++) {
            if (s[i] == '0') {
                x = i/3;
                y = i%3;
                break;
            }
        }
        
        if (closed[s].second == 'U') {
            swap(s[x*3+y], s[(x+1)*3+y]);
        }
        else if (closed[s].second == 'D') {
            swap(s[x*3+y], s[(x-1)*3+y]);
        }   
        else if (closed[s].second == 'L') {
            swap(s[x*3+y], s[x*3+y+1]);
        }
        else if (closed[s].second == 'R') {
            swap(s[x*3+y], s[x*3+y-1]);
        }    
    }

    print(s);

    cout << "minimun no steps to solve is: " << final.length() << endl;
    cout << "steps are: " << final;
    
}

