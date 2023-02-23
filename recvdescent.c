#include<stdio.h>
int i=0, t=1, f=0;
char str[20];
int S();
int L();
int A();
int main(){
    printf("the given grammar is:\n");
    printf("\nS -> (L)/a");
    printf("\nL -> SA/S");
    printf("\nA -> ,SA / $ ");
    /*printf(\nT' -> *FT'/$);
    printf("\nF -> (E)/a");*/
    printf("\nenter the string to be parrsed:");
    gets(str);
    if (S() && str[i]=='\0')
    printf("\ngiven string is accepted");
    else
    printf("the given string is not accepted");
    return 0;
}

int S(){
    if (str[i]=='a'){
        i++;
        return t;
    }
    else if(str[i]=='('){
        i++;
        if(L()){
            if (str[i]==')'){
                i++;
                return t;
            }
            else
            return f;
        }
        else
        return f;
    }
    else
    return f;
}

int L(){
    if (S()){
        if (str[i]=='\0')
        return t;
        if(A())
        return t;
        else
        return f;
    }
    else
    return f;
}

int A(){
    if(str[i]==','){
        i++;
        if(S()){
            if(A())
            return t;
            else
            return f;
        }
        else
        return f;
    }
}