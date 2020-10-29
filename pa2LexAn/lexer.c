#include "lexer.h"

// Returns 'true' if the character is a DELIMITER. 
bool isDelim(char ch) 
{ 
	if (ch == ' ' || ch == '+' || ch == '-' || ch == '*' || 
		ch == '/' || ch == ',' || ch == ';' || ch == '>' || 
		ch == '<' || ch == '=' || ch == '(' || ch == ')' || 
		ch == '[' || ch == ']' || ch == '{' || ch == '}' ||
		ch == '\n'|| ch == ':' || ch == '\t'|| ch == '\r')
		return (true); 
	return (false); 
} 

// Returns 'true' if the character is an OPERATOR. 
bool isOp(char ch) 
{ 
	if (ch == '+' || ch == '-' || ch == '*' || 
		ch == '/' || ch == '>' || ch == '<' || 
		ch == '=' || ch == '(' || ch == ')' ||
		ch == ':' || ch == ';' || ch == ',' ||
		ch == '[' || ch == ']') 
		return (true); 
		if (ch+1 == '*')
		{
			return (false);
		}

return (false); 
} 

bool isOp2(char *str)
{
	if (!strcmp(str, ":="))
		return (true);
	return (false);
}


// Returns 'true' if the string is a VALID IDENTIFIER. 
bool vIdent(char *str) 
{ 
	if (str[0] == '0' || str[0] == '1' || str[0] == '2' || 
		str[0] == '3' || str[0] == '4' || str[0] == '5' || 
		str[0] == '6' || str[0] == '7' || str[0] == '8' || 
		str[0] == '9' || isDelim(str[0]) == true) 
		return (false); 
	return (true); 
} 

// Returns 'true' if the string is a KEYWORD. 
bool isKW(char *str) 
{ 
	if (!strcmp(str, "if") || !strcmp(str, "else") || 
		!strcmp(str, "while") || !strcmp(str, "do") || 
		!strcmp(str, "break") || !strcmp(str, "continue") 
		|| !strcmp(str, "int") || !strcmp(str, "in") 
		|| !strcmp(str, "double") || !strcmp(str, "float") 
		|| !strcmp(str, "return") || !strcmp(str, "char") 
		|| !strcmp(str, "case") || !strcmp(str, "char") 
		|| !strcmp(str, "sizeof") || !strcmp(str, "long") 
		|| !strcmp(str, "short") || !strcmp(str, "typedef") 
		|| !strcmp(str, "switch") || !strcmp(str, "unsigned") 
		|| !strcmp(str, "void") || !strcmp(str, "static") 
		|| !strcmp(str, "struct") || !strcmp(str, "goto")
		|| !strcasecmp(str, "integer") || !strcasecmp(str, "interface")
		|| !strcasecmp(str, "accessor") || !strcasecmp(str, "and")
		|| !strcasecmp(str, "array") || !strcasecmp(str, "begin")
		|| !strcasecmp(str, "bool") || !strcasecmp(str, "character") 
		|| !strcasecmp(str, "constant") || !strcasecmp(str, "elsif")
		|| !strcasecmp(str, "end") || !strcasecmp(str, "exit")
		|| !strcasecmp(str, "function") || !strcasecmp(str, "is")
		|| !strcasecmp(str, "module") || !strcasecmp(str, "loop")
		|| !strcasecmp(str, "mutator") || !strcasecmp(str, "natural")
		|| !strcasecmp(str, "null")|| !strcasecmp(str, "of")
		|| !strcasecmp(str, "or")|| !strcasecmp(str, "others")
		|| !strcasecmp(str, "out") || !strcasecmp(str, "positive")
		|| !strcasecmp(str, "procedure") || !strcasecmp(str, "range")
		|| !strcasecmp(str, "return") || !strcasecmp(str, "struct")
		|| !strcasecmp(str, "subtype") || !strcasecmp(str, "then")
		|| !strcasecmp(str, "type") || !strcasecmp(str, "when")
		|| !strcasecmp(str, "while")) 
		return (true); 
	return (false); 
} 

// Returns 'true' if the string is an INTEGER. 
bool isNL(char* str) 
{ 
	int i, len = strlen(str); 

	if (len == 0) 
		return (false); 
	for (i = 0; i < len; i++) 
	{ 
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9' && str[i] != 'A' && str[i] != 'B' 
			&& str[i] != 'C' && str[i] != 'D' && str[i] != 'E'
			&& str[i] != 'F' || (str[i] == '-' && i > 0))
			return (false); 
	} 
	return (true); 
} 

// Returns 'true' if the string is a REAL NUMBER. 
bool isRN(char* str) 
{ 
	int i, len = strlen(str); 
	bool hasDecimal = false; 

	if (len == 0) 
		return (false); 
	for (i = 0; i < len; i++) 
	{ 
		if (str[i] != '0' && str[i] != '1' && str[i] != '2'
			&& str[i] != '3' && str[i] != '4' && str[i] != '5'
			&& str[i] != '6' && str[i] != '7' && str[i] != '8'
			&& str[i] != '9' && str[i] != '.' || 
			(str[i] == '-' && i > 0)) 
			return (false); 
		if (str[i] == '.') 
			hasDecimal = true; 
	} 
	return (hasDecimal); 
} 

// Extracts the SUBSTRING. 
char* sStr(char* str, int left, int right) 
{ 
	int i; 
	char* subStr = (char*)malloc( sizeof(char) * (right - left + 2)); 

	for (i = left; i <= right; i++) 
		subStr[i - left] = str[i]; 
	subStr[right - left + 1] = '\0'; 
	return (subStr); 
} 

// Parsing the input STRING. 
void lex(char *str) 
{ 
	int left = 0, right = 0; 
	int len = strlen(str); 

	while (right <= len && left <= right) 
    { 
		if (isDelim(str[right]) == false) 
			right++;
		/* if a delimiter if found, check it against the operator table
		and print the operator character if found.*/
		if (isDelim(str[right]) == true && left == right) 
        { 
			if (isOp(str[right]) == true)
			{
				printf("%c (operator)\n", str[right]);
			}
			right++; 
			left = right; 
		}
        else if (isDelim(str[right]) == true && left != right 
				|| (right == len && left != right)) 
		{ 
				char *subStr = sStr(str, left, right - 1);

				if (isKW(subStr) == true) 
					printf("%s (keyword)\n", subStr); 
							
				else if (isNL(subStr) == true) 
					printf("%s (numeric literal)\n", subStr); 

				else if (isRN(subStr) == true) 
					printf("%s (realNum)\n", subStr); 

				else if (vIdent(subStr) == true
						&& isDelim(str[right - 1]) == false) 
					printf("%s (identifier)\n", subStr); 

				else if (vIdent(subStr) == false
						&& isDelim(str[right - 1]) == false) 
					printf("%s (unknown)\n", subStr); 
			left = right; 
		} 
	} 
	return; 
} 

