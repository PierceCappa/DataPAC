#include<iostream>
#include<vector>
#include<fstream>
#include"../bin/DFPAC/DataFrame.h"
//#include<DFPAC/DataFrame.h>

std::ofstream testingOutput;

int errorCount = 0;

std::string testDescription = "";

std::string testDataName = "DFTests.txt";
std::vector<std::string> labels = {"previous_sale", "square_footage", "city", "id"};
int testDataRows = 1000000;
int testDataColumns = 4;

bool outputToConsole = true;



void printString(std::string output) {
    testingOutput << output;
    if(outputToConsole) {
        std::cout << output;
    }
}


/**
 * This function is called by every test. It ensures that all tests start from the same initial dataset.
*/
DataPAC::DataFrame* createDataFrame() {
    testingOutput = std::ofstream(testDataName);
    //dataframe setup

    std::vector<DataPAC::NodeValue*> sampleNodes = {new DataPAC::DPFloat(), new DataPAC::DPFloat(), new DataPAC::DPDiscrete(), new DataPAC::DPString()};
    return new DataPAC::DataFrame(sampleNodes, labels, "Test.csv", true);

}



std::string toString(int num)
{
    return std::to_string(num);
}



std::string testRead()
{
    printString("Testing DF read\n");

    DataPAC::DataFrame* df = createDataFrame();

    std::string errors = "";

    if(df->Rows.size() != testDataRows)
    {
        errors += "Wrong number rows. Expected " + toString(testDataRows) + " rows, but got " + toString(df->Rows.size()) + " rows instead.     ";
    }
    if(df->DefaultRow->Values.size() != testDataColumns)
    {
        errors += "Wrong number columns. Expected " + toString(testDataColumns) + " columns, but got " + toString(df->DefaultRow->Values.size()) + " columns instead.";
    }

    df->deepClean();
    free(df);

    return errors;

}

std::string testSplit()
{
    printString("Testing DF split\n");

    DataPAC::DataFrame* df = createDataFrame();

    DataPAC::DataFrame* train;
    DataPAC::DataFrame* test;
    float split = .6;
    
    std::string errors = "";

    df->split(split, train, test);

    if(train->Rows.size() != df->Rows.size() * split)
    {
        errors += "Wrong number rows in train set. Expected " + toString(df->Rows.size() * split) + " rows, but got " + toString(train->Rows.size()) + " rows instead.     ";
    }
    if(test->Rows.size() != (df->Rows.size() * .4))
    {
        errors += "Wrong number rows in test set. Expected " + toString(df->Rows.size() * .4) + " rows, but got " + toString(test->Rows.size()) + " rows instead.     ";
    }

    df->deepClean();
    free(df);

    return errors;

}



void sampleExpandRowsFunc(DataPAC::DataFrameRow* row)
{
    (*row)["sample_addition"]->setValue((*row)["previous_sale"]->toFloat() + (*row)["square_footage"]->toFloat());
}

std::string testExpandRows()
{
    printString("Testing DF Expand Rows\n");

    DataPAC::DataFrame* df = createDataFrame();

    std::string errors = "";

    std::vector<DataPAC::NodeValue*> newValueTypes = {new DataPAC::DPFloat()};   
    std::vector<std::string> labels = {"sample_addition"};

    df->expandDataFrameRows(sampleExpandRowsFunc, labels, newValueTypes);

    float expectedResult = (*df->getRow(0))["previous_sale"]->toFloat() + (*df->getRow(0))["square_footage"]->toFloat();
    if((*df->getRow(0))["sample_addition"]->toFloat() != expectedResult )
    {
        errors += "Wrong number returned from test. Expected " + std::to_string(expectedResult) + ", but got " + std::to_string((*df->getRow(0))["sample_addition"]->toFloat());
    }

    df->deepClean();
    free(df);

    return errors;
}

void sampleModifyDFFunction(DataPAC::DataFrameRow* row)
{
    (*row)["previous_sale"]->setValue((*row)["previous_sale"]->toFloat() + 2);
}

std::string testModifyValues()
{
    printString("Testing DF modify values\n");

    DataPAC::DataFrame* df = createDataFrame();

    std::string errors = "";
    float expectedResult = (*df->getRow(0))["previous_sale"]->toFloat() + 2;

    df->modifyValues(sampleModifyDFFunction);

    if((*df->getRow(0))["previous_sale"]->toFloat() != expectedResult )
    {
        errors += "Wrong number returned from test. Expected " + std::to_string(expectedResult) + ", but got " + std::to_string((*df->getRow(0))["previous_sale"]->toFloat());
    }

    df->deepClean();
    free(df);

    return errors;
}


std::string testOutputToCSV(){
    DataPAC::DataFrame* df = createDataFrame();

    df->writeToCSV("testOuput.csv");

    free(df);

    return "";
} 



std::string checkDeconstructor() {
    DataPAC::DataFrame* df = createDataFrame();

    free(df);

    return "";
}



void runTest(std::string (*func)(), std::string description)
{
    testDescription = description;
    try
    {
        std::string potentialError = func();
        if(potentialError != "")
        {
            printString("\n\n   Test Failure: " + testDescription + "\n" + potentialError + "\n\n"); 
            errorCount++;
        }
    }
    catch(const std::exception& e)
    {
        printString("\n\n   Test Failed to Complete: " + testDescription + "\n" + e.what() + "\n\n");
        errorCount++;
    }
}


int main()
{
    try
    {       

        //place new tests here
        // EX: runTest(func, "Example Test")

        runTest(testRead, "Making sure that the df initializer and csv reader worked");
        runTest(testSplit, "Making sure that the split function works");
        runTest(testExpandRows, "Testing expandDataFrameRows functionality");
        runTest(testModifyValues, "Testing the ability to modify dataframe values");
        runTest(testOutputToCSV, "Testing the write to CSV feature");
        runTest(checkDeconstructor, "Testing deconstructor");
        
        
        //testing end here
        if(errorCount == 0)
        {
            testingOutput << "All tests have passed!!!!! \n\n";
        } else {
            testingOutput << errorCount << " Tests Failed!!!!! \n\n";
        }

        testingOutput.close();
        return 0;
    }
    catch(const std::exception& e)
    {
        testingOutput << "Testing has failed!!!! " <<  e.what() << '\n';
        testingOutput.close();
        return 1;
    }
    
   
}