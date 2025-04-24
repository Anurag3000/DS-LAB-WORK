#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    public:
        char arr[MAX];
        int top = -1;
    
        void push(char c) {
            if (top < MAX - 1) arr[++top] = c;
        }
    
        char pop() {
            if (top >= 0) return arr[top--];
            return '\0';
        }
    
        char peek() {
            if (top >= 0) return arr[top];
            return '\0';
        }
    
        bool isEmpty() {
            return top == -1;
        }
    };
    

//agar operand hay to simply return kardo, stack may nhi dalna
bool isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void reverse(char expr[]) {
    int n = 0;
    while (expr[n] != '\0') n++;

    for (int i = 0; i < n / 2; ++i) {
        char temp = expr[i];
        expr[i] = expr[n - i - 1];
        expr[n - i - 1] = temp;
    }
}

void infixToPostfix(char infix[], char postfix[]) {
    Stack st;
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char c = infix[i];
        if (isOperand(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(')
                postfix[j++] = st.pop();
            st.pop(); // pop '('
        } else { // operator
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(c))
                postfix[j++] = st.pop();
            st.push(c);
        }
        i++;
    }

    while (!st.isEmpty())
        postfix[j++] = st.pop();

    postfix[j] = '\0';
}

void infixToPrefix(char infix[], char prefix[]) {
    reverse(infix);

    for (int i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(') infix[i] = ')';
        else if (infix[i] == ')') infix[i] = '(';
    }

    char temp[MAX];
    infixToPostfix(infix, temp);
    reverse(temp);

    int i = 0;
    while (temp[i] != '\0') {
        prefix[i] = temp[i];
        i++;
    }
    prefix[i] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX], prefix[MAX];

    cout << "Enter infix expression: ";
    cin >> infix;

    infixToPostfix(infix, postfix);
    infixToPrefix(infix, prefix);

    cout << "Postfix: " << postfix << endl;
    cout << "Prefix: " << prefix << endl;

    return 0;
}
