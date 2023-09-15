#pragma once
#ifndef DATAFRAMEROW
#define DATAFRAMEROW

#include <vector>
#include <map>

#include "DPDiscrete.h"
#include "DPString.h"
#include "DPFloat.h"

namespace DataPAC
{

    class DataFrameRow
    {
        private:
        std::map<std::string, int>* ColumnDict;

        public:
        //-----------------------Variables BEGIN -----------------------
        std::vector<NodeValue*> Values;
        //-----------------------Variables END -----------------------
        //-----------------------Variables Get BEGIN -----------------------
        std::map<std::string, int>* getColumnDict();
        //-----------------------Variables Get END -----------------------
        //-----------------------Constructors BEGIN -----------------------

        //This initializer function should never be called by the user.
        DataFrameRow(std::map<std::string, int>* columnDict);
        DataFrameRow(DataFrameRow* defaultRow);
        DataFrameRow(DataFrameRow* defaultRow, std::vector<NodeValue> newNodeValues);
        DataFrameRow(DataFrameRow* defaultRow, std::vector<char*> newNodeValues);
        DataFrameRow(DataFrameRow* defaultRow, std::vector<std::string> newNodeValues);
        DataFrameRow(DataFrameRow* defaultRow, std::vector<void*> newNodeValues);

        ~DataFrameRow();

        void deepClean();

        //-----------------------Constructors END-----------------------
        //-----------------------Row Copy Methods BEGIN-----------------------

        DataFrameRow* createNewRow();

        DataFrameRow* createNewRow(char* newValues, int length);

        DataFrameRow* createNewRow(std::vector<char*> newValues);

        DataFrameRow* createNewRow(std::vector<std::string> newValues);

        DataFrameRow* createNewRow(std::vector<NodeValue> newValues);

        DataFrameRow* createNewRow(std::vector<void*> newValues);

        //-----------------------Row Copy Methods END-----------------------
        //-----------------------Row Operators BEGIN-----------------------

        NodeValue* operator[](std::string index);

        NodeValue* operator[](int index);

        //-----------------------Row Operators END----------------------
        //-----------------------Row Helper Function BEGIN----------------------

        std::vector<int> convertColumnNamesToIndexs(std::vector<std::string> colums);

        void printRow(std::string space = "   |   ");

        //-----------------------Row Helper Function END----------------------
    };
    
} // namespace D


#endif