/* In any language program mostly syntax error occurs due to unbalancing delimiter such as
(),{},[]. Write C++ program using stack to check whether given expression is well
parenthesized or not. */

#include<iostream>
#include<string>    
using namespace std;
#define MAX 1000

class Stack
{
    private:
        char arr[MAX];
        int top;

    public:
        Stack() {
            top = -1;
        }

        bool push(char ch) {
            if(top >= MAX-1) {
                cout<<"Stack Overflow"<<endl;
                return false;
            }
            arr[++top]=ch;
            return true;
        }

        bool pop() {
            if(top==-1){
                cout<<"Stack Underflow"<<endl;
                return false;
            }
            top--;
            return true;
        }

        char peek() {
            if(top==-1) {   
                return '\0';
            }
            return arr[top];
        }

        bool isEmpty() {
            return (top==-1);
        }

};

bool iswellparenthesized(const string& expression) 
{
    Stack s;

    for(int i=0 ; i<expression.length() ; i++ ) {
        char ch = expression[i];

        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.isEmpty()) {
                return false;
            }
            char top=s.peek();
            s.pop();

            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '[') )
            {
                return false;
            }
        }
    }
    return s.isEmpty();
}

int main() {
    string expression;
    cout<<"Enter An Expression"<<endl;
    cin>>expression;

    if(iswellparenthesized(expression)) {
        cout<<"The Expression Is Well Parenthesized"<<endl;
    }
    else {
        cout<<"The Expression Is Not Well Parenthesized"<<endl;
    }

    return 0;
}