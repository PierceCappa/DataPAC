#include "NodeValue.h"


namespace DataPAC
{
    NodeValue::~NodeValue(){}

    #pragma region ____________ Methods _________________________________________________________________________________________
    #pragma region >___________ Node Value Virtual Methods ______________________________________________________________________
    #pragma region >>__________ Virtual Copy Constructor and Deconstructor ______________________________________________________

    NodeValue* NodeValue::createNewNode(){return NULL;}
    
    NodeValue* NodeValue::createNewNode(char* newValue, int length){return NULL;}

    NodeValue* NodeValue::createNewNode(void* newValue){return NULL;}
    NodeValue* NodeValue::createNewNode(NodeValue newValue){return NULL;}

    NodeValue* NodeValue::createNewNode(int newValue){return NULL;}

    NodeValue* NodeValue::createNewNode(float newValue){return NULL;}
        
    NodeValue* NodeValue::createNewNode(std::string newValue){return NULL;}

    #pragma endregion
    #pragma region >>__________ Setters _________________________________________________________________________________________

    bool NodeValue::setValue(std::string newValue){return false;}
    bool NodeValue::setValue(char* newValue){return false;}
    bool NodeValue::setValue(float newValue){return false;}
    bool NodeValue::setValue(int newValue){return false;}
    bool NodeValue::setValue(NodeValue newValue){return false;}
    bool NodeValue::setValue(void* newValue){return false;}

    #pragma endregion
    #pragma region >>__________ NodeTypeOpertors ________________________________________________________________________________

    ValueType NodeValue::getType(){return ValueType::Float;}

    std::string NodeValue::toString(){return "";}

    void* NodeValue::getValue(){return NULL;}

    float NodeValue::toFloat(){return 0.0;}

    int NodeValue::toInt(){return 0;}

    bool NodeValue::isNumeric(){return false;}

    bool NodeValue::isContinous(){return false;}

    bool NodeValue::isDiscrete(){return false;}

    unsigned int NodeValue::toHash(){return 0;}

    #pragma endregion
    #pragma region >>__________ Logic Operators _________________________________________________________________________________

    bool NodeValue::operator==(NodeValue* rightSide){return false;}

    bool NodeValue::operator!=(NodeValue* rightSide){return false;}

    bool NodeValue::operator<(NodeValue* rightSide){return false;}

    bool NodeValue::operator>(NodeValue* rightSide){return false;}

    bool NodeValue::operator<=(NodeValue* rightSide){return false;}

    bool NodeValue::operator>=(NodeValue* rightSide){return false;}



    NodeValue NodeValue::operator+(NodeValue* rightSide){return rightSide;}

    NodeValue NodeValue::operator-(NodeValue* rightSide){return NodeValue();}

    NodeValue NodeValue::operator*(NodeValue* rightSide){return rightSide;}

    NodeValue NodeValue::operator/(NodeValue* rightSide){return NodeValue();}
    
    NodeValue NodeValue::operator%(NodeValue* rightSide){return NodeValue();}

    #pragma endregion
    #pragma endregion
    #pragma endregion
}