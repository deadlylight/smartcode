#include<string>
#include<stdio.h>
#include<vector>
#include<queue>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        int openLock(vector<string>& deadends, string target) {
            if (target == "0000") return 0;
            queue<int> searchq;
            unordered_set<int> deadends2;
            for (int i = 0; i < deadends.size(); ++i) {
                int v = deadends[i][3] - '0';
                v += (deadends[i][2]-'0') * 10;
                v += (deadends[i][1]-'0') * 100;
                v += (deadends[i][0]-'0') * 1000;
                deadends2.insert(v);
            }
            int tt = target[3] - '0';
            tt += (target[2]-'0') * 10;
            tt += (target[1]-'0') * 100;
            tt += (target[0]-'0') * 1000;

            if (deadends2.count(0) > 0) return -1;
            searchq.push(0);
            int round = 0;

            while (searchq.size() > 0) {
                round++;
                int round_size = searchq.size();
                //printf("round=%d\n", round);
                while (round_size > 0) {
                    round_size--;
                    int step = searchq.front();
                    searchq.pop();

#define PUSHSTEP(pos, how) if (push(tt, step, pos, how, searchq, deadends2)) return round
                    PUSHSTEP(1, 1);
                    PUSHSTEP(10, 1);
                    PUSHSTEP(100, 1);
                    PUSHSTEP(1000, 1);
                    PUSHSTEP(1, -1);
                    PUSHSTEP(10, -1);
                    PUSHSTEP(100, -1);
                    PUSHSTEP(1000, -1);
                    deadends2.insert(step);
                }
            }
            return -1;
        }
        bool push(int tt, int step, int pos, int how, queue<int>& searchq, unordered_set<int>& deadends2) {
            step += 30000;
            int step2 = step + pos*how;
            int up = pos*10;
            if (up < 0) {
                up = -up;
            }
            if (step/up*up != step2/up*up) {
                step2 -= pos*how*10;
            }
            step2 -= 30000;
            if (tt == step2) return true;
            if (deadends2.count(step2) > 0) return false;
            deadends2.insert(step2);
            searchq.push(step2);
            return false;
        }
};

int main()
{
    vector<string> deadends;
#if 0
    string target = "0202";
    deadends.push_back("0201");
    deadends.push_back("0101");
    deadends.push_back("0102");
    deadends.push_back("1212");
    deadends.push_back("2002");
#endif
#if 1
    string target = "8888";
    deadends.push_back("8887");
    deadends.push_back("8889");
    deadends.push_back("8878");
    deadends.push_back("8898");
    deadends.push_back("8788");
    deadends.push_back("8988");
    deadends.push_back("7888");
    deadends.push_back("9888");
#endif
    //deadends.push_back("");

    Solution s;
    printf("%d\n", s.openLock(deadends, target));
    return 0;
}

