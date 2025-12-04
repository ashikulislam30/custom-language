# custom-language
# Ashik's Easy Language (AEL)

A simple custom programming language created by Md. Ashikul Islam to perform basic mathematical operations, handle variables, and show results based on user input. This language supports different data types like real numbers, dosomik numbers (probably for some custom number format), and characters, along with a simple command syntax to handle variable declarations, arithmetic expressions, and outputs.

## Features

- **Variable Declaration**: You can define variables with types such as `realnumber`, `dosomiknumber`, and `character`.
- **Mathematical Operations**: Supports basic arithmetic operations such as addition, subtraction, multiplication, and division.
- **Variable Manipulation**: Supports the creation, updating, and retrieval of variable values.
- **Show Command**: The `show` command displays the value of a variable or an expression.
- **Input Parsing**: Handles expressions with variables and constants, including mathematical calculations.
- **Custom Data Types**: Handles custom types, including characters (e.g., `char` type for single characters).

## Supported Commands

1. **Variable Declaration and Assignment**:
    - Supported types: `realnumber`, `dosomiknumber`, `character`
    - Example:
      ```plaintext
      realnumber x = 5;
      dosomiknumber y = 3.14;
      character letter = 'A';
      ```

2. **Show Command**:
    - To display the value of a variable or an expression.
    - Example:
      ```plaintext
      show x;          // Output: 5
      show x + y;      // Output: 8.14
      show "Hello";    // Output: Hello
      ```

3. **Mathematical Expressions**:
    - You can perform arithmetic operations with the variables defined.
    - Supported operations: `+`, `-`, `*`, `/`
    - Example:
      ```plaintext
      realnumber result = x + y * 2;
      show result;     // Output: 11.28
      ```

4. **Character Handling**:
    - You can assign a single character to a variable.
    - Example:
      ```plaintext
      character letter = 'A';
      show letter;     // Output: A
      ```

5. **Error Handling**:
    - The language provides error messages if the user tries to divide by zero or uses invalid syntax.

## Data Types

- **realnumber**: A floating-point number, e.g., `5.4`, `10`, `3.14`
- **dosomiknumber**: A custom number type, which can be a floating-point number.
- **character**: A single character enclosed in single quotes, e.g., `'A'`, `'X'`.

## How to Use

1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/ashiks-easy-language.git
