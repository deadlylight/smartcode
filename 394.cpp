#include<stdio.h>
#include<string>

using namespace std;

class Solution {
    public:
        string decodeString(string s) {
            string ret;
            for (int i = 0; i < s.length(); i++) {
                int repeat = 0;
                char c = s.at(i);
                if (c >= '0' && c <= '9') {
                    while (c >= '0' && c <= '9') {
                        repeat = repeat * 10 + c - '0';
                        //printf("repate=%d, i=%d\n", repeat, i);
                        i++;
                        c = s.at(i);
                    }
                    int brackets = 1;
                    int j = i + 1;
                    while (j < s.length() && (brackets > 0)) {
                        char c2 = s.at(j);
                        if (c2 == '[') brackets++;
                        if (c2 == ']') brackets--;
                        j++;
                    }
                    string s2(s, i+1, j-i-2);
                    //printf("repeat=%d, s2=%s\n", repeat, s2.c_str());
                    i = j-1;
                    while (repeat > 0) {
                        repeat--;
                        ret += decodeString(s2);
                    }
                } else {
                    ret += c;
                }
            }
            return ret;
        }
};


int main(int argc, char** argv)
{
    Solution s;
    string in(argv[1]);
    printf("ret=%s\n", s.decodeString(in).c_str());
    return 0;
}
