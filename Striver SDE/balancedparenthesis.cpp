class Solution {
public:
    bool isValid(std::string str) {
        std::stack<char> parenthesesStack;
        
        for (char x : str) {
            if (x == '(' || x == '{' || x == '[') {
                parenthesesStack.push(x);
            } else {
                if (parenthesesStack.empty()) {
                    return false;
                }
                
                if (!matching(parenthesesStack.top(), x)) {
                    return false;
                } else {
                    parenthesesStack.pop();
                }
            }
        }
        
        return parenthesesStack.empty();
    }

private:
    bool matching(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }
};
