from ast import Num
import random
from xml.etree.ElementTree import tostring

OutputName = "Test.csv"
NumRows = 1000000
File = open(OutputName, "w")


#The following arrays are used to configure the output csv file. Each array must be of the same size or errors will occur.

#these represent the column titles.   
columnTitles = ["previous_sale", "square_footage", "city", "id"]
#These determine the type each value in the column will be. By default only 3 values are supported, float, discrete or string. 
columnTypes = ["float", "float", "discrete", "string"]
#This array is used to determine the range of values that will be randomly generated.
#   Float, a 2 value array where the min value is first followed by the max value
#   discrete, a list of all possible values,
#   string, a string containing all possible chars and then a 2 value array containg min and max string size.
columnProperties =  [
                        [50000, 9000000], 
                        [600, 50000], 
                        ["seattle", "tacoma", "spokane", "wenatchee", "new york", "bremerton", "bellvue"],
                        ["abcdefghijklmnopqrstuvwxyz123456789", [6, 6]]
                    ]

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