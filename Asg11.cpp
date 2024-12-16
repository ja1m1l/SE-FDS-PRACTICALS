#include <iostream>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

bool isOperand(char ch) {
    return isdigit(ch); 
}

int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        default: return 0;
    }
}

string infixToPostfix(const string& infix)
{
    stack<char> operators;
    string postfix;

    for (char ch : infix) 
    {
        if (isOperand(ch)) 
        {
            postfix += ch; 
        } 
        else if (ch == '(')
        {
            operators.push(ch);
        } 
        else if (ch == ')') 
        {
            while (!operators.empty() && operators.top() != '(') 
            {
                postfix += operators.top(); operators.pop();
            }
            operators.pop(); 
        } 
        else 
        {
            while (!operators.empty() && precedence(operators.top()) >= precedence(ch)) 
            {
                postfix += operators.top(); operators.pop();
            }
            operators.push(ch);
        }
    }

    while (!operators.empty())
    {
        postfix += operators.top(); operators.pop();
    }
    return postfix;
}

int evaluatePostfix(const string& postfix) 
{
    stack<int> operands;

    for (char ch : postfix) {
        if (isOperand(ch)) {
            operands.push(ch - '0'); 
        } else {
            int b = operands.top(); operands.pop();
            int a = operands.top(); operands.pop();
            operands.push(applyOperation(a, b, ch));
        }
    }
    return operands.top();
}

int main() {
    string infix;
    cout << "Enter infix expression: ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;

    int result = evaluatePostfix(postfix);
    cout << "Evaluation result: " << result << endl;

    return 0;
}