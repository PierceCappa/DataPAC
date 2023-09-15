#include "NodeValue.h"


namespace DataPAC
{
    NodeValue::~NodeValue(){}

    //-----------------------Initialization Methods BEGIN-----------------------

    NodeValue* NodeValue::createNewNode(){return NULL;}
    
    NodeValue* NodeValue::createNewNode(char* newValue, int length){return NULL;}

    NodeValue* NodeValue::createNewNode(void* newValue){return NULL;}
    NodeValue* NodeValue::createNewNode(NodeValue newValue){return NULL;}

    NodeValue* NodeValue::createNewNode(int newValue){return NULL;}

    NodeValue* NodeValue::createNewNode(float newValue){return NULL;}
        
    NodeValue* NodeValue::createNewNode(std::string newValue){return NULL;}

	//-----------------------Initialization Methods END-----------------------
    //-----------------------Set Value Methods BEGIN-----------------------

    bool NodeValue::setValue(std::string newValue){return false;}

    bool NodeValue::setValue(char* newValue){return false;}

    bool NodeValue::setValue(float newValue){return false;}
    bool NodeValue::setValue(int newValue){return false;}
    bool NodeValue::setValue(NodeValue newValue){return false;}
    bool NodeValue::setValue(void* newValue){return false;}

    //-----------------------Set Value Methods END-----------------------
	//-----------------------General node value operators for overide BEGIN-----------------------

    ValueType NodeValue::getType(){return ValueType::Float;}

    std::string NodeValue::toString(){return "";}

    void* NodeValue::getValue(){return NULL;}

    float NodeValue::toFloat(){return 0.0;}

    int NodeValue::toInt(){return 0;}

    bool NodeValue::isNumeric(){return false;}

    bool NodeValue::isContinous(){return false;}

    bool NodeValue::isDiscrete(){return false;}

    unsigned int NodeValue::toHash(){return 0;}

	//-----------------------General node value operators for overide END-----------------------
    //-----------------------Object Operators Methods BEGIN-----------------------

    bool NodeValue::operator==(NodeValue* rightSide){return false;}

    bool NodeValue::operator==(float rightSide){return false;}

    bool NodeValue::operator==(int rightSide){return false;}

    bool NodeValue::operator==(char* rightSide){return false;}

    bool NodeValue::operator==(std::string rightSide){return false;}

    bool NodeValue::operator==(void* rightSide){return false;}


    bool NodeValue::operator!=(NodeValue* rightSide){return false;}
    bool NodeValue::operator!=(float rightSide){return false;}

    bool NodeValue::operator!=(int rightSide){return false;}

    bool NodeValue::operator!=(char* rightSide){return false;}

    bool NodeValue::operator!=(std::string rightSide){return false;}

    bool NodeValue::operator!=(void* rightSide){return false;}



    bool NodeValue::operator<(NodeValue* rightSide){return false;}
    
    bool NodeValue::operator<(float rightSide){return false;}

    bool NodeValue::operator<(int rightSide){return false;}

    bool NodeValue::operator<(char* rightSide){return false;}

    bool NodeValue::operator<(std::string rightSide){return false;}

    bool NodeValue::operator<(void* rightSide){return false;}



    bool NodeValue::operator>(NodeValue* rightSide){return false;}
    
    bool NodeValue::operator>(float rightSide){return false;}

    bool NodeValue::operator>(int rightSide){return false;}

    bool NodeValue::operator>(char* rightSide){return false;}

    bool NodeValue::operator>(std::string rightSide){return false;}

    bool NodeValue::operator>(void* rightSide){return false;}



    bool NodeValue::operator<=(NodeValue* rightSide){return false;}

    bool NodeValue::operator<=(float rightSide){return false;}

    bool NodeValue::operator<=(int rightSide){return false;}

    bool NodeValue::operator<=(char* rightSide){return false;}

    bool NodeValue::operator<=(std::string rightSide){return false;}

    bool NodeValue::operator<=(void* rightSide){return false;}



    bool NodeValue::operator>=(NodeValue* rightSide){return false;}

    bool NodeValue::operator>=(float rightSide){return false;}

    bool NodeValue::operator>=(int rightSide){return false;}

    bool NodeValue::operator>=(char* rightSide){return rightSide;}

    bool NodeValue::operator>=(std::string rightSide){return false;}

    bool NodeValue::operator>=(void* rightSide){return false; }





    NodeValue NodeValue::operator+(NodeValue* rightSide){return rightSide;}

    float NodeValue::operator+(float rightSide){return 0;}

    float NodeValue::operator+(int rightSide){return 0;}

    std::string NodeValue::operator+(std::string rightSide){return "";}

    void* NodeValue::operator+(void* rightSide){return rightSide;}



    NodeValue NodeValue::operator-(NodeValue* rightSide){return NodeValue();}

    float NodeValue::operator-(float rightSide){return 0;}

    float NodeValue::operator-(int rightSide){return 0;}

    void* NodeValue::operator-(void* rightSide){return NULL; }



    NodeValue NodeValue::operator*(NodeValue* rightSide){return rightSide;}
    
    float NodeValue::operator*(float rightSide){return 0;}

    float NodeValue::operator*(int rightSide){return 0;}

    void* NodeValue::operator*(void* rightSide){return NULL;}



    NodeValue NodeValue::operator/(NodeValue* rightSide)
    {return NodeValue();}
    
    float NodeValue::operator/(float rightSide){return 0.0;}

    float NodeValue::operator/(int rightSide){return 0;}

    void* NodeValue::operator/(void* rightSide){return NULL;}

    

    NodeValue NodeValue::operator%(NodeValue* rightSide){return NodeValue();}
    
    float NodeValue::operator%(float rightSide){return 0.0;}

    float NodeValue::operator%(int rightSide){return 0;}

    void* NodeValue::operator%(void* rightSide){return NULL;}

    //-----------------------Object Operators Methods END-----------------------
}