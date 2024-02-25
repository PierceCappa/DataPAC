#pragma once
#ifndef NODEVALUEDISCRETE
#define NODEVALUEDISCRETE


#include <stdlib.h>
#include <vector>

#include "NodeValue.h"

namespace DataPAC
{
    
    class DPDiscrete: public NodeValue
    {
        public:
        #pragma region ____________ Properties ______________________________________________________________________________________
        
        std::vector<std::string*>* hashTable; 

        int Value;

        #pragma endregion
        #pragma region ____________ Methods _________________________________________________________________________________________
        #pragma region >___________ Constructors ____________________________________________________________________________________

        DPDiscrete();

        DPDiscrete(char* newValue, std::vector<std::string*>* newHashTable);

        DPDiscrete(std::string newValue, std::vector<std::string*>* newHashTable);

        DPDiscrete(int newValue, std::vector<std::string*>* newHashTable);

        DPDiscrete(DPDiscrete* newValue);

        #pragma endregion
        #pragma region >___________ Node Value Virtual Methods ______________________________________________________________________
        #pragma region >>__________ Virtual Copy Constructor and Deconstructor ______________________________________________________



        ~DPDiscrete();

        NodeValue* createNewNode();
        
        NodeValue* createNewNode(char* newValue, int length);

        NodeValue* createNewNode(void* newValue);

        NodeValue* createNewNode(NodeValue newValue);

        NodeValue* createNewNode(int newValue);

        NodeValue* createNewNode(float newValue);
        
        NodeValue* createNewNode(std::string newValue);

        #pragma endregion
        #pragma region >>__________ Setters _________________________________________________________________________________________

        bool setValue(std::string newValue);

        bool setValue(char* newValue);

        bool setValue(float newValue);

        bool setValue(int newValue);

        bool setValue(NodeValue* newValue);

        bool setValue(void* newValue);

        #pragma endregion
		#pragma region >>__________ NodeTypeOpertors ________________________________________________________________________________

		//returns a string of the current node type. Each node type should have a const string defined. returns "standardNode"
        ValueType getType();

        std::string toString();

        void* getValue();

        float toFloat();

        int toInt();

        bool isNumeric();

        bool isContinous();

        bool isDiscrete();

        unsigned int toHash();

        #pragma endregion
        #pragma region >>__________ Logic Operators _________________________________________________________________________________

        bool operator==(NodeValue* rightSide);





        bool operator!=(NodeValue* rightSide);





        bool operator<(NodeValue* rightSide);
        




        bool operator>(NodeValue* rightSide);
        




        bool operator<=(NodeValue* rightSide);





        bool operator>=(NodeValue* rightSide);






        NodeValue operator+(NodeValue* rightSide);



        NodeValue operator-(NodeValue* rightSide);





        NodeValue operator*(NodeValue* rightSide);
        




        NodeValue operator/(NodeValue* rightSide);
        


        

        NodeValue operator%(NodeValue* rightSide);
        


        #pragma endregion
        #pragma endregion
        #pragma region >__________ Discrete Operators _______________________________________________________________________________



        unsigned int hash(std::string string);

        bool findString(unsigned int& hashIndex, std::string aString);

        unsigned int addStringToTable(unsigned int& hashIndex, std::string* aString);

        std::string getString(int index);

        void createHashTable(int defaultNum);

        void storeValue(std::string newValue);

        void clearDictionary();

        void replaceHashValue(int valueIndex, std::string newValue);

        #pragma endregion
        #pragma endregion



      
    };

}

#endif