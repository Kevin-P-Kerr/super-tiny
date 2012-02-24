#include <stdio.h>
// IO Stuff Here
// The Lookahead Character
int Look;
// The Encoded Token This Should Be Global
int Token;
// The Unencoded Token Not Sure If This Should Be Global
// char Value[];

void GetChar(void) {
	Look = getchar();
}

void Match(char c) {
	if (Look != c)
		printf("Expected %c\n, c");
	else
	   GetChar();
}

int IsAlph(void) {
	if (((Look <= 'z') && (Look >= 'a')) || ((Look <= 'Z') && (Look >= 'A'))) 
		return 0;	
	else
		return 1;
}

int IsDigit(void) {
	if ((Look <= '0') && (Look >= '9'))
		return 0;
	else
		return 1;
}

int IsAlphNum(void) {
	if ((IsAlph == '0') || (IsDigit == '0'))
		return 0;
	else
		return 1;
}

void GetString(char s[]) {
       int i = 0;
	while (IsAlphNum == '0') {
		s[i] = Look;
		i = ++i;
		GetChar();
}
}
void GetNum(char s[]) {
	int i = 0;
	while (IsDigit == '0') {
		s[i] = Look;
		i = ++i;
		GetChar();
}
}

int IsWhite(void) {
	if ((Look == ' ') || ((Look == '\t') || (Look == '\n')))
		return 0;
	else
		return 1;
}

void SkipWhite(void) {
	while (IsWhite == 0) {
		GetChar();
}
}
// Parse A Math Term
void Term(void) {
	Factor();
	if (Look == '*')
		Multiply();
	else if (Look == '/');
		Divide();
	


// Arithmetical Statements
// Parse An Addition Or Subtraction
void Add(void) {
		Match('+');
		Match('(');
		Expression();
		Match(')');
		printf("add %%eax, %%ebx\n");
}
		
void Subtract(void) {
	Match('-');
	Match('(');
	Expression();
	Match(')');
	printf("sub %%ebc, %%eax");

// Parse A Mathematical Expression
void Expression(void) {
	Term();
	if (Look == '+')
		AddOp;
	else if (Look == '-')
		Subtract();
}
}
