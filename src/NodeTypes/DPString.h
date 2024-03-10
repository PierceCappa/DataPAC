#pragma once
#ifndef NODEVALUECONTINUOUSSTRING
#define NODEVALUECONTINUOUSSTRING

#include "NodeValue.h"

namespace DataPAC
{
    class DPString: public NodeValue
    {
        public:
        #pragma region ____________ Properties ______________________________________________________________________________________
        
        char* Value;

        #pragma endregion
        #pragma region ____________ Methods _________________________________________________________________________________________
        #pragma region >___________ Constructors ____________________________________________________________________________________

        DPString();

        DPString(char* newValue, int length);

        DPString(std::string newValue);

        DPString(DPString* newValue);

        ~DPString();


        #pragma endregion
        #pragma region >___________ Node Value Virtual Methods ______________________________________________________________________
        #pragma region >>__________ Virtual Copy Constructor and Deconstructor ______________________________________________________


        NodeValue* CreateNewNode();
        
        NodeValue* CreateNewNode(char* newValue, int length);

        NodeValue* CreateNewNode(void* newValue);

        NodeValue* CreateNewNode(NodeValue newValue);

        NodeValue* CreateNewNode(int newValue);

        NodeValue* CreateNewNode(float newValue);
        
        NodeValue* CreateNewNode(std::string newValue);


        #pragma endregion
        #pragma region >>__________ Setters _________________________________________________________________________________________

        bool setValue(std::string newValue);

        bool setValue(char* newValue);

        bool setValue(float newValue);

        bool setValue(int newValue);

        bool setValue(NodeValue newValue);

        bool setValue(void* newValue);

        #pragma endregion
		#pragma region >>__________ NodeTypeOpertors ________________________________________________________________________________

		//returns a string of the current node type. Each node type should have a const string defined. returns "standardNode"
        ValueType GetType();

        std::string toString();

        void* getValue();

        float toFloat();

        int toInt();

        bool IsNumeric();

        bool IsContinous();

        bool IsDiscrete();

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
        #pragma region >__________ String Operators ________________________________________________________________________________


        void deleteCurrentString();

        unsigned int hash();


        #pragma endregion
        #pragma endregion

	
    };
}

#endif