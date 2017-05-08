grammar Aileen;

// Parser rules

compilation_unit
  : function_definition*
  ;

function_definition
  : 'function' IDENTIFIER '(' parameters? ')' ('->' return_type)? block
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
  : '{' statement_list '}'
  ;

statement_list
  : (statement)*
  ;

statement
  : 'return' expression? ';'
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
  : 'boolean'
  | 'character'
  | 'i8'
  | 'i16'
  | 'i32'
  | 'i64'
  | 'u8'
  | 'u16'
  | 'u32'
  | 'u64'
  | 'f32'
  | 'f64'
  ;

// Lexer rules

KEYWORD_FUNCTION  : 'function';
KEYWORD_RETURN    : 'return';
KEYWORD_BOOLEAN   : 'boolean';
KEYWORD_CHARACTER : 'character';
KEYWORD_I8        : 'i8';
KEYWORD_I16       : 'i16';
KEYWORD_I32       : 'i32';
KEYWORD_I64       : 'i64';
KEYWORD_U8        : 'u8';
KEYWORD_U16       : 'u16';
KEYWORD_U32       : 'u32';
KEYWORD_U64       : 'u64';
KEYWORD_F32       : 'f32';
KEYWORD_F64       : 'f64';

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
  : '0'
  | [+-]? NON_ZERO_DIGIT DECIMAL_DIGIT*
  ;

HEXADECIMAL_INTEGER_LITERAL
  : '0x' [0-9a-fA-F]+
  ;

BINARY_INTEGER_LITERAL
  : '0b' [01]+
  ;

FLOAT_LITERAL
  : '0.0'
  | [+-]? DECIMAL_INTEGER_LITERAL '.' DECIMAL_INTEGER_LITERAL
  ;

IDENTIFIER
  :  LETTER (LETTER | DECIMAL_DIGIT)*
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

fragment LETTER
  : [a-zA-Z]
  ;

fragment DECIMAL_DIGIT
  : [0-9]
  ;

fragment NON_ZERO_DIGIT
  : [1-9]
  ;
