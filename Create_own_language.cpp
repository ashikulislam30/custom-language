#include<bits/stdc++.h>
using namespace std;

// Structure to store variable data
struct Variable {
    string name;   // Variable name
    string type;   // Type: realnumber, dosomiknumber, character
    union {
        double fvalue;  // For numbers
        char cvalue;    // For characters
    };
};

// List to store all defined variables
vector<Variable> variablesList;

// Remove spaces from both ends
void trim(string &text) {
    size_t start = text.find_first_not_of(" \t\r\n");
    size_t end = text.find_last_not_of(" \t\r\n");
    if (start == string::npos) {
        text = "";
    } else {
        text = text.substr(start, end - start + 1);
    }
}

// Find a variable by name
Variable* findVariableByName(const string &name) {
    for (auto &v : variablesList) {
        if (v.name == name) {
            return &v;
        }
    }
    return nullptr;
}

// Add or update a variable
void addVariable(string name, string type, string valueStr) {
    Variable newVar;
    newVar.name = name;
    newVar.type = type;

    if (type == "character") {
        // Must be in the form 'X'
        if (valueStr.size() == 3 && valueStr[0] == '\'' && valueStr[2] == '\'') {
            newVar.cvalue = valueStr[1];
        } else {
            cout << "Error: Invalid character. Use single quotes like 'A'." << endl;
            return;
        }
    } else {
        // Convert string to double
        newVar.fvalue = stod(valueStr);
    }

    // Update if exists, else add new
    Variable* existing = findVariableByName(name);
    if (existing) {
        *existing = newVar;
    } else {
        variablesList.push_back(newVar);
    }
}

// Get numeric value of a variable
double getValue(string varName) {
    trim(varName);
    Variable* var = findVariableByName(varName);
    if (!var) {
        cout << "Error: Variable '" << varName << "' not found." << endl;
        exit(1);
    }
    if (var->type == "character") {
        cout << "Error: Cannot use character in calculations." << endl;
        exit(1);
    }
    return var->fvalue;
}

// Evaluate a math expression with one operator type
double evaluateExpression(string expr, char op) {
    stringstream ss(expr);
    string part;
    double result = 0;
    bool first = true;

    while (getline(ss, part, op)) {
        trim(part);
        double value = getValue(part);

        if (first) {
            result = value;
            first = false;
        } else {
            if (op == '+') result += value;
            else if (op == '-') result -= value;
            else if (op == '*') result *= value;
            else if (op == '/') {
                if (value == 0) {
                    cout << "Error: Division by zero!" << endl;
                    exit(1);
                }
                result /= value;
            }
        }
    }

    return result;
}

// Check if it's a string in quotes
bool isStringLiteral(string text) {
    return text.length() >= 2 && text.front() == '"' && text.back() == '"';
}

// Run one line of code
void executeLine(string line) {
    trim(line);

    // Handle show statement
    if (line.substr(0, 4) == "show") {
        string expr = line.substr(5);
        trim(expr);

        if (isStringLiteral(expr)) {
            cout << expr.substr(1, expr.length() - 2) << endl;
        } else if (expr.find('+') != string::npos) {
            cout << evaluateExpression(expr, '+') << endl;
        } else if (expr.find('-') != string::npos) {
            cout << evaluateExpression(expr, '-') << endl;
        } else if (expr.find('*') != string::npos) {
            cout << evaluateExpression(expr, '*') << endl;
        } else if (expr.find('/') != string::npos) {
            cout << evaluateExpression(expr, '/') << endl;
        } else {
            cout << getValue(expr) << endl;
        }
    }
    // Handle variable declaration
    else if (line.find("realnumber ") == 0 || line.find("dosomiknumber ") == 0 || line.find("character ") == 0) {
        stringstream ss(line);
        string type, name, equalSign, value;
        ss >> type >> name >> equalSign;
        getline(ss, value, ';');
        trim(value);

        // Check if expression
        if (value.find_first_of("+-*/") != string::npos && type != "character") {
            char op = (value.find('+') != string::npos) ? '+' :
                      (value.find('-') != string::npos) ? '-' :
                      (value.find('*') != string::npos) ? '*' : '/';

            double result = evaluateExpression(value, op);
            addVariable(name, type, to_string(result));
        } else {
            addVariable(name, type, value);
        }
    } else {
        cout << "Error: Invalid command." << endl;
    }
}

int main() {
    string line;

    cout << "Welcome to Ashik's Easy Language!" << endl;
    cout << "Type your commands below (type EXIT to stop):" << endl;

    while (true) {
        cout << "> ";
        getline(cin, line);

        if (line == "EXIT") {
            cout << "Goodbye!" << endl;
            break;
        }

        executeLine(line);
    }

    return 0;
}
