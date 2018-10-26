#include<stdio.h>
#include<vector>
#include<stack>
#include<string>
using namespace std;

class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> works;
            for (int i  = 0; i < tokens.size(); ++i) {
                const string& s = tokens[i];
                if (s.length() == 1) {
                    int a;
                    int b;
                    switch (s.c_str()[0]) {
#define GETVALUES b = works.top(); works.pop(); a = works.top(); works.pop();
#define SETVALUE(x) works.push(x);
                        case '+':
                            GETVALUES;
                            SETVALUE(a+b);
                            break;
                        case '-':
                            GETVALUES;
                            SETVALUE(a-b);
                            break;
                        case '*':
                            GETVALUES;
                            SETVALUE(a*b);
                            break;
                        case '/':
                            GETVALUES;
                            SETVALUE(a/b);
                            break;
                        default:
                            SETVALUE(stoi(s));
                            break;
                    }
                } else {
                    SETVALUE(stoi(s));
                }
            }
            return works.top();
        }
};

int main()
{
    vector<string> in;
    Solution s;
#if 0
    in.push_back("2");
    in.push_back("1");
    in.push_back("+");
    in.push_back("3");
    in.push_back("*");
#endif
#if 1
    in.push_back("4");
    in.push_back("13");
    in.push_back("5");
    in.push_back("/");
    in.push_back("+");
#endif

    printf("%d\n", s.evalRPN(in));
    return 0;
}
