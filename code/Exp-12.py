class CodeGenerator:
    def __init__(self):
        self.code = []

    def emit(self, instruction):
        self.code.append(instruction)

    def generate_code(self, ast):
        if isinstance(ast, int):
            self.emit(f"MOV R1, {ast}")
        elif isinstance(ast, str):
            self.emit(f"MOV R1, {ast}")
        elif isinstance(ast, tuple):
            op, left, right = ast
            self.generate_code(left)
            self.emit(f"MOV R2, R1")
            self.generate_code(right)
            if op == '+':
                self.emit("ADD R1, R2, R1")
            elif op == '-':
                self.emit("SUB R1, R2, R1")
            elif op == '*':
                self.emit("MUL R1, R2, R1")
            elif op == '/':
                self.emit("DIV R1, R2, R1")

# Function to parse the arithmetic expression
def parse_expression(expression):
    # Implementation of your parsing logic goes here
    # For simplicity, let's assume the expression is already parsed into an AST
    return ('+', 3, ('*', 4, 5))  # Example AST for "3 + 4 * 5"

expression = input("Enter an arithmetic expression: ")
ast = parse_expression(expression)

generator = CodeGenerator()
generator.generate_code(ast)

print("Generated Code:")
for instruction in generator.code:
    print(instruction)
