class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(char a:s){
            //if opening bracket=push in stack
            if(a=='(' || a=='{' || a=='['){
                st.push(a);
            }
            //if closing bracket
            else{
                //if empty means no opening bracket present= return false because if we add closing there will be  no matching opening for it ever
                if(st.empty()) return false;
                //now check for closing brackets and their respective opening brackets
                char c=st.top();
                if((a==')' && c=='(') || (a=='}' && c=='{') || (a==']' && c=='[')){
                    st.pop();
                }
                else{
                    return false;
                }
            }            
        }
        return st.empty();
    }
    
};
