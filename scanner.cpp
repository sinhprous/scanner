// dong goi SinhNB.zip
// deadline 11h59 chu nhat 2/10/2017 gmt+7
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#include "scanner.h"

;char ch;

int Num;
char Id[MAX_IDENT_LEN + 1];

TokenType getToken(){
    // spaces
    if (ch == ' ' || ch == '\n' || ch == '\t') {
        while (ch == ' ' || ch == '\n' || ch == '\t') ch = getchar();
    }
    // ident
    if (isalpha(ch)) {
        int i = 0;
        while (isalpha(ch) || isdigit(ch) && i < MAX_IDENT_LEN){
            Id[i] = ch;
            ++i;
            ch = getchar();
        }
        if (i == MAX_IDENT_LEN) return NONE;
        Id[i] = '\0';
        for (int i = 0; i < KEYWORDS_COUNT; ++i){
            if (strcmpi(keywords[i].string, Id) == 0) return keywords[i].Token;
        }
        return IDENT;
    }
    // number
    if (isdigit(ch)) {
        while (isdigit(ch)) ch = getchar();
        return NUMBER;
    }
    // plus
    if (ch == '+') {
        ch = getchar();
        return PLUS;
    }
    // minus
    if (ch == '-') {
        ch = getchar();
        return MINUS;
    }
    // times
    if (ch == '*') {
        ch = getchar();
        return TIMES;
    }
    // slash
    if (ch == '/') {
        ch = getchar();
        return SLASH;
    }
    // equ
    if (ch == '=') {
        ch = getchar();
        return EQU;
    }
    // neq, leq, lss
    if (ch == '<') {
        ch = getchar();
        if (ch == '>') {
            ch = getchar();
            return NEQ;
        } else if (ch == '=') {
            ch = getchar();
            return LEQ;
        } else return LSS;
    }
    // geq, gtr
    if (ch == '>') {
        ch = getchar();
        if (ch == '=') {
            ch = getchar();
            return GEQ;
        } else return GTR;
    }
    // percent
    if (ch == '%') {
        getchar();
        return PERCENT;
    }
    // period
    if (ch == '.') {
        ch = getchar();
        return PERIOD;
    }
    // parent
    if (ch == '(') {
        ch = getchar();
        return LPARENT;
    }
    if (ch == ')') {
        ch = getchar();
        return RPARENT;
    }
    // brack
    if (ch == '[') {
        ch = getchar();
        return LPARENT;
    }
    if (ch == ']') {
        ch = getchar();
        return RPARENT;
    }
    // comma
    if (ch == ','){
        ch = getchar();
        return COMMA;
    }
    // semicolon
    if (ch == ';'){
        ch = getchar();
        return SEMICOLON;
    }
    // assign
    if (ch == ':'){
        ch = getchar();
        if (ch == '=') {
            ch = getchar();
            return ASSIGN;
        }
        else return NONE;
    }
    ch = getchar();
    return NONE;
}

int main(){
    freopen("test.PL0", "r", stdin);
    ch = ' ';
    while (true) {
        TokenType t = getToken();
        printf("%s\n", token_names[t]);
        if (t == NONE || t == PERIOD) break;
    }
    return 0;
}
