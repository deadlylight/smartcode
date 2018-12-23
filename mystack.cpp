class MyStack {
    queue<int> q;
    public:
        /** Initialize your data structure here. */
        MyStack() {

        }

        /** Push element x onto stack. */
        void push(int x) {
            q.push(x);
            int size = q.size();
            while(size > 1) {
                size--;
                int v = q.front();
                q.pop();
                q.push(v);
            }
        }

        /** Removes the element on top of the stack and returns that element. */
        int pop() {
            int v = q.front();
            q.pop();
            return v;
        }

        /** Get the top element. */
        int top() {
            return q.front();
        }

        /** Returns whether the stack is empty. */
        bool empty() {
            return p.empty();

        }
};
