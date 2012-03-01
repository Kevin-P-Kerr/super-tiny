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

void GetNum(void) {
	int i;
	i = 0;
	char numlist[100];
	while (IsDigit == 0) {
		numlist[i] = Look;
		i = ++i;
		GetChar();
}
	printf("%s  ", numlist);
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
// Put A Label
	void PutLabel(int lab) {
		printf(".L%d", lab);
}
// Place a Label and new line
	void PlaceLabel(int lab) {
		PutLabel(lab);
		printf("\n");
}

// Get A Lable
	int GetLabel(void) {
		int i = LabNum;
		LabNum = ++LabNum;
		return i;
}
		
// The Parser Proper
//Parse and Translate A Factor
void Factor(void) {
	printf("Factor\n");
	GetNum();
}
//Parse and Translate a Mulop
void MulOp(void) {
	 if (Look == '*') {
		Match('*');
		Factor();
		printf("multiply stuff\n");
}
	else if (Look == '/') {
		Match('/');
		Factor();
		printf("divide stuff\n");
}
}
//Parse and Translate A Term
void Term(void) {
	printf("Term");
	Factor();
	if ((Look == '*') || (Look == '/')) 
		MulOp();
}	

// Parse and Translate An AddOp
void AddOp(void) {
	if (Look == '+') {
		Match('+');
		Term();	
		printf("addstuff\n");
		GetChar();
}
	else if (Look == '-') {
		Match('-');
		Term();
		printf("substract stuff");
		GetChar();
}
}
			

// Parse and Translate A Expression
void Expression(void) {
	printf("Expression\n");
	Term();
	if ((Look == '+') || (Look =='-'))
		AddOp();
}


void Relation(void) {
	printf("Relation\n");
	Expression();
	Match('q');
	Expression();
}


// Parse and Translate A Boolean Factor
void BoolFactor(void) {
	if (Look == 'T') {
		Match('T');
}
	else if (Look == 'F') {
		Match('F');
}
	else
		Relation();
}

//Parse and Translate A Not Factor
void NotFactor(void) {
	if (Look == '~') {
		Match('~');
		BoolFactor();
;
}
	else
		BoolFactor();
}
// Parse and Translate a Boolean  And Operation
void AndOp(void) {
	Match('&');
	NotFactor();

}



// Parse and Translate a Boolean Term
void BoolTerm(void) {
	NotFactor();
	if (Look == '&') 
		AndOp();
}

// Parse and Translate A Boolean OR
	void OrOp(void) {
		Match('|');
		BoolTerm();
	
}	


//Parse and Translate a Boolean Expression
	void BoolExpression(void) {
		BoolTerm();
		if (Look == '|') {
			OrOp();
}
}


// Parse and Translate Variables 
	void Variables(void) {
		int offset;
		int i;
		i = 0;
		Match('v');
		while(Look != 'e') {
			VarList[i] = Look;
			i = ++i;
			GetChar();
}
		offset = ((4 * i) + 4);
		Match('e');
		
}

// Parse and Translate an IF statement
	void DoIf(void) {
		int lab;
		lab = GetLabel();
		Match('i');
		BoolExpression();
		PlaceLabel(lab);
		while (Look != 't') 
			GetChar();
		Match('l');
		Block();
		PlaceLabel(lab);
		Match('e');
}
// Parse and Translate a While Statement
	void DoWhile(void) {
		int lab;
		int scndlab;
		lab = GetLabel();
		scndlab = GetLabel();
		Match('w');
		PlaceLabel(lab);
		BoolExpression();
		PlaceLabel(scndlab);
		Block();
		printf("\tjmp");
		PlaceLabel(lab);
		PlaceLabel(scndlab);
		Match('e');
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
	//	else if (Look == 'f')
	//		DoFor();
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
