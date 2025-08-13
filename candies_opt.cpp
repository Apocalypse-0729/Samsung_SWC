#include <bits/stdc++.h>
using namespace std;

pair<long long, long long> step(pair<long long, long long> p) {
    long long a = p.first, b = p.second;
    long long mini = min(a, b);
    if (mini == 0) return p; // terminal state
    if (mini == a) {
        a += mini;
        b -= mini;
    } else {
        b += mini;
        a -= mini;
    }
    return {a, b};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    for (int caseNo = 1; caseNo <= t; caseNo++) {
        long long a, b, k;
        cin >> a >> b >> k;

        vector<pair<long long,long long>> seq;
        unordered_map<long long,int> pos; // store position by min(a,b)
        
        seq.push_back({a, b});
        pos[min(a,b)] = 0;
        
        int cycleStart = -1, cycleLen = 0;
        for (int i = 1;; i++) {
            auto nextState = step(seq.back());
            seq.push_back(nextState);
            long long m = min(nextState.first, nextState.second);
            if (m == 0) { cycleStart = -1; break; }
            if (pos.count(m)) {
                cycleStart = pos[m];
                cycleLen = i - cycleStart;
                break;
            }
            pos[m] = i;
        }

        cout << "#" << caseNo << " ";
        if (cycleStart == -1) {
            // reached zero before cycle
            if (k < (int)seq.size()) cout << min(seq[k].first, seq[k].second) << "\n";
            else cout << 0 << "\n";
        } else {
            if (k < cycleStart) {
                cout << min(seq[k].first, seq[k].second) << "\n";
            } else {
                int idx = cycleStart + (k - cycleStart) % cycleLen;
                cout << min(seq[idx].first, seq[idx].second) << "\n";
            }
        }
    }
}
