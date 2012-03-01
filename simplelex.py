# SIMPLE: A Simple Programming Language I Am Designing

keywords = ('IF', 'THEN', 'ELSE' )
tokens = keywords +  ('ID','PLUS', 'NUMBER', 'MINUS', 'TIMES', 'DIVIDE', 'RPAREN', 'LPAREN', 'LT', 'GT', 'EQ', 'NE', 'LE', 'GE', 'AND', 'OR', 'NOT')

# tokens

t_ID = r'[a-zA-Z_][a-zA-Z0-9_]*'
t_PLUS = r'\+'
t_MINUS = r'-'
t_TIMES = r'\*'
t_DIVIDE = r'/'
t_RPAREN = r'\('
t_LPAREN = r'\)'
t_LT = r'<'
t_GT = r'>'
t_EQ = r'='
t_NE = r'!='
t_LE = r'<='
t_GE = r'>='
t_AND = r'&'
t_OR = r'\|'
t_NOT = r'!!'

def t_NUMBER(t):
	r'\d+'
	t.value = int(t.value)
	return t

# ignored characters

def t_newline(t):
	r'\n+'
	t.lexer.lineno += t.value.count("\n")

def t_error(t):
	print("Illegal Character, %s" % t.value[0])
	t.lex.skip(1)

# build the lexer

import ply.lex as lex
lex.lex()

# precedence rules

precedence = (
		('left', 'PLUS', 'MINUS', 'TIMES', 'DIVIDE'),
#		('right', 'UMINUS'),
		)

# dictionary of ids

ids = {}

def p_statement_assign(p):
	'statement : ID EQ expr' 
	ids[p[1]] = p[3]

def p_statement_if(p):
	'statement : IF boolexpr THEN statement ELSE statement'
	if p[2] == 0 : p[0] = p[6]
	elif p[2] == 1 : p[0] = p[4]

def p_statement_expr(p):
	'statement : expr'
	print(p[1])




def p_boolexpr(p):
	'''boolexpr : relexpr AND relexpr
		    | LPAREN boolexpr RPAREN 
	if p[1] == 1 and p[3] == 1 : p[0] = 1

	

def p_relexpr_lt(p):
	'relexpr : expr LT expr'
	if p[1] < p[3] : p[0] == 1
	else:
		p[0] == 0

def p_relexpr_gt(p):
	'relexpr : expr GT expr'
	if p[1] > p[3] : p[0] == 1
	else:
		p[0] == 0

def p_relexpr_eq(p):
	'relexpr : expr EQ expr'
	if p[1] == p[3] : p[0] == 1
	else:
		p[0] == 0

def p_relexpr_neq(p):
	'relexpr : expr NE expr'
	if p[1] == p[3] : p[0] == 0
	else:
		p[0] == 1

def p_relexpr_le(p):
	'relexpr : expr LE expr'
	if p[1] <= p[0] : p[0] == 1
	else:
		p[0] == 0

def p_relexpr_ge(p):
	'relexpr : expr GE expr'
	if p[1] >= p[3] : p[0] == 1
	else:
		p[0] == 0

def p_expr_add(p):
	'expr : expr PLUS expr'
	p[0] = p[1] + p[3]

def p_expr_minus(p):
	'expr : expr MINUS expr'
	p[0] = p[1] - p[3]

def p_expr_times(p):
	'expr : expr TIMES expr'
	p[0] = p[1] * p[3]

def p_expr_divide(p):
	'expr : expr DIVIDE expr'
	p[0] = p[1] / p[3]

def p_expr_number(p):
	'expr : NUMBER'
	p[0] = p[1]

def p_expr_bool(p):
	'expr : boolexpr'
	p[0] = p[1]

def p_expr_id(p):
	'expr : ID'
	try:
		p[0] = ids[p[1]]
	except LookupError:
		print("UNDEFINED VARIABLE: %s" % p[1])
		p[0] = 0

def p_error(p):
	print("ERROR AT %s" % p.value)

import ply.yacc as yacc
yacc.yacc()

while 1:
	try: 
		s = raw_input('simple => ')
	except EOFError:
		break
	yacc.parse(s)

