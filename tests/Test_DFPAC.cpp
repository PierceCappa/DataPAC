#include<iostream>
#include<vector>
#include<fstream>
#include"../bin/DFPAC/DataFrame.h"
//#include<DFPAC/DataFrame.h>

std::ofstream testingOutput;

int errorCount = 0;

std::string testDescription = "";

int testDataRows = 10000;
int testDataColumns = 4;

DataPAC::DataFrame df;

std::string toString(int num)
{
    return std::to_string(num);
}

std::string testRead()
{

    std::string errors = "";

    if(df.Rows.size() != testDataRows)
    {
        errors += "Wrong number rows. Expected " + toString(testDataRows) + " rows, but got " + toString(df.Rows.size()) + " rows instead.     ";
    }
    if(df.DefaultRow->Values.size() != testDataColumns)
    {
        errors += "Wrong number columns. Expected " + toString(testDataColumns) + " columns, but got " + toString(df.DefaultRow->Values.size()) + " columns instead.";
    }
    return errors;

}

std::string testSplit()
{
    DataPAC::DataFrame* train;
    DataPAC::DataFrame* test;
    float split = .6;
    
    std::string errors = "";

    df.split(split, train, test);

    if(train->Rows.size() != df.Rows.size() * split)
    {
        errors += "Wrong number rows in train set. Expected " + toString(df.Rows.size() * split) + " rows, but got " + toString(train->Rows.size()) + " rows instead.     ";
    }
    if(test->Rows.size() != (df.Rows.size() * .4))
    {
        errors += "Wrong number rows in test set. Expected " + toString(df.Rows.size() * .4) + " rows, but got " + toString(test->Rows.size()) + " rows instead.     ";
    }
    return errors;

}



void sampleExpandRowsFunc(DataPAC::DataFrameRow* row)
{
    (*row)["sample_addition"]->setValue((*row)["previous_sale"]->toFloat() + (*row)["square_footage"]->toFloat());
}

std::string testExpandRows()
{
    std::string errors = "";

    std::vector<DataPAC::NodeValue*> newValueTypes = {new DataPAC::DPFloat()};   
    std::vector<std::string> labels = {"sample_addition"};

    df.expandDataFrameRows(sampleExpandRowsFunc, labels, newValueTypes);

    float expectedResult = (*df[0])["previous_sale"]->toFloat() + (*df[0])["square_footage"]->toFloat();
    if((*df[0])["sample_addition"]->toFloat() != expectedResult )
    {
        errors += "Wrong number returned from test. Expected " + std::to_string(expectedResult) + ", but got " + std::to_string((*df[0])["sample_addition"]->toFloat());
    }

    return errors;
}

void sampleModifyDFFunction(DataPAC::DataFrameRow* row)
{
    (*row)["previous_sale"]->setValue((*row)["previous_sale"]->toFloat() + 2);
}

std::string testModifyValues()
{
    std::string errors = "";
    float expectedResult = (*df[0])["previous_sale"]->toFloat() + 2;

    df.modifyValues(sampleModifyDFFunction);

    if((*df[0])["previous_sale"]->toFloat() != expectedResult )
    {
        errors += "Wrong number returned from test. Expected " + std::to_string(expectedResult) + ", but got " + std::to_string((*df[0])["previous_sale"]->toFloat());
    }
    return errors;
}













void runTest(std::string (*func)(), std::string description)
{
    testDescription = description;
    try
    {
        std::string potentialError = func();
        if(potentialError != "")
        {
            testingOutput << "\n\n   Test Failure: " << testDescription<< "\n" << potentialError << "\n\n";
            errorCount++;
        }
    }
    catch(const std::exception& e)
    {
        testingOutput << "\n\n   Test Failed to Complete: " << testDescription << "\n" << e.what() << "\n\n";
        errorCount++;
    }
}


int main()
{
    try
    {   
        testingOutput = std::ofstream("DFTests.txt");
        //dataframe setup

        std::vector<DataPAC::NodeValue*> sampleNodes = {new DataPAC::DPFloat(), new DataPAC::DPFloat(), new DataPAC::DPDiscrete(), new DataPAC::DPString()};
        std::vector<std::string> labels = {"previous_sale", "square_footage", "city", "id"};
        df = DataPAC::DataFrame (sampleNodes, labels, "Test.csv", true, 1);
    

        //place new tests here
        // EX: runTest(func, "Example Test")

        runTest(testRead, "Making sure that the df initializer and csv reader worked");
        runTest(testSplit, "Making sure that the split function works");
        runTest(testExpandRows, "Testing expandDataFrameRows functionality");
        runTest(testModifyValues, "Testing the ability to modify dataframe values");
        
        
        //testing end here
        if(errorCount == 0)
        {
            testingOutput << "All tests have passed!!!!! \n\n";
        }

        //df.printToConsole();

        testingOutput << "Jobs Done\n";

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