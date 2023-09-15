from ast import Num
import random
from xml.etree.ElementTree import tostring

OutputName = "Test.csv"
NumRows = 10000
File = open(OutputName, "w")

DataInfo = [    ["previous_sale", "square_footage", "city", "id"],
                ["float", "float", "discrete", "string"],
                [
                    [50000, 9000000], 
                    [600, 50000], 
                    ["seattle", "tacoma", "spokane", "wenatchee", "new york", "bremerton", "bellvue"],
                    ["abcdefghijklmnopqrstuvwxyz123456789", [6, 6]]
                ]
            ]

def newFloat(options):
    return random.uniform(options[0], options[1])

def newDiscrete(options):
    return options[random.randint(0, len(options) - 1)]

def newRandString(options):
    size = random.randint(options[1][0], options[1][1])
    string = ""
    for i in range(0, size):
        string += options[0][random.randint(0, len(options[0]) - 1)]
    return string

functions = []
for funcType in DataInfo[1]:
    if funcType == "float":
        functions.append(newFloat)
    elif funcType == "discrete":
        functions.append(newDiscrete)
    elif funcType == "string":
        functions.append(newRandString)


for j in range(0, len(DataInfo[0])):
    newValue = DataInfo[0][j] 
    File.write(newValue)
    if j != len(functions) - 1:
        File.write(",")
File.write("\n")

for i in range(0, NumRows):
    for j in range(0, len(functions)):
        newValue = functions[j](DataInfo[2][j]) 
        File.write(str(newValue))
        if j != len(functions) - 1:
            File.write(",")
    if i != NumRows - 1:
        File.write("\n")

File.close()