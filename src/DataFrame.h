#pragma once
#ifndef DATAFRAME
#define DATAFRAME

#include<iostream>
#include<vector>
#include<map>
#include<ctime>
#include<stdlib.h>

#include"DataFrameRow.h"

const int BUF_SIZE = 8192;
const int MAX_LONG_DOUBLE_DIGIT_LENGTH = 15;

namespace DataPAC
{

    enum QueuedOperation{
        WholeDFOperation, //This needs to be expaned. Each operation needs its own enum, such as sort, reduce etc
        CreateRow,
        DeleteRow,
        UpdateRow,
        ReadRow,   
    };

    class DataFrame
    {
	private:
		// the following variables are used for reading values and creating nodes and columns. should not be used by other users.
		std::vector<std::string> newValuesVector;
		std::vector<char*>* newValuesChar;

		std::string leftovers;

		char* newValue;

		int newValueStartIndex;
		int newValueEndIndex;
		char buf[BUF_SIZE];
		NodeValue* newNode;

		bool readTitles;


		int NumThreads;

		//Inputs to this vector are,
		//	The operation to be computed stored in queuedOperation.
		//	The row to be operated on. In the case where either row doesnt exist or for whole data frame opeartions, than it will not be read. 
		//	all other data needed for an operation should be pointed to in the void*. Example: void* should point to a csv line when creating a new row.
		std::vector<std::tuple<QueuedOperation, int, void*>> OperationsQueue;

		//-----------------------Read From CSV Helper Operators BEGIN-----------------------

		void resetCSVReadVariables();

		void addNewValueToCharVector();

		void createNewColumns(std::vector<NodeValue*> samples, std::vector<std::string> labels);

		void createCStringFromBuf();

		void clearCSVReadingVariables();

		//-----------------------Read From CSV Helper Operators END-----------------------






    public:

		//-----------------------Data Frame Members BEGIN-----------------------

		std::map< std::string, int >* ColumnDict;

		std::vector<DataFrameRow*> Rows;

		//When createing new rows, call this object. It should not be modified unless dataframe is altered.
		DataFrameRow* DefaultRow;

		//-----------------------Data Frame Members END-----------------------
		//-----------------------Initialization Methods BEGIN-----------------------
		//default constructor, creates an empty dataframe object.

		DataFrame(int numThreads = 1);

		DataFrame(DataFrame* copyDF);	

		//loads dataframe from file given the path to the file. currently accepted file types:
		//	CSV
		DataFrame(std::vector<NodeValue*> columnTypes, std::vector<std::string> labels, std::string fileAddress, bool firstRowIsLabels = true, int numThreads = 1);	

		~DataFrame();

		void shallowClean();

		void deepClean();

		//-----------------------Initialization Methods END-----------------------
		//-----------------------NodeValue Generators BEGIN-----------------------
		NodeValue* NodeValueTypeGenerator(ValueType newNodeType);

		NodeValue* NodeValueTypeGenerator(char* newValue, std::string column = "", int columnIndex = -1);

		//-----------------------NodeValue Generators END-----------------------
		//-----------------------Data Frame Operators BEGIN-----------------------

		DataFrameRow* operator[](int rowIndex);


		//-----------------------Data Frame Operators END-----------------------
		//-----------------------Whole Data Frame Operations BEGIN-----------------------

		void sortDataFrame(std::vector<std::string> columns, bool isDescending);

		void modifyValues(void (*func)(DataFrameRow* row));

		void expandDataFrameRows(void (*func)(DataFrameRow* row), std::vector<std::string> newColumns, std::vector<NodeValue*> newColumnTypes);

		void reduceDataFrameRows(std::vector<std::string> columns, bool deepClean);

		void reduceDataFrameRows(std::vector<int> columns, bool deepClean);

		void reduceDataFrame(bool (*func)(DataFrameRow* row), bool deepClean);

		void reduceDataFrame(int start, int end, bool deepClean);

		//todo: experiment with this.
		void dataFrameComp(std::vector<void*> (*threadSetup)(std::vector<void*> otherArguments), void (*comp)(DataFrameRow* row, std::vector<void*> otherArguments), bool (*exitLoopCheck)(int loopIndex, std::vector<void*> otherArguments), void (*exitLoopActions)(int loopIndex, std::vector<void*> otherArguments) ,std::vector<void*> otherArguments);

		void split(double ratio, DataFrame*& dfOne, DataFrame*& dfTwo);

		//----------------------Whole Data Frame Operations END-----------------------
		//-----------------------Read From CSV Operators BEGIN-----------------------

		void setColumnTitles(std::vector<char*> columnTitles);

		void readFromCSV(std::string fileAddress);

		void createAndInsertNewRowFromCharVector(std::vector<char*> values);

		//-----------------------Read From CSV Operators END-----------------------
		//-----------------------Other Data Frame Methods BEGIN-----------------------


		void createDefaultColumns(int numcolumns);


		DataFrameRow* getRow(int rowIndex);

		int size();

		int length();

		void printToConsole(int startRow = 0, int endRow = -1, int maxNumRowsPrint = 10, std::string space = "   |   ");

		void printColumnByteSize(std::string offset);

		//-----------------------Other Data Frame Methods END-----------------------


    };
}

#endif