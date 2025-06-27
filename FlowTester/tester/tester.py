functions = []

with open("../program/main.cpp", "r") as file:
    content = file.read().splitlines()
#print(content)

function_str = ""
for index, line in enumerate(content):
    if "()" in line and "{" in content[index + 1]:
        function_str = ""
        while()
    else:
        function_str += line.strip()
        functions.append(function_str)
print(functions)