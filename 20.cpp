#include<stdio.h>
#include<stack>
#include<string>
using namespace std;

class Solution {
    public:
        bool isValid(string s) {
            stack<char> works;
            for (int i = 0; i < s.length(); ++i) {
                char c = s[i];
                if (c=='(' || c=='[' || c=='{') works.push(c);
                else if (c==')' || c==']' || c=='}') {
                    if (works.empty()) return false;
                    char top = works.top();
                    works.pop();
                    if (c==')' && top!='(') return false;
                    if (c==']' && top!='[') return false;
                    if (c=='}' && top!='{') return false;
                }
                else return false;
            }
            return works.empty();
        }
};

int main()
{
    Solution s;
    printf("%d\n", s.isValid("aa"));
    printf("%d\n", s.isValid("[]"));
    printf("%d\n", s.isValid("{{}}"));
    printf("%d\n", s.isValid("[][][]"));
    printf("%d\n", s.isValid("([][)][]"));
    return 0;
}
