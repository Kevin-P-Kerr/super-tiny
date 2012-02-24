#include <stdio.h>
// IO Stuff Here
// The Lookahead Character
char Look;
// The Encoded Token This Should Be Global
char Token;
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
// The Parser Proper

// Parse and Translate Variables 
	void Variables(void) {
		Match('v');
		printf("variable stub\n");
		while (Look != 'e') {
			GetChar();
}
}
// Parse and Translate an IF statement
	void DoIf(void) {
		Match('i');
		printf("IF STUB\n");
		while (Look != 'l') 
			GetChar();
		Match('l');
		Block();
		Match('e');
}
// Parse and Translate a While Stateement
	void DoWhile(void) {
		Match('w');
		while (Look != 'e')
			GetChar();
		Block();
		Match('e');
}
// Parse and Translate a For Statement
	void DoFor(void) {
		Match('f');
		while (Look != 'e') 
			GetChar();
		Block();
		Match('e');
}
//Parse and Translate a Boolean Expression
	void BoolExpression(void) {
		printf("Here is a boolean expression\n");
		GetChar();
}

//Parse and Translate a Program Block
	void Block(void) {
		Match('b');
		if (Look == 'v')
			Variables();
		else if (Look == 'i')
			DoIf();
		else if (Look == 'w')
			DoWhile();
		else if (Look == 'f')
			DoFor();
		while (Look != 'e') 
			BoolExpression();
		Match('e');
}
// Init
	void Init(void) {
		GetChar();
}
			

// A program is an EOF, or it is a block
void DoProgram(void) {
	while (Look != 'e') 
		Block();
	printf("The program is finished");
}

// Main
 main() {
	Init();
	DoProgram();
}
