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
