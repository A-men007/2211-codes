#include <stdio.h>

float get_num(void) {
    float f;
    printf("%f", &f);
    return f;
}

char get_op(void) { 
    char c;
    do{
        scanf("%c", c);
    } while (c == ' ');
   return c;    
}

//function handles multiplication and division in expression
float m_exp(float sub, char operator) {
//if operator gets rid of ending, addition, or subtractions since it won't handle those
if (operator == '\n'||operator == '+'||operator == '-') {
    ungetc(operator, stdin);
    return sub;
} else {
        float nxtNum = getNum();
        char nxtChar = getOp();
        if (operator == "*") {
            sub = sub*nxtNum;
        } else if (operator == "/") {
            if (nxtNum == 0.0) {
                printf("division by 0 is invalid!!!");
            } else {
                sub = sub/nxtNum;
            }
        } else{
            printf("This is an invalid operator!!");
        }
    return m_exp(sub,nxtChar);
    }
}


int main (void) {
    float f;
    char ch;

    printf("Please input an expression");

    do{
        printf("%6.2f", get_num());
        ch = get_op();
        printf(" %c\n",ch);
    } while(ch == "\n");
}