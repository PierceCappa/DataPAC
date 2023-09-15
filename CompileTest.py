from configparser import ConfigParser
import os
import subprocess
import shutil
import glob

headerFolder = "DFPAC"
testPrefix = "Test_"
root = os.getcwd()
outputDir = root + "/bin/"
extrasDir = root + "/extras/"
testDir = root + "/tests/"
srcDir = root + "/src/"

junkFileExtension = '.o'
libFileExtension = '.a'

#shutil.rmtree(outputDir)
if not os.path.exists(outputDir):
    os.mkdir(outputDir)

if not os.path.exists(outputDir + headerFolder):
    os.mkdir(outputDir + headerFolder)

#print(config["PLATFORM"])



makeResult = subprocess.run(["make"], shell=True, cwd=srcDir)
for object in glob.iglob(os.path.join(srcDir, '*' + junkFileExtension)):
    os.remove(object)
for lib in glob.iglob(os.path.join(srcDir, '*' + libFileExtension)):
    shutil.copy(lib, outputDir)
    shutil.copy(lib, testDir)
for header in glob.iglob(os.path.join(srcDir, '*.h')):
    shutil.copy(header, outputDir + headerFolder)
    #print(makeResult)
    

#this is not important and was throwing too many errors
#generate needed csv files if needed
#if not os.path.isfile(testDir + "Test_DFPAC/Test.csv"):
    #result = subprocess.run(["python3 " + extrasDir + "GenerateTestData.py"], shell=True, cwd=currentDir)
    #print(result)
    #shutil.copy(extrasDir + "Test.csv", testDir + "Test_DFPAC/")

print("************Testing************")


currentDir = testDir
print(currentDir)
makeResult = subprocess.run(["make"], shell=True, cwd=currentDir)
makeResult = subprocess.run([currentDir + '/' + 'Test_DFPAC.out'], shell=True, cwd=currentDir, stdout=subprocess.PIPE, stderr=subprocess.PIPE)
print(makeResult)




print("jobs done")