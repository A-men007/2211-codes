#include <stdio.h>
#include <stdlib.h>

float m_exp(float sub_exp, char op); 

//used as a input retriever function
float get_num(void) {
    float num;
    scanf("%f", &num);
    return num;
}

//used as a input retriever function for operators
char get_op(void) { 
    char op;
    do {
        scanf("%c", &op);
    } while (op == ' ');
   return op;    
}

float s_exp() {
    float num = get_num();
    char l_op = get_op();
    if (l_op == '\n') {
         return num;
    }
    float result = m_exp(num, l_op);
    l_op = get_op();
    
    while (l_op != '\n'){

        if (l_op == '+') {
            num = get_num();
            l_op = get_op();
            result = result + m_exp(num, l_op);
        }
        else if (l_op == '-') {
            num = get_num();
            l_op = get_op();
            result = result - m_exp(num, l_op);
        }
        else {
            result = m_exp(num, l_op);
        }
        l_op = get_op();
    }
    return result;
}


float m_exp(float sub_exp, char op) {
float next_num;
char next_op;
//if operator gets rid of ending, addition, or subtractions since it won't handle those
if (op == '\n'||op == '+'||op == '-') {
    ungetc(op, stdin);
    return sub_exp;

} 
    float next_sub_exp;
    next_num = get_num();
    next_op = get_op();

    switch (op){  //if its multiply- multiply it
        case '*':
            next_sub_exp = next_num * sub_exp;
            break;
        case '/':   //if its division then divide it
            next_sub_exp = next_num/sub_exp;
            break;
        default:printf("Invalid operators\n");
            exit(EXIT_FAILURE);
    }
    return m_exp(next_sub_exp,next_op);
}

int main(void) {
    float ans;
    char ch;
    
    do{
        printf("Enter arithmetic expression:");
        ans = s_exp();
        printf("the result is: %0.2f\n", ans);
        printf("do you want to continue? (Y/N): ");
        scanf(" %c", &ch);
    } while (ch != 'N');
    return 0;
}