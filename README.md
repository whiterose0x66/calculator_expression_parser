# Calculator Expression Parser (C++)

A small calculator expression parser written in C++ that evaluates mathematical expressions using **tokenization**, **infix-to-postfix translation**, and **postfix evaluation**.

## Features

- Supports:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`) — integer division only
  - Parentheses (`(` `)`)

## Limitations

- No unary minus support (`-5` is not handled as a negative number)
- Integer-only arithmetic
- No floating-point numbers
- Input should not contain malformed expressions

---

# How It Works

This project follows three classical steps used in expression parsing:

## 1. Tokenizer

The tokenizer extracts tokens from the input string, ignores spaces, and separates:

- Numbers
- Operators
- Parentheses

### Example:
```txt
Input:  (12+3)*4
Tokens: [ ( 12 + 3 ) * 4 ]
```

### 2. Infix to Postfix Translator

This step converts the infix expression into postfix notation (Reverse Polish Notation) using a stack and operator precedence rules.

#### Operator precedence:
- `*` `/` → higher priority
- `+` `-` → lower priority
- `(` `)` → control flow

### Why postfix notation?

Postfix expressions are:
- Easier to evaluate
- Free of parentheses
- Common in compilers and virtual machines

### Example:
```txt
Input:  [ ( 12 + 3 ) * 4 ]
postfix: [12 3 + 4 *]
```

### 3. Postfix Evaluation

The postfix expression is evaluated using a stack:

#### Rules:
- If token is a number → push it to stack
- If token is an operator → pop two values, apply operation, push result
