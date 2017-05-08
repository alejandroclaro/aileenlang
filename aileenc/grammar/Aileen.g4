grammar Aileen;

// Parser rules

compilation_unit
  : function_definition*
  ;

function_definition
  : KEYWORD_FUNCTION IDENTIFIER '(' parameters? ')' ('->' return_type)? block
  ;

parameters
  : parameter (',' parameter)*
  ;

parameter
  : IDENTIFIER ':' parameter_type
  ;

return_type
  : primitive_type
  ;

parameter_type
  : primitive_type
  ;

block
  : '{' binding_declaration_list statement_list '}'
  ;

binding_declaration_list
  : (binding_declaration)*
  ;

statement_list
  : (statement)*
  ;

statement
  : return_statement
  ;

return_statement
  : KEYWORD_RETURN expression? ';'
  ;

binding_declaration
  : constant_binding_declaration
  | variable_binding_declaration
  ;

constant_binding_declaration
  : 'const' IDENTIFIER (':' parameter_type)? KEYWORD_ASSIGNMENT expression ';'
  ;

variable_binding_declaration
  : 'var' (':' parameter_type)? KEYWORD_ASSIGNMENT expression ';'
  ;

expression
  : literal
  ;

literal
  : BOOLEAN_LITERAL
  | CHARACTER_LITERAL
  | INTEGER_LITERAL
  | FLOAT_LITERAL
  ;

primitive_type
  : KEYWORD_BOOLEAN
  | KEYWORD_CHARACTER
  | KEYWORD_I8
  | KEYWORD_I16
  | KEYWORD_I32
  | KEYWORD_I64
  | KEYWORD_U8
  | KEYWORD_U16
  | KEYWORD_U32
  | KEYWORD_U64
  | KEYWORD_F32
  | KEYWORD_F64
  ;

// Lexer rules

KEYWORD_FUNCTION   : 'function';
KEYWORD_RETURN     : 'return';
KEYWORD_BOOLEAN    : 'bool';
KEYWORD_CHARACTER  : 'char';
KEYWORD_I8         : 'i8';
KEYWORD_I16        : 'i16';
KEYWORD_I32        : 'i32';
KEYWORD_I64        : 'i64';
KEYWORD_U8         : 'u8';
KEYWORD_U16        : 'u16';
KEYWORD_U32        : 'u32';
KEYWORD_U64        : 'u64';
KEYWORD_F32        : 'f32';
KEYWORD_F64        : 'f64';
KEYWORD_ASSIGNMENT : '=';

BOOLEAN_LITERAL
  : 'true'
  | 'false'
  ;

CHARACTER_LITERAL
  : '\'' SINGLE_CHARACTER '\''
  ;

INTEGER_LITERAL
  : DECIMAL_INTEGER_LITERAL
  | HEXADECIMAL_INTEGER_LITERAL
  | BINARY_INTEGER_LITERAL
  ;

DECIMAL_INTEGER_LITERAL
  : '-'? NONNEGATIVE_INTEGER EXPONENT
  | '-'? NONNEGATIVE_INTEGER
  ;

HEXADECIMAL_INTEGER_LITERAL
  : '0x' (HEXADECIMAL_DIGIT HEXADECIMAL_DIGIT)+
  ;

BINARY_INTEGER_LITERAL
  : '0b' [01]+
  ;

FLOAT_LITERAL
  : '0.0'
  | '-'? NONNEGATIVE_INTEGER '.' [0-9]+ EXPONENT?
  ;

STRING_LITERAL
 : '"' (ESCAPED_CHARACTER | ~ ["\\])* '"'
 ;

IDENTIFIER
  : LETTER (LETTER | [0-9])*
  ;

BLOCK_COMMENT
  : '/*' .*? '*/' -> channel(HIDDEN)
  ;

LINE_COMMENT
  : '//' ~[\r\n]* -> channel(HIDDEN)
  ;

WHITE_SPACES
  : [ \t\n\r]+ -> skip
  ;

fragment SINGLE_CHARACTER
  : ~['\\\r\n]
  ;

fragment ESCAPED_CHARACTER
  : '\\' (["\\/bfnrt] | UNICODE_CHARACTER)
  ;

fragment UNICODE_CHARACTER
  : 'u' HEXADECIMAL_DIGIT HEXADECIMAL_DIGIT HEXADECIMAL_DIGIT HEXADECIMAL_DIGIT
  ;

fragment HEXADECIMAL_DIGIT
  : [0-9a-f]
  ;

fragment LETTER
  : [a-zA-Z]
  ;

fragment NONNEGATIVE_INTEGER
  : '0' | [1-9] [0-9]*
  ;

fragment EXPONENT
  : [e] [+-]? NONNEGATIVE_INTEGER
  ;
