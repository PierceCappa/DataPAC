#pragma once
#ifndef NODEVALUECONTINUOUSFLOAT
#define NODEVALUECONTINUOUSFLOAT


#include <stdlib.h>

#include "NodeValue.h"

namespace DataPAC
{
    class DPFloat: public NodeValue
    {

        public:
        #pragma region ____________ Properties ______________________________________________________________________________________
        
        float Value;

        #pragma endregion
        #pragma region ____________ Methods _________________________________________________________________________________________
        #pragma region >___________ Constructors ____________________________________________________________________________________

        DPFloat();

        DPFloat(char* newValue);

        DPFloat(float newValue);

        #pragma endregion
        #pragma region >___________ Node Value Virtual Methods ______________________________________________________________________
        #pragma region >>__________ Virtual Copy Constructor and Deconstructor ______________________________________________________


        ~DPFloat();

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
        #pragma region >__________ Float Operators ________________________________________________________________________________


        void deleteCurrentString();

        unsigned int hash();


        #pragma endregion
        #pragma endregion

    
    };
}

#endif