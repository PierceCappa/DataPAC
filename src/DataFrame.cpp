#include "DataFrame.h"

namespace DataPAC
{
	//PRIVATE METHODS	
	//-----------------------Read From CSV Helper Operators BEGIN-----------------------
	void DataFrame::createNewColumns(std::vector<NodeValue*> samples, std::vector<std::string> labels)
	{
		for(int i = 0; i < samples.size(); i++)
		{
			if(samples.size() == labels.size())
			{
				this->ColumnDict->emplace(labels[i], i);

			}
			else
			{
				this->ColumnDict->emplace("0" + std::to_string(i), i);
			}

			this->DefaultRow->Values.push_back(samples[i]);

		}
	}


	void DataFrame::resetCSVReadVariables()
	{


		this->newValueStartIndex = this->newValueEndIndex + 1;

		this->leftovers = "";
		//this->newNodesVector.clear();
	}

	void DataFrame::addNewValueToCharVector()
	{
		//std::cout << "adding new value to char\n";
		this->createCStringFromBuf();
		//std::cout << this->newValue << "\n";
		this->newValuesChar->push_back(this->newValue);
		//std::cout << this->newValuesChar->at(this->newValuesChar->size() - 1) << "\n";
	}


	void DataFrame::createCStringFromBuf()
	{
		int charLength = this->newValueEndIndex - this->newValueStartIndex;
		
		//memcpy(this->newValue, this->buf + this->newValueStartIndex, charLength);
		if(this->leftovers != "")
		{
			this->newValue = (char*)malloc(charLength + 1 + this->leftovers.size());
			strncpy(this->newValue, this->buf + this->newValueStartIndex, charLength);
			strncpy(this->newValue + charLength, this->leftovers.c_str(), this->leftovers.size());
			this->leftovers = "";
			charLength += this->leftovers.size();
		}
		else
		{
			this->newValue = (char*)malloc(charLength + 1);
			strncpy(this->newValue, this->buf + this->newValueStartIndex, charLength);
		}
		this->newValue[charLength] = '\0';
	}

	//PUBLIC METHODS	
	//-----------------------Read From CSV Helper Operators END-----------------------


	
    DataFrame::DataFrame()
    {
		this->ColumnDict = new std::map< std::string, int >();
		this->DefaultRow = new DataFrameRow(this->ColumnDict);
    }


	DataFrame::DataFrame(DataFrame* copyDF)
	{
		this->DefaultRow = copyDF->DefaultRow;
		this->readTitles = copyDF->readTitles;
		this->ColumnDict = copyDF->ColumnDict;
		this->DefaultRow = copyDF->DefaultRow;
	}

    DataFrame::DataFrame(std::vector<NodeValue*> sampleNodes, std::vector<std::string> labels, std::string fileAddress, bool firstRowIsLabels)
	{
		this->newValuesChar = new std::vector<char*>();
		this->readTitles = firstRowIsLabels;
		this->ColumnDict = new std::map< std::string, int >();
		this->DefaultRow = new DataFrameRow(this->ColumnDict);
		this->createNewColumns(sampleNodes, labels);
		this->readFromCSV(fileAddress);
	}


	DataFrame::~DataFrame()
	{

	}

	void DataFrame::shallowClean()
	{
		this->~DataFrame();
	}

	void DataFrame::deepClean()
	{
		for(int i = this->Rows.size(); i != 0; i--)
		{
			this->Rows[i - 1]->deepClean();
		}
		this->~DataFrame();

	}


	//-----------------------Initialization Methods END-----------------------
	//-----------------------NodeValue Generators BEGIN-----------------------
	NodeValue* DataFrame::NodeValueTypeGenerator(ValueType newNodeType)
	{

		return NULL;
	}

	NodeValue* DataFrame::NodeValueTypeGenerator(char* newValue, std::string column, int columnIndex)
	{

		return NULL;
	}

	//-----------------------NodeValue Generators END-----------------------
	//-----------------------Data Frame Operators BEGIN-----------------------

	DataFrameRow* DataFrame::operator[](int rowIndex)
	{
		return this->Rows[rowIndex];
	}


	//-----------------------Data Frame Operators END-----------------------
	//-----------------------Whole Data Frame Operations BEGIN-----------------------

	void DataFrame::sortDataFrame(std::vector<std::string> columns, bool isDescending)
	{
		
	}

	void DataFrame::modifyValues(void (*func)(DataFrameRow* row))
	{
		for(auto it = this->Rows.begin(); it != this->Rows.end(); it++)
		{
			func(*it);
		}
	}

	void DataFrame::expandDataFrameRows(void (*func)(DataFrameRow* row), std::vector<std::string> newColumns, std::vector<NodeValue*> newColumnTypes)
	{
		for(int i = 0; i < newColumnTypes.size(); i++)
		{
			this->ColumnDict->emplace(newColumns[i], this->DefaultRow->Values.size());
			this->DefaultRow->Values.push_back(newColumnTypes[i]);
		}
		for(auto it = this->Rows.begin(); it != this->Rows.end(); it++)
		{
			for(auto itj = newColumnTypes.begin(); itj != newColumnTypes.end(); itj++)
			{
				(*it)->Values.push_back((*itj)->createNewNode());
			}
			//(*it)->printRow();
			func((*it));
		}
	}

	void DataFrame::reduceDataFrameRows(std::vector<std::string> columns, bool deepClean)
	{
		std::vector<int> columnIndexs;
		for(int i = 0; i < columns.size(); i++)
		{
			columnIndexs.push_back(this->ColumnDict->find(columns[i])->second);
		}
		this->reduceDataFrameRows(columnIndexs, deepClean);
	}

	void DataFrame::reduceDataFrameRows(std::vector<int> columns, bool deepClean)
	{
		for(auto it = this->Rows.begin(); it != this->Rows.end(); it++)
		{
			for(auto itj = columns.begin(); itj != columns.end(); itj++)
			{
				NodeValue* deletedNode = (*it)->Values[(*itj)];
				if(deepClean == true)
				{
					free(deletedNode);
				}
			}
		}
		for(int i = 0; i < columns.size(); i++)
		{
			int columnIndex = columns[i];
			std::string columnTitle;
			for(std::map<std::string, int>::iterator it = this->ColumnDict->begin(); it != this->ColumnDict->end(); it++)
			{
				if(it->second > columnIndex)
				{
					it->second--;
				}
				if(it->second == columnIndex)
				{
					columnTitle = it->first;
				}
			}
			this->ColumnDict->erase(columnTitle);
		}
	}

	void DataFrame::reduceDataFrame(bool (*func)(DataFrameRow* row), bool deepClean)
	{
		auto it = this->Rows.end();
		while(it != this->Rows.begin())
		{
			it--;
			if(func((*it)))
			{
				if(deepClean == true)
				{
					(*it)->deepClean();
					free((*it));
				}
				this->Rows.erase(it);
			}
		}
	}

	void DataFrame::reduceDataFrame(int start, int end, bool deepClean)
	{
		if(start >= 0 && start <= this->Rows.size())
		{
			return;
		}
		if(end >= 0 && end <= this->Rows.size())
		{
			return;
		}
		if(start > end)
		{	
			return;
		}

		for(int i = end; i > start; i--)
		{
			if(deepClean == true)
			{
				this->Rows[i]->deepClean();
				free(this->Rows[i]);
			}
			this->Rows.erase(this->Rows.begin() + i);
		}
	}
	//std::vector<NodeValue*> columnTypes, std::vector<std::string> labels, std::string fileAddress
	void DataFrame::split(double ratio, DataFrame*& dfOne, DataFrame*& dfTwo)
	{
		if(ratio >= 0 && ratio <= 1)
		{


			srand(std::time(NULL));
			dfOne = new DataFrame(this);
			dfTwo = new DataFrame(this);

			int numRowsOne = this->Rows.size() * ratio;
			int numRowsTwo = this->Rows.size() - numRowsOne;
			int precision = 1000;
			int ratioToInt = precision * ratio;
			std::cout << this->Rows.size() << "\n";

			for(int i = this->Rows.size(); i != 0;)
			{
				if(rand() % precision <= ratioToInt)
				{
					dfOne->Rows.push_back(this->Rows[i - 1]);
					numRowsOne--;
				}
				else
				{
					dfTwo->Rows.push_back(this->Rows[i - 1]);
					numRowsTwo--;
				}
				i--;
				if(numRowsOne == i)
				{
					for(i; i != 0; i--)
					{
						dfOne->Rows.push_back(this->Rows[i - 1]);
						numRowsOne--;
					}
				}
				if(numRowsTwo == i)
				{
					for(i; i != 0; i--)
					{
						dfTwo->Rows.push_back(this->Rows[i - 1]);
						numRowsOne--;
					}
				} 
			}
		}
		else
		{
			std::cout << "inputs to split not correct \n";
		}


	}


	//----------------------Whole Data Frame Operations END-----------------------
	//-----------------------Read From CSV Operators BEGIN-----------------------

	void DataFrame::setColumnTitles(std::vector<char*> columnTitles)
	{
		//std::cout << "reading titles";
		if(this->ColumnDict->empty())
		{
			for(int l = 0; l < columnTitles.size(); l++)
			{
				//std::cout << columnTitles[l] << "\n";
				this->ColumnDict->insert({columnTitles.at(l), l});
			}
		}
		this->readTitles = false;
	}

	void DataFrame::readFromCSV(std::string fileAddress)
	{
		this->leftovers="";
		//std::cout << "trying to read csv\n";
		std::string currentElement = "";
		int i = 0;

		if (FILE* fp = fopen(fileAddress.c_str(), "r"))
		{
			//std::string newLine = "";

			//std::cout << "going to read stream \n";
			while (size_t len = fread(this->buf, 1, sizeof(this->buf), fp))
			{
				this->newValueStartIndex = 0;

				
				//std::cout << this->buf << "\nstarting new this->buf \n";
				for (i = 0; i < len; i++)
				{

					
					if (this->buf[i] == ',' || this->buf[i] == '\n')
					{
						this->newValueEndIndex = i;
						this->addNewValueToCharVector();
						this->newValueStartIndex = i + 1;

						if (this->buf[i] == '\n')
						{
							//std::cout << *(this->newValuesChar) << " -- " << i << "\n";
							if(this->readTitles == false)
							{
								this->createAndInsertNewRowFromCharVector(*(this->newValuesChar)); 
							}
							else
							{
								this->setColumnTitles(*(this->newValuesChar));
							}
							this->newValuesChar->clear();
						}

					}
					
				}
				if (this->newValueStartIndex < len - 1)
				{
					this->leftovers = this->buf[this->newValueStartIndex];
				}
		
				//this->parseAndInsertNewRowCSV(newLine);
				//std::cout << "count: " << count << "\n";
			}

			this->newValueEndIndex = i - 2;
			this->addNewValueToCharVector();
			if(this->readTitles == false)
			{
				this->createAndInsertNewRowFromCharVector(*(this->newValuesChar)); 
			}
			else
			{
				this->setColumnTitles(*(this->newValuesChar));
			}
			this->newValuesChar->clear();
			
		}
		else
		{
			std::cout << "failed to open file \n";
		}
	}

	void DataFrame::createAndInsertNewRowFromCharVector(std::vector<char*> values)
	{
		if(values.size() == this->ColumnDict->size())
		{
			this->Rows.push_back(new DataFrameRow(this->DefaultRow, values));
		}
		else
		{
			for(int i = 0; i < values.size(); i++)
			{
				std::cout << values[i] << "  ";
			}
			std::cout << "\n";
			//printf("number of values to be inserted (%zd) does not match expected value (%zd)\n", values.size(), this->ColumnDict->size()); 
		}
	}

	//-----------------------Read From CSV Operators END-----------------------
	//-----------------------Other Data Frame Methods BEGIN-----------------------


	

	DataFrameRow* DataFrame::getRow(int rowIndex)
	{
		return this->Rows[rowIndex];
	}

	int DataFrame::size()	
	{
		return this->DefaultRow->getColumnDict()->size();
	}

	int DataFrame::length()	
	{
		return this->Rows.size();
	}

	void DataFrame::printToConsole(int startRow, int endRow, int maxNumRowsPrint, std::string space)	
	{
		if(endRow == -1)
		{
			endRow = this->Rows.size();
		}
		for(int i = 0; i < this->DefaultRow->getColumnDict()->size(); i++)
		{
			for(std::map<std::string, int>::iterator it = this->DefaultRow->getColumnDict()->begin(); it != this->DefaultRow->getColumnDict()->end(); it++)
			{
				if(it->second == i)
				{
					if(i != 0)
					{
						std::cout << space;
					}
					std::cout << it->first;
				}
			}
		}
		int currentIndex = startRow;
		std::cout << "\n";
		for(int i = 0; i < maxNumRowsPrint; i++)
		{
			if(currentIndex == endRow)
			{
				i = maxNumRowsPrint;
			}
			else if(i == maxNumRowsPrint/2 && (startRow - endRow)/2 != currentIndex)
			{
				currentIndex = endRow - i;
				std::cout << ".\n.\n.\n";
			}
			this->Rows[currentIndex]->printRow(space);
			currentIndex++;
		
		}
		

	}

	void DataFrame::printColumnByteSize(std::string offset)	
	{

	}

	//-----------------------Other Data Frame Methods END-----------------------

}