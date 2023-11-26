#include "DataFrameRow.h"

namespace DataPAC
{
    //-----------------------Variables Get BEGIN -----------------------

    std::map<std::string, int>* DataFrameRow::getColumnDict()
    {
        return this->ColumnDict;
    }

    //-----------------------Variables Get END -----------------------
    //-----------------------Constructors BEGIN -----------------------

    DataFrameRow::DataFrameRow(std::map<std::string, int>* columnDict)
    {
        this->ColumnDict = columnDict;
    }

    DataFrameRow::DataFrameRow(DataFrameRow* defaultRow)
    {
        this->ColumnDict = defaultRow->getColumnDict();
        for(int i = 0; i < defaultRow->Values.size(); i++)
        {
            this->Values.push_back(defaultRow->Values[i]->createNewNode());
        }
    }

    DataFrameRow::DataFrameRow(DataFrameRow* defaultRow, std::vector<NodeValue> newNodeValues)
    {
        this->ColumnDict = defaultRow->getColumnDict();
        for(int i = 0; i < defaultRow->Values.size(); i++)
        {
            if(newNodeValues.size() > i)
            {
                this->Values.push_back(defaultRow->Values[i]->createNewNode(&newNodeValues[i]));
            }
            else
            {
                this->Values.push_back(defaultRow->Values[i]->createNewNode());
            }
        }
    }

    DataFrameRow::DataFrameRow(DataFrameRow* defaultRow, std::vector<char*> newNodeValues)
    {
        this->ColumnDict = defaultRow->getColumnDict();
        for(int i = 0; i < defaultRow->Values.size(); i++)
        {
            if(newNodeValues.size() > i)
            {
                this->Values.push_back(defaultRow->Values[i]->createNewNode(newNodeValues[i], strlen(newNodeValues[i])));
            }
            else
            {
                this->Values.push_back(defaultRow->Values[i]->createNewNode());
            }
        }
    }

    DataFrameRow::DataFrameRow(DataFrameRow* defaultRow, std::vector<std::string> newNodeValues)
    {
        this->ColumnDict = defaultRow->getColumnDict();
        for(int i = 0; i < defaultRow->Values.size(); i++)
        {
            if(newNodeValues.size() > i)
            {
                this->Values.push_back(defaultRow->Values[i]->createNewNode(newNodeValues[i]));
            }
            else
            {
                this->Values.push_back(defaultRow->Values[i]->createNewNode());
            }
        }
    }

    DataFrameRow::DataFrameRow(DataFrameRow* defaultRow, std::vector<void*> newNodeValues)
    {
        this->ColumnDict = defaultRow->getColumnDict();
        for(int i = 0; i < defaultRow->Values.size(); i++)
        {
            if(newNodeValues.size() > i)
            {
                std::cout << newNodeValues[i];
                this->Values.push_back(defaultRow->Values[i]->createNewNode(newNodeValues[i]));
            }
            else
            {
                this->Values.push_back(defaultRow->Values[i]->createNewNode());
            }
        }
    }

    DataFrameRow::~DataFrameRow()
    {

    }

    void DataFrameRow::deepClean()
    {
        for(int i = this->Values.size(); i != 0; i--)
        {
            free(this->Values[i - 1]);
        }
        this->~DataFrameRow();
    }

    //-----------------------Constructors END-----------------------
    //-----------------------Row Copy Methods BEGIN-----------------------

    DataFrameRow* DataFrameRow::createNewRow()
    {
        return new DataFrameRow(this);
    }

    DataFrameRow* DataFrameRow::createNewRow(std::vector<char*> newValues)
    {
        return new DataFrameRow(this, newValues);
    }

    DataFrameRow* DataFrameRow::createNewRow(std::vector<std::string> newValues)
    {
        return new DataFrameRow(this, newValues);
    }

    DataFrameRow* DataFrameRow::createNewRow(std::vector<NodeValue> newValues)
    {
        return new DataFrameRow(this, newValues);
    }

    DataFrameRow* DataFrameRow::createNewRow(std::vector<void*> newValues)
    {
        return new DataFrameRow(this, newValues);
    }

    //-----------------------Row Copy Methods END-----------------------
    //-----------------------Row Operators BEGIN-----------------------

    NodeValue* DataFrameRow::operator[](std::string index)
    {
        return this->Values[(*this->ColumnDict)[index]];
    }

    NodeValue* DataFrameRow::operator[](int index)
    {
        return this->Values[index];
    }

    //-----------------------Row Operators END----------------------
    //-----------------------Row Helper Function BEGIN----------------------

    std::vector<int> DataFrameRow::convertColumnNamesToIndexs(std::vector<std::string> columns)
    {
        std::vector<int> conversion;
        for(int i = 0; i < columns.size(); i++)
        {
            conversion.push_back((*this->ColumnDict)[columns[i]]);
        }
        return conversion;
    }

    std::vector<std::string> DataFrameRow::getColumnNames()
    {
        std::vector<std::string> columnNamesInOrder;

        for(int i = 0; i < this->ColumnDict->size(); i++) 
            columnNamesInOrder.push_back("");

        for(auto it = this->ColumnDict->begin(); it != this->ColumnDict->end(); it++) {
            std::string key = it->first;
            int keyIndex = this->convertColumnNamesToIndexs({key})[0];
            columnNamesInOrder[keyIndex] = key;
        }   
        return columnNamesInOrder;
    }   

    void DataFrameRow::printRow(std::string delimiter)
    {
        std::cout << this->toString(delimiter);
        std::cout << std::endl;
    }

    std::string DataFrameRow::toString(std::string delimiter) 
    {
        std::string output = "";

        if(this->Values.size() == 0) {
            return "";
        }

        //TODO add in edge case checks to make sure it is not null;
        auto it = this->Values.begin();
        output += (*it)->toString();
        it++;

        for(it; it != this->Values.end(); it++) {
            output += delimiter + (*it)->toString();
        }

        return output;
    }

    //-----------------------Row Helper Function END----------------------

}