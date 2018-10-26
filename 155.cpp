class MinStack {
    stack<int> s;
    stack<int> min;
    public:
    /** initialize your data structure here. */
    MinStack() {

    }

    void push(int x) {
        s.push(x);
        if (min.empty()) {
            min.push(x);
        } else {
            int cur = min.top();
            if (x < cur) {
                min.push(x);
            } else {
                min.push(cur);
            }
        }
    }

    void pop() {
        s.pop();
        min.pop();
    }

    int top() {
        return s.top();
    }

    int getMin() {
        return min.top();
    }
};
