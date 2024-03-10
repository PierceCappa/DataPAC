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
        LongDouble,
        Double,
        Float,
        LongLong,
        ULongLong,
        Long,
        ULong,
        Int,
        UInt,
        Short,
        UShort,
        Char,
        String,
        Discrete,
        Invalid,
    };

    class NodeValue
    {
        public:
        #pragma region ____________ Methods _________________________________________________________________________________________
        #pragma region >___________ Constructors/Deconstructors _____________________________________________________________________

		NodeValue(){}

        NodeValue(char* newValue){}

        NodeValue(NodeValue* newValue){}

        ~NodeValue(){}
        
        #pragma endregion
        #pragma region >___________ Node Value General Operators ____________________________________________________________________

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
        #pragma region >___________ Node Value Virtual Methods ______________________________________________________________________
        #pragma region >>__________ Virtual Copy Constructor and Deconstructor ______________________________________________________


        virtual void Deallocate();

        virtual NodeValue* CreateNewNode();
        
        virtual NodeValue* CreateNewNode(char* newValue, int length);

        virtual NodeValue* CreateNewNode(std::string newValue);



        #pragma endregion
		#pragma region >>__________ NodeValue to C++ Fundemental Types ______________________________________________________________

        virtual std::string ToString();

        virtual long double ToLongDouble();

        virtual double ToDouble();

        virtual float ToFloat();

        virtual long long ToLongLong();

        virtual unsigned long long ToULongLong();

        virtual long ToLong();

        virtual unsigned long ToULong();

        virtual int ToInt();

        virtual unsigned int ToUInt();

        virtual short ToShort();

        virtual unsigned short ToUShort();

        virtual char ToChar();


        #pragma endregion
		#pragma region >>__________ Node Value Informational ________________________________________________________________________

		//returns a string of the current node type. Each node type should have a const string defined. returns "standardNode"
        virtual ValueType GetType();

        virtual bool IsNumeric();

        virtual bool IsContinous();

        virtual bool IsDiscrete();

        #pragma endregion
        #pragma endregion
        #pragma endregion
    };




}

#endif