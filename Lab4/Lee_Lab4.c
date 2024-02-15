//
//  Lee_Lab4.c
//  
//
//  Created by Jihye Lee on 2/7/24.
//

#include "Lee_Lab4.h"

#include <stdio.h>
#include <stdlib.h> /* for atof(): converts the string argument str to a floating-point number (type double)*/
#include <ctype.h>

#define MAXOP 100 /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

# define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0; /* next free position in buf */

int getch(void){  /* get a (possibly pushed back) character */
    return (bufp > 0) ? buf[--bufp] : getchar(); // ?: conditional value
}

void ungetch(int c){ /* push character back on input */
    if (bufp >= BUFSIZE)
        printf("ungetch: to many characters\n");
    else
        buf[bufp++] = c;
}

/* getop: get next operator or numeric operand */
int getop(char s[]){
    int i, c;
    
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c; /* not a number */
    i = 0;
    if(isdigit(c))    /* collect integer part */
        while (isdigit(s[++i] = c = getch()));
    if (c =='.')   /* collect fraction part */
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}
#define MAXVAL 100
int sp = 0; /* next free stack position */
double val[MAXVAL]; /* value stack */

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n",f);
}

/* pop: pop and return top value from satck */
double pop(void){
    if (sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

/* reverse Polish calculator */
int main(){
    int type;
    double op2;
    char s[MAXOP];
    
    
    while ((type = getop(s)) != EOF){
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor \n");
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}


