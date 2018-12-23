#include<vector>
#include<stack>
using namespace std;

class Solution {
    public:
        bool canVisitAllRooms(vector<vector<int>>& rooms) {
            int size = rooms.size();
            vector<int> opened(size, 0);
            int opencount = 1;
            opened[0] = 1;
            stack<int> keys;
            keys.push(0);

            while (keys.size() > 0) {
                int key = keys.top();
                keys.pop();

                vector<int>& roomkeys = rooms[key];
                for (vector<int>::const_iterator it = roomkeys.begin(); it != roomkeys.end(); ++it) {
                    int key = *it;
                    if (!opened[key]) {
                        opened[key] = 1;
                        printf("open %d\n", key);
                        opencount++;
                        if (opencount == size) return true;
                        keys.push(key);
                    }
                }
            }
            return opencount == size;
        }
};
