#include <ctype.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// トークンの種類
typedef enum {
  TK_RESERVED,  // 記号
  TK_NUM,       // 整数トークン
  TK_EOF,       // 入力の終わりを表すトークン
} TokenKind;

// トークン型
typedef struct Token Token;
struct Token {
  TokenKind kind;  // トークンの型
  Token *next;     // 次の入力トークン
  int val;         // kindがTK_NUMの場合、その数値
  char *str;       // トークン文字列
  int len;         // トークンの長さ
};

void error_at(char *loc, char *fmt, ...);
bool consume(char *op);
void expect(char *op);
int expect_number();
Token *tokenize();

// 現在着目しているトークン
Token *token;

// 入力プログラム
char *user_input;

// 抽象構文木のノードの種類
typedef enum {
  ND_ADD,  // +
  ND_SUB,  // -
  ND_MUL,  // *
  ND_DIV,  // /
  ND_EQ,   // ==
  ND_NE,   // != Not Equal
  ND_LT,   // <
  ND_LE,   // <=
  ND_NUM,  // 整数
} NodeKind;

typedef struct Node Node;
// 抽象構文木のノードの型
struct Node {
  NodeKind kind;  // ノードの型
  Node *lhs;      // 左辺 left-hand side
  Node *rhs;      // 右辺 right-hand side
  int val;        // kindがND_NUMの場合のみ使用
};

Node *expr(void);

void codegen(Node *node);
