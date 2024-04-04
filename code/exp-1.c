#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_CODE_LENGTH 1000
#define MAX_TOKEN_LENGTH 100

// Token types
typedef enum {
    NUMBER,
    IDENTIFIER,
    ASSIGN,
    PLUS,
    MINUS,
    MULTIPLY,
    DIVIDE,
    LPAREN,
    RPAREN,
    NEWLINE,
    WHITESPACE,
    END_OF_FILE
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char value[MAX_TOKEN_LENGTH];
} Token;

// Function to tokenize the input code
Token* tokenize(const char* code) {
    Token* tokens = malloc(strlen(code) * sizeof(Token));
    if (!tokens) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    int i = 0;
    while (*code) {
        if (isspace(*code)) {
            code++;
            continue;  // Skip whitespace
        }
        if (isdigit(*code)) {
            char* start = code;
            while (isdigit(*code) || *code == '.') {
                code++;
            }
            int len = code - start;
            tokens[i].type = NUMBER;
            strncpy(tokens[i].value, start, len);
            tokens[i].value[len] = '\0';  // Null-terminate string
        } else if (isalpha(*code) || *code == '_') {
            char* start = code;
            while (isalnum(*code) || *code == '_') {
                code++;
            }
            int len = code - start;
            tokens[i].type = IDENTIFIER;
            strncpy(tokens[i].value, start, len);
            tokens[i].value[len] = '\0';  // Null-terminate string
        } else {
            switch (*code) {
                case '=':
                    tokens[i].type = ASSIGN;
                    strncpy(tokens[i].value, "=", 1);
                    break;
                case '+':
                    tokens[i].type = PLUS;
                    strncpy(tokens[i].value, "+", 1);
                    break;
                case '-':
                    tokens[i].type = MINUS;
                    strncpy(tokens[i].value, "-", 1);
                    break;
                case '*':
                    tokens[i].type = MULTIPLY;
                    strncpy(tokens[i].value, "*", 1);
                    break;
                case '/':
                    tokens[i].type = DIVIDE;
                    strncpy(tokens[i].value, "/", 1);
                    break;
                case '(':
                    tokens[i].type = LPAREN;
                    strncpy(tokens[i].value, "(", 1);
                    break;
                case ')':
                    tokens[i].type = RPAREN;
                    strncpy(tokens[i].value, ")", 1);
                    break;
                case '\n':
                    tokens[i].type = NEWLINE;
                    strncpy(tokens[i].value, "\n", 1);
                    break;
                default:
                    fprintf(stderr, "Illegal character: %c\n", *code);
                    exit(EXIT_FAILURE);
            }
            code++;
            tokens[i].value[1] = '\0';  // Null-terminate string
        }
        i++;
    }

    tokens[i].type = END_OF_FILE;
    tokens[i].value[0] = '\0';  // Null-terminate string

    return tokens;
}

// Function to free memory allocated for tokens
void free_tokens(Token* tokens) {
    free(tokens);
}

// Function to print token type
const char* token_type_to_string(TokenType type) {
    switch(type) {
        case NUMBER: return "NUMBER";
        case IDENTIFIER: return "IDENTIFIER";
        case ASSIGN: return "ASSIGN";
        case PLUS: return "PLUS";
        case MINUS: return "MINUS";
        case MULTIPLY: return "MULTIPLY";
        case DIVIDE: return "DIVIDE";
        case LPAREN: return "LPAREN";
        case RPAREN: return "RPAREN";
        case NEWLINE: return "NEWLINE";
        case WHITESPACE: return "WHITESPACE";
        case END_OF_FILE: return "END_OF_FILE";
        default: return "UNKNOWN";
    }
}

// Test the lexer
int main() {
    char code[MAX_CODE_LENGTH];
    printf("Enter code (max %d characters):\n", MAX_CODE_LENGTH - 1);
    if (fgets(code, MAX_CODE_LENGTH, stdin) == NULL) {
        fprintf(stderr, "Failed to read input\n");
        return EXIT_FAILURE;
    }

    Token* tokens = tokenize(code);
    for (int i = 0; tokens[i].type != END_OF_FILE; i++) {
        printf("Token: Type=%s, Value=%s\n", token_type_to_string(tokens[i].type), tokens[i].value);
    }
    free_tokens(tokens);

    return EXIT_SUCCESS;
}
