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
        //-----------------------Class Members BEGIN-----------------------
        //-----------------------Class Members END-----------------------
		//-----------------------Initialization Methods BEGIN-----------------------

		NodeValue(){}

        NodeValue(char* newValue){}

        NodeValue(void* newValue){}

        NodeValue(NodeValue* newValue){}

        virtual ~NodeValue();

        virtual NodeValue* createNewNode();
        
        virtual NodeValue* createNewNode(char* newValue, int length);

        virtual NodeValue* createNewNode(void* newValue);

        virtual NodeValue* createNewNode(NodeValue newValue);

        virtual NodeValue* createNewNode(int newValue);

        virtual NodeValue* createNewNode(float newValue);

        virtual NodeValue* createNewNode(std::string newValue);

		//-----------------------Initialization Methods END-----------------------
        //-----------------------Set Value Methods BEGIN-----------------------

        virtual bool setValue(std::string newValue);

        virtual bool setValue(char* newValue);

        virtual bool setValue(float newValue);

        virtual bool setValue(int newValue);

        virtual bool setValue(NodeValue newValue);

        virtual bool setValue(void* newValue);

        //-----------------------Set Value Methods END-----------------------
		//-----------------------General node value operators for overide BEGIN-----------------------

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

		//-----------------------General node value operators for overide END-----------------------
        //-----------------------Object Operators Methods BEGIN-----------------------

        virtual bool operator==(NodeValue* rightSide);

        virtual bool operator==(float rightSide);

        virtual bool operator==(int rightSide);

        virtual bool operator==(char* rightSide);

        virtual bool operator==(std::string rightSide);

        virtual bool operator==(void* rightSide);



        virtual bool operator!=(NodeValue* rightSide);

        virtual bool operator!=(float rightSide);

        virtual bool operator!=(int rightSide);

        virtual bool operator!=(char* rightSide);

        virtual bool operator!=(std::string rightSide);

        virtual bool operator!=(void* rightSide);



        virtual bool operator<(NodeValue* rightSide);
        
        virtual bool operator<(float rightSide);

        virtual bool operator<(int rightSide);

        virtual bool operator<(char* rightSide);

        virtual bool operator<(std::string rightSide);

        virtual bool operator<(void* rightSide);



        virtual bool operator>(NodeValue* rightSide);
        
        virtual bool operator>(float rightSide);

        virtual bool operator>(int rightSide);

        virtual bool operator>(char* rightSide);

        virtual bool operator>(std::string rightSide);

        virtual bool operator>(void* rightSide);



        virtual bool operator<=(NodeValue* rightSide);

        virtual bool operator<=(float rightSide);

        virtual bool operator<=(int rightSide);

        virtual bool operator<=(char* rightSide);

        virtual bool operator<=(std::string rightSide);

        virtual bool operator<=(void* rightSide);



        virtual bool operator>=(NodeValue* rightSide);

        virtual bool operator>=(float rightSide);

        virtual bool operator>=(int rightSide);

        virtual bool operator>=(char* rightSide);

        virtual bool operator>=(std::string rightSide);

        virtual bool operator>=(void* rightSide);





        virtual NodeValue operator+(NodeValue* rightSide);

        virtual float operator+(float rightSide);

        virtual float operator+(int rightSide);

        virtual std::string operator+(std::string rightSide);

        virtual void* operator+(void* rightSide);



        virtual NodeValue operator-(NodeValue* rightSide);

        virtual float operator-(float rightSide);

        virtual float operator-(int rightSide);

        virtual void* operator-(void* rightSide);



        virtual NodeValue operator*(NodeValue* rightSide);
        
        virtual float operator*(float rightSide);

        virtual float operator*(int rightSide);

        virtual void* operator*(void* rightSide);



        virtual NodeValue operator/(NodeValue* rightSide);
        
        virtual float operator/(float rightSide);

        virtual float operator/(int rightSide);

        virtual void* operator/(void* rightSide);

        

        virtual NodeValue operator%(NodeValue* rightSide);
        
        virtual float operator%(float rightSide);

        virtual float operator%(int rightSide);

        virtual void* operator%(void* rightSide);

        //-----------------------Object Operators Methods END-----------------------

    };




}

#endif