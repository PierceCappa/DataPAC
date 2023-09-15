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
        //-----------------------Class Members BEGIN-----------------------
        
        std::vector<std::string*>* hashTable; 

        int Value;
        //-----------------------Class Members END-----------------------
        //-----------------------Initialization Methods BEGIN-----------------------

        DPDiscrete();

        DPDiscrete(char* newValue, std::vector<std::string*>* newHashTable);

        DPDiscrete(std::string newValue, std::vector<std::string*>* newHashTable);

        DPDiscrete(int newValue, std::vector<std::string*>* newHashTable);

        DPDiscrete(DPDiscrete* newValue);

        ~DPDiscrete();

        NodeValue* createNewNode();
        
        NodeValue* createNewNode(char* newValue, int length);

        NodeValue* createNewNode(void* newValue);

        NodeValue* createNewNode(NodeValue newValue);

        NodeValue* createNewNode(int newValue);

        NodeValue* createNewNode(float newValue);
        
        NodeValue* createNewNode(std::string newValue);

		//-----------------------Initialization Methods END-----------------------
        //-----------------------Set Value Methods BEGIN-----------------------

        bool setValue(std::string newValue);

        bool setValue(char* newValue);

        bool setValue(float newValue);

        bool setValue(int newValue);

        bool setValue(NodeValue* newValue);

        bool setValue(void* newValue);

        //-----------------------Set Value Methods END-----------------------
		//-----------------------General node value operators for overide BEGIN-----------------------

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

		//-----------------------General node value operators for overide END-----------------------
        //-----------------------Object Operators Methods BEGIN-----------------------

        bool operator==(NodeValue* rightSide);

        bool operator==(float rightSide);

        bool operator==(int rightSide);

        bool operator==(char* rightSide);

        bool operator==(std::string rightSide);

        bool operator==(void* rightSide);



        bool operator!=(NodeValue* rightSide);

        bool operator!=(float rightSide);

        bool operator!=(int rightSide);

        bool operator!=(char* rightSide);

        bool operator!=(std::string rightSide);

        bool operator!=(void* rightSide);



        bool operator<(NodeValue* rightSide);
        
        bool operator<(float rightSide);

        bool operator<(int rightSide);

        bool operator<(char* rightSide);

        bool operator<(std::string rightSide);

        bool operator<(void* rightSide);



        bool operator>(NodeValue* rightSide);
        
        bool operator>(float rightSide);

        bool operator>(int rightSide);

        bool operator>(char* rightSide);

        bool operator>(std::string rightSide);

        bool operator>(void* rightSide);



        bool operator<=(NodeValue* rightSide);

        bool operator<=(float rightSide);

        bool operator<=(int rightSide);

        bool operator<=(char* rightSide);

        bool operator<=(std::string rightSide);

        bool operator<=(void* rightSide);



        bool operator>=(NodeValue* rightSide);

        bool operator>=(float rightSide);

        bool operator>=(int rightSide);

        bool operator>=(char* rightSide);

        bool operator>=(std::string rightSide);

        bool operator>=(void* rightSide);





        NodeValue operator+(NodeValue* rightSide);

        float operator+(float rightSide);

        float operator+(int rightSide);

        char* operator+(char* rightSide);

        std::string operator+(std::string rightSide);

        void* operator+(void* rightSide);



        NodeValue operator-(NodeValue* rightSide);

        float operator-(float rightSide);

        float operator-(int rightSide);

        void* operator-(void* rightSide);



        NodeValue operator*(NodeValue* rightSide);
        
        float operator*(float rightSide);

        float operator*(int rightSide);

        void* operator*(void* rightSide);



        NodeValue operator/(NodeValue* rightSide);
        
        float operator/(float rightSide);

        float operator/(int rightSide);

        void* operator/(void* rightSide);

        

        NodeValue operator%(NodeValue* rightSide);
        
        float operator%(float rightSide);

        float operator%(int rightSide);

        void* operator%(void* rightSide);

        //-----------------------Object Operators Methods END-----------------------
        //-----------------------Hashtable Operations BEGIN-----------------------

        unsigned int hash(std::string string);

        bool findString(unsigned int& hashIndex, std::string aString);

        unsigned int addStringToTable(unsigned int& hashIndex, std::string* aString);

        std::string getString(int index);

        void createHashTable(int defaultNum);

        void storeValue(std::string newValue);

        void clearDictionary();

        void replaceHashValue(int valueIndex, std::string newValue);

        //-----------------------Hashtable Operations END-----------------------


      
    };

}

#endif