
OBJECTNAME = ""
TAB = "    "
HTab = 0
CPPTab = 0

HFile = 0
CPPFile = 0

IsDiscrete = False
IsContinous = False
IsNumeric = False

BooleanOperators = ["==", "!=", "<", ">", "<=", ">="]
MathOperators = ["+", "-", "*", "/", "%"]
OperatorTypes = ["float", "int", "std::string", "void*", "char*"]
ConversionTypes = ["toFloat", "toInt", "toString"]
ObjectChecks = ["IsDiscrete", "IsContinous", "IsNumeric"]

def getBool(Question):
    res = input(Question)
    if(res == 'y' or res == 'Y'):
        return True
    return False

def writeNextSection():
    global HFile
    global CPPFile
    HFile.write("//___________________________________\n\n")
    CPPFile.write("//___________________________________\n\n")

def functionH(functionName, returnType, args):
    global TAB
    global HFile
    function = TAB

    newFunction = ""
    if(returnType != ""):
        newFunction += (returnType + " ")
    newFunction += (functionName + "(" + args + ");")

    writeLines([newFunction], HFile, CPPTab)

def createFunctionBody(args):
    global TAB
    global CPPTab
    argTab = createTAB(CPPTab)
    body = ""
    for arg in args:
        body += (argTab + "\n")
    return body


def functionCPP(functionName, returnType, args, body):
    global CPPTab
    global CPPFile
    global OBJECTNAME

    newFunction = ""
    if(returnType != ""):
        newFunction += (returnType + " ")
    newFunction += (OBJECTNAME + "::" + functionName + "(" + args + "){")

    writeLines([newFunction], CPPFile, CPPTab)
    writeLines([body], CPPFile, CPPTab + 1)
    writeLines(["}\n"], CPPFile, CPPTab)
    

def createTODO(TODOBody, Indent):
    newTODO = "/*" + Indent + TAB + TODOBody + Indent + "*/"
    return newTODO

def createTODODefault(indent):
    return createTODO("Your Code Here!!!!", indent)

def writeLines(lines, file, currentTAB):
    tab = createTAB(currentTAB)
    for line in lines:
        file.write(tab + line + "\n")

def createTAB(tabNum):
    global TAB
    newTAB = ""
    for i in range(0, tabNum):
        newTAB += TAB
    return newTAB

OBJECTNAME = input("What do you want to name this object?\n")
OperatorTypes.append(OBJECTNAME + "*")

IsDiscrete = getBool("Will this object store a discrete value?(y/n)\n")
IsContinous = getBool("Will this object store a continous value?(y/n)\n")
IsNumeric = getBool("Will this object store a numeric value?(y/n)\n")



HFile = open(OBJECTNAME + ".h", "w")
CPPFile = open(OBJECTNAME + ".cpp", "w")

writeLines(["#pragma once", "#ifndef " + OBJECTNAME.upper(), "#define " + OBJECTNAME.upper(), "#include<DFPAC/DataFrame.h>", "\n\n\n", "namespace DataPAC", "{"], HFile, 0)
writeLines(["class " + OBJECTNAME, "{"], HFile, 1)

writeLines(['#include "' + OBJECTNAME + '.h"', "", "", "namespace DataPAC", "{"], CPPFile, 0)

CPPTab += 1

functionCPP(OBJECTNAME, "", "", createTODODefault(createTAB(CPPTab)))
functionH(OBJECTNAME, "", "")
for type in OperatorTypes:#constructors
    functionCPP(OBJECTNAME, "", type + " newValue", createTODODefault(createTAB(CPPTab)))
    functionH(OBJECTNAME, "", type + " newValue")
writeNextSection()

for type in OperatorTypes: #seter functions
    functionCPP("setValue", "bool", type + " newValue", createTODODefault(createTAB(CPPTab)))
    functionH("setValue", "bool", type + " newValue")
writeNextSection()

for i in range(0, len(ConversionTypes)): #conversion methods
    functionCPP(ConversionTypes[i], OperatorTypes[i], "", createTODODefault(createTAB(CPPTab)))
    functionH(ConversionTypes[i], OperatorTypes[i], "")

functionCPP("toHash", "unsigned int", "", createTODODefault(createTAB(CPPTab)))
functionH("toHash", "unsigned int", "")
writeNextSection()

for check in ObjectChecks: #checks
    functionCPP(check, "bool", "", createTODODefault(createTAB(CPPTab)))
    functionH(check, "bool", "") 
writeNextSection() 

for operator in BooleanOperators:
    for type in OperatorTypes:
        functionCPP("operator" + operator, "bool", type + " rightSide", createTODODefault(createTAB(CPPTab)))
        functionH("operator" + operator, "bool", type + " rightSide")
    HFile.write("\n\n")
    CPPFile.write("\n\n")    
writeNextSection()

for operator in MathOperators:
    for type in OperatorTypes:
        if type == "std::string":
            if operator == "+":
                functionCPP("operator" + operator, "bool", type + " rightSide", createTODODefault(createTAB(CPPTab)))
                functionH("operator" + operator, "bool", type + " rightSide") 
        elif type == "char*": #only used to ear char*inputs
            hello = "sup"
        else:
            functionCPP("operator" + operator, "bool", type + " rightSide", createTODODefault(createTAB(CPPTab)))
            functionH("operator" + operator, "bool", type + " rightSide")
    HFile.write("\n\n")
    CPPFile.write("\n\n")         



HFile.write("}\n};\n\n#endif")
CPPFile.write("}")

HFile.close()
CPPFile.close()
