/*
https://www.careercup.com/question?id=5677905146281984
https://github.com/arjunsk/samsung_interview/blob/master/wormhole.cpp
https://gist.github.com/gunpreet34/b58c38b3556271059182244676ba06a1
https://hack.codingblocks.com/contests/c/782/870
https://discuss.codingblocks.com/t/test-case-of-minimum-time-traversal-problem/12944

http://ideone.com/Sbx7MA
*/

/*
There is one spaceship. X and Y co-odinate of source of spaceship and destination spaceship is given.
There are N number of warmholes; each warmhole has 5 values. First 2 values are starting co-ordinate
of warmhole and after that value no. 3 and 4 represents ending co-ordinate of warmhole and last 5th 
value is represents cost to pass through this warmhole. Now these warmholes are bi-directional. Now 
the to go from (x1,y1) to (x2,y2) is abs(x1-x2)+abs(y1-y2). The main problem here is to find minimum 
distance to reach spaceship from source to destination co-ordinate using any number of warm-hole. 
It is ok if you wont use any warmhole.
*/
#include <iostream>
#include <climits>
using namespace std;

int ANS = INT_MAX, n, temp = 0;
int w[35][5];
int mask[35];

int abs(int i){
    return (i>=0) ? i : -1*i;
}

int min(int x, int y){
    return (x>=y) ? y : x;
}

int dist(int sX, int sY, int tX, int tY){
    return abs(sX-tX) + abs(sY-tY);
}

void wormhole(int sX, int sY, int tX, int tY, int value){
    ANS = min(ANS, dist(sX, sY, tX, tY) + value);

    for(int i=0; i<n; i++){
        if(mask[i] == 0){
            mask[i] = 1;

            /* Choose lower end of wormhole */
            temp = dist(sX, sY, w[i][0], w[i][1]) + w[i][4] + value;
            wormhole(w[i][2], w[i][3], tX, tY, temp);

            /* Choose upper end of wormhole */
            temp = dist(sX, sY, w[i][2], w[i][3]) + w[i][4] + value;
            wormhole(w[i][0], w[i][1], tX, tY, temp);

            mask[i] = 0;
        }
    }
}

int main() {
    int t, sX, sY, tX, tY;
    cin >> t;
    while(t--){
    	ANS = INT_MAX;
        cin >> n;
        cin >> sX >> sY >> tX >> tY;
        for(int i=0; i<n; i++){
            mask[i] = 0;
            for(int j=0; j<5; j++){
                cin >> w[i][j];
            }
        }

        wormhole(sX, sY, tX, tY, 0);
        cout << ANS << endl;
    }
    return 0;
}
