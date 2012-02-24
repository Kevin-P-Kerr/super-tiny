#include <stdio.h>
// IO Stuff Here
// The Lookahead Character
char Look;
// The Encoded Token This Should Be Global
char Token;
// Variable List
char VarList[90];
// Label Number
int LabNum = 0;
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
// Put A Label
	void PutLabel(int lab) {
		printf("L:%d", lab);
}
// Get A Lable
	int GetLabel(void) {
		int i = LabNum;
		LabNum = ++LabNum;
		return i;
}
		
// The Parser Proper

// Parse and Translate Variables 
	void Variables(void) {
		int offset;
		int i;
		i = 0;
		Match('v');
		printf("\tpushl %%epb\n" "\tmovl %%esp, %%ebp\n");
		while(Look != 'e') {
			VarList[i] = Look;
			i = ++i;
			GetChar();
}
		offset = ((4 * i) + 4);
		printf("\tsubl $%d, %%esp\n", offset);
		Match('e');
		
}

// Parse and Translate an IF statement
	void DoIf(void) {
		int lab;
		lab = GetLabel();
		Match('i');
		BoolExpression();
		while (Look != 'l') 
			GetChar();
		Match('l');
		Block();
		PutLabel(lab);
		Match('e');
}
// Parse and Translate a While Statement
	void DoWhile(void) {
		Match('w');
		BoolExpression();
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
			

// A program is an 'e', or it is a block
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
