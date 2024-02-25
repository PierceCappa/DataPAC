#pragma once
#ifndef NODEVALUE
#define NODEVALUE

#include<string>
#include<iostream>
#include<string.h>

namespace DataPAC
{
    enum ValueType
    {
        Float,
        String,
        Special,
        Discrete,
    };

    class NodeValue
    {
        public:
        #pragma region ____________ Methods _________________________________________________________________________________________
        #pragma region >___________ Constructors ____________________________________________________________________________________

		NodeValue(){}

        NodeValue(char* newValue){}

        NodeValue(void* newValue){}

        NodeValue(NodeValue* newValue){}

        #pragma endregion
        #pragma region >___________ Node Value Virtual Methods ______________________________________________________________________
        #pragma region >>__________ Virtual Copy Constructor and Deconstructor ______________________________________________________


        virtual ~NodeValue();

        virtual NodeValue* createNewNode();
        
        virtual NodeValue* createNewNode(char* newValue, int length);

        virtual NodeValue* createNewNode(void* newValue);

        virtual NodeValue* createNewNode(NodeValue newValue);

        virtual NodeValue* createNewNode(int newValue);

        virtual NodeValue* createNewNode(float newValue);

        virtual NodeValue* createNewNode(std::string newValue);

        #pragma endregion
        #pragma region >>__________ Setters _________________________________________________________________________________________


        virtual bool setValue(std::string newValue);

        virtual bool setValue(char* newValue);

        virtual bool setValue(float newValue);

        virtual bool setValue(int newValue);

        virtual bool setValue(NodeValue newValue);

        virtual bool setValue(void* newValue);

        #pragma endregion
		#pragma region >>__________ NodeTypeOpertors ________________________________________________________________________________

		//returns a string of the current node type. Each node type should have a const string defined. returns "standardNode"
        virtual ValueType getType();

        virtual std::string toString();

        virtual void* getValue();

        virtual float toFloat();

        virtual int toInt();

        virtual bool isNumeric();

        virtual bool isContinous();

        virtual bool isDiscrete();

        virtual unsigned int toHash();

        #pragma endregion
        #pragma region >>__________ Logic Operators _________________________________________________________________________________

        virtual bool operator==(NodeValue* rightSide);

        virtual bool operator!=(NodeValue* rightSide);


        virtual bool operator<(NodeValue* rightSide);



        virtual bool operator>(NodeValue* rightSide);


        virtual bool operator<=(NodeValue* rightSide);


        virtual bool operator>=(NodeValue* rightSide);


        virtual NodeValue operator+(NodeValue* rightSide);


        virtual NodeValue operator-(NodeValue* rightSide);



        virtual NodeValue operator*(NodeValue* rightSide);


        virtual NodeValue operator/(NodeValue* rightSide);
        

        virtual NodeValue operator%(NodeValue* rightSide);
        
        #pragma endregion
        #pragma endregion
        #pragma endregion
    };




}

#endif