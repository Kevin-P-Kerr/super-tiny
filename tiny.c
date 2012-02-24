#include <stdio.h>
// The Lookahead Character
char Look;

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
	i = 0;
	while (IsAlphNum == '0') {
		s[i] = Look;
		i = ++i;
		GetChar();
}

void GetNum(char s[]) {
	i = 0;
	while (IsNum == '0') {
		s[i] = Look;
		i = ++i;
		GetChar();
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

	


