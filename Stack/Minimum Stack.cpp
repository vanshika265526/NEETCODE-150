class MinStack {
        stack<int> st;
        stack<int> minSt;
public:
    MinStack() {}
            
    void push(int val) {
        st.push(val); //pushing into the first stack
        if(minSt.empty() || minSt.top()>=val){
            minSt.push(val);
        }
    }
    void pop() {
        if(st.top()==minSt.top())
        {
            minSt.pop();
        }
        st.pop();
    }
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
    
};
