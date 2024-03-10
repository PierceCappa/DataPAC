#include "NodeValue.h"


namespace DataPAC
{

    #pragma region ____________ Methods _________________________________________________________________________________________
    #pragma region >___________ Node Value General NodeValue::operators ____________________________________________________________________

    bool NodeValue::operator==(NodeValue* rightSide) 
    {
        switch(GetType())
        {
            case LongDouble: return ToLongDouble() == rightSide->ToLongDouble();
            case Double: return ToDouble() == rightSide->ToDouble();
            case Float: return ToFloat() == rightSide->ToFloat();
            case LongLong: return ToLongLong() == rightSide->ToLongLong();
            case ULongLong: return ToULongLong() == rightSide->ToULongLong();
            case Long: return ToLong() == rightSide->ToLong();
            case ULong: return ToULong() == rightSide->ToULong();
            case Int: return ToInt() == rightSide->ToInt();
            case UInt: return ToUInt() == rightSide->ToUInt();
            case Short: return ToShort() == rightSide->ToShort();
            case UShort: return ToUShort() == rightSide->ToUShort();
            case Char: return ToChar() == rightSide->ToChar();
            case String: return ToString() == rightSide->ToString();
            case Discrete: return ToInt() == rightSide->ToInt(); //we compare on discrete value inded, which is an int
            case Invalid: return false;
            default: return false;
        }
    }

    bool NodeValue::operator!=(NodeValue* rightSide)
    {
        switch(GetType())
        {
            case LongDouble: return ToLongDouble() != rightSide->ToLongDouble();
            case Double: return ToDouble() != rightSide->ToDouble();
            case Float: return ToFloat() != rightSide->ToFloat();
            case LongLong: return ToLongLong() != rightSide->ToLongLong();
            case ULongLong: return ToULongLong() != rightSide->ToULongLong();
            case Long: return ToLong() != rightSide->ToLong();
            case ULong: return ToULong() != rightSide->ToULong();
            case Int: return ToInt() != rightSide->ToInt();
            case UInt: return ToUInt() != rightSide->ToUInt();
            case Short: return ToShort() != rightSide->ToShort();
            case UShort: return ToUShort() != rightSide->ToUShort();
            case Char: return ToChar() != rightSide->ToChar();
            case String: return ToString() != rightSide->ToString();
            case Discrete: return ToInt() != rightSide->ToInt(); //we compare on discrete value inded, which is an int
            case Invalid: return false;
            default: return false;
        }
    }


    bool NodeValue::operator<(NodeValue* rightSide)
    {
        switch(GetType())
        {
            case LongDouble: return ToLongDouble() < rightSide->ToLongDouble();
            case Double: return ToDouble() < rightSide->ToDouble();
            case Float: return ToFloat() < rightSide->ToFloat();
            case LongLong: return ToLongLong() < rightSide->ToLongLong();
            case ULongLong: return ToULongLong() < rightSide->ToULongLong();
            case Long: return ToLong() < rightSide->ToLong();
            case ULong: return ToULong() < rightSide->ToULong();
            case Int: return ToInt() < rightSide->ToInt();
            case UInt: return ToUInt() < rightSide->ToUInt();
            case Short: return ToShort() < rightSide->ToShort();
            case UShort: return ToUShort() < rightSide->ToUShort();
            case Char: return ToChar() < rightSide->ToChar();
            case String: return ToString() < rightSide->ToString();
            case Discrete: return ToInt() < rightSide->ToInt(); //we compare on discrete value inded, which is an int
            case Invalid: return false;
            default: return false;
        }
    }

    bool NodeValue::operator>(NodeValue* rightSide)
    {
        switch(GetType())
        {
            case LongDouble: return ToLongDouble() > rightSide->ToLongDouble();
            case Double: return ToDouble() > rightSide->ToDouble();
            case Float: return ToFloat() > rightSide->ToFloat();
            case LongLong: return ToLongLong() > rightSide->ToLongLong();
            case ULongLong: return ToULongLong() > rightSide->ToULongLong();
            case Long: return ToLong() > rightSide->ToLong();
            case ULong: return ToULong() > rightSide->ToULong();
            case Int: return ToInt() > rightSide->ToInt();
            case UInt: return ToUInt() > rightSide->ToUInt();
            case Short: return ToShort() > rightSide->ToShort();
            case UShort: return ToUShort() > rightSide->ToUShort();
            case Char: return ToChar() > rightSide->ToChar();
            case String: return ToString() > rightSide->ToString();
            case Discrete: return ToInt() > rightSide->ToInt(); //we compare on discrete value inded, which is an int
            case Invalid: return false;
            default: return false;
        }
    }


    bool NodeValue::operator<=(NodeValue* rightSide)
    {
        switch(GetType())
        {
            case LongDouble: return ToLongDouble() <= rightSide->ToLongDouble();
            case Double: return ToDouble() <= rightSide->ToDouble();
            case Float: return ToFloat() <= rightSide->ToFloat();
            case LongLong: return ToLongLong() <= rightSide->ToLongLong();
            case ULongLong: return ToULongLong() <= rightSide->ToULongLong();
            case Long: return ToLong() <= rightSide->ToLong();
            case ULong: return ToULong() <= rightSide->ToULong();
            case Int: return ToInt() <= rightSide->ToInt();
            case UInt: return ToUInt() <= rightSide->ToUInt();
            case Short: return ToShort() <= rightSide->ToShort();
            case UShort: return ToUShort() <= rightSide->ToUShort();
            case Char: return ToChar() <= rightSide->ToChar();
            case String: return ToString() <= rightSide->ToString();
            case Discrete: return ToInt() <= rightSide->ToInt(); //we compare on discrete value inded, which is an int
            case Invalid: return false;
            default: return false;
        }
    }

    bool NodeValue::operator>=(NodeValue* rightSide)
    {
        switch(GetType())
        {
            case LongDouble: return ToLongDouble() >= rightSide->ToLongDouble();
            case Double: return ToDouble() >= rightSide->ToDouble();
            case Float: return ToFloat() >= rightSide->ToFloat();
            case LongLong: return ToLongLong() >= rightSide->ToLongLong();
            case ULongLong: return ToULongLong() >= rightSide->ToULongLong();
            case Long: return ToLong() >= rightSide->ToLong();
            case ULong: return ToULong() >= rightSide->ToULong();
            case Int: return ToInt() >= rightSide->ToInt();
            case UInt: return ToUInt() >= rightSide->ToUInt();
            case Short: return ToShort() >= rightSide->ToShort();
            case UShort: return ToUShort() >= rightSide->ToUShort();
            case Char: return ToChar() >= rightSide->ToChar();
            case String: return ToString() >= rightSide->ToString();
            case Discrete: return ToInt() >= rightSide->ToInt(); //we compare on discrete value inded, which is an int
            case Invalid: return false;
            default: return false;
        }
    }

    NodeValue NodeValue::operator+(NodeValue* rightSide)
    { //todo, need to impliment other node value types to store values
        // switch(GetType())
        // {
        //     case LongDouble: return ToLongDouble() + rightSide->ToLongDouble();
        //     case Double: return ToDouble() + rightSide->ToDouble();
        //     case Float: return ToFloat() + rightSide->ToFloat();
        //     case LongLong: return ToLongLong() + rightSide->ToLongLong();
        //     case ULongLong: return ToULongLong() + rightSide->ToULongLong();
        //     case Long: return ToLong() + rightSide->ToLong();
        //     case ULong: return ToULong() + rightSide->ToULong();
        //     case Int: return ToInt() + rightSide->ToInt();
        //     case UInt: return ToUInt() + rightSide->ToUInt();
        //     case Short: return ToShort() + rightSide->ToShort();
        //     case UShort: return ToUShort() + rightSide->ToUShort();
        //     case Char: return ToChar() + rightSide->ToChar();
        //     case String: return ToString() + rightSide->ToString();
        //     case Discrete: return ToInt() + rightSide->ToInt(); //we compare on discrete value inded, which is an int
        //     case Invalid: return false;
        //     default: return false;
        // }
    }


    NodeValue NodeValue::operator-(NodeValue* rightSide)
    { //todo
        // switch(GetType())
        // {
        //     case LongDouble: return ToLongDouble() == rightSide->ToLongDouble();
        //     case Double: return ToDouble() == rightSide->ToDouble();
        //     case Float: return ToFloat() == rightSide->ToFloat();
        //     case LongLong: return ToLongLong() == rightSide->ToLongLong();
        //     case ULongLong: return ToULongLong() == rightSide->ToULongLong();
        //     case Long: return ToLong() == rightSide->ToLong();
        //     case ULong: return ToULong() == rightSide->ToULong();
        //     case Int: return ToInt() == rightSide->ToInt();
        //     case UInt: return ToUInt() == rightSide->ToUInt();
        //     case Short: return ToShort() == rightSide->ToShort();
        //     case UShort: return ToUShort() == rightSide->ToUShort();
        //     case Char: return ToChar() == rightSide->ToChar();
        //     case String: return ToString() == rightSide->ToString();
        //     case Discrete: return ToInt() == rightSide->ToInt(); //we compare on discrete value inded, which is an int
        //     case Invalid: return false;
        //     default: return false;
        // }
    }

    NodeValue NodeValue::operator*(NodeValue* rightSide)
    { //todo
        // switch(GetType())
        // {
        //     case LongDouble: return ToLongDouble() == rightSide->ToLongDouble();
        //     case Double: return ToDouble() == rightSide->ToDouble();
        //     case Float: return ToFloat() == rightSide->ToFloat();
        //     case LongLong: return ToLongLong() == rightSide->ToLongLong();
        //     case ULongLong: return ToULongLong() == rightSide->ToULongLong();
        //     case Long: return ToLong() == rightSide->ToLong();
        //     case ULong: return ToULong() == rightSide->ToULong();
        //     case Int: return ToInt() == rightSide->ToInt();
        //     case UInt: return ToUInt() == rightSide->ToUInt();
        //     case Short: return ToShort() == rightSide->ToShort();
        //     case UShort: return ToUShort() == rightSide->ToUShort();
        //     case Char: return ToChar() == rightSide->ToChar();
        //     case String: return ToString() == rightSide->ToString();
        //     case Discrete: return ToInt() == rightSide->ToInt(); //we compare on discrete value inded, which is an int
        //     case Invalid: return false;
        //     default: return false;
        // }
    }


    NodeValue NodeValue::operator/(NodeValue* rightSide)
    {//todo
        // switch(GetType())
        // {
        //     case LongDouble: return ToLongDouble() == rightSide->ToLongDouble();
        //     case Double: return ToDouble() == rightSide->ToDouble();
        //     case Float: return ToFloat() == rightSide->ToFloat();
        //     case LongLong: return ToLongLong() == rightSide->ToLongLong();
        //     case ULongLong: return ToULongLong() == rightSide->ToULongLong();
        //     case Long: return ToLong() == rightSide->ToLong();
        //     case ULong: return ToULong() == rightSide->ToULong();
        //     case Int: return ToInt() == rightSide->ToInt();
        //     case UInt: return ToUInt() == rightSide->ToUInt();
        //     case Short: return ToShort() == rightSide->ToShort();
        //     case UShort: return ToUShort() == rightSide->ToUShort();
        //     case Char: return ToChar() == rightSide->ToChar();
        //     case String: return ToString() == rightSide->ToString();
        //     case Discrete: return ToInt() == rightSide->ToInt(); //we compare on discrete value inded, which is an int
        //     case Invalid: return false;
        //     default: return false;
        // }
    }
    

    NodeValue NodeValue::operator%(NodeValue* rightSide)
    {//todo
        // switch(GetType())
        // {
        //     case LongDouble: return ToLongDouble() == rightSide->ToLongDouble();
        //     case Double: return ToDouble() == rightSide->ToDouble();
        //     case Float: return ToFloat() == rightSide->ToFloat();
        //     case LongLong: return ToLongLong() == rightSide->ToLongLong();
        //     case ULongLong: return ToULongLong() == rightSide->ToULongLong();
        //     case Long: return ToLong() == rightSide->ToLong();
        //     case ULong: return ToULong() == rightSide->ToULong();
        //     case Int: return ToInt() == rightSide->ToInt();
        //     case UInt: return ToUInt() == rightSide->ToUInt();
        //     case Short: return ToShort() == rightSide->ToShort();
        //     case UShort: return ToUShort() == rightSide->ToUShort();
        //     case Char: return ToChar() == rightSide->ToChar();
        //     case String: return ToString() == rightSide->ToString();
        //     case Discrete: return ToInt() == rightSide->ToInt(); //we compare on discrete value inded, which is an int
        //     case Invalid: return false;
        //     default: return false;
        // }
    }
    
    #pragma endregion
    #pragma region >___________ Node Value Methods ______________________________________________________________________
    #pragma region >>__________ Copy Constructor and Deconstructor ______________________________________________________

    void NodeValue::Deallocate() {}

    NodeValue* NodeValue::CreateNewNode() {}
    
    NodeValue* NodeValue::CreateNewNode(char* newValue, int length) {}

    NodeValue* NodeValue::CreateNewNode(std::string newValue) {}



    #pragma endregion
    #pragma region >>__________ NodeValue to C++ Fundemental Types ______________________________________________________________

    std::string ToString() {return "";}

    long double ToLongDouble() {return 0;}

    double ToDouble() {return 0;}

    float ToFloat() {return 0;}

    long long ToLongLong() {return 0;}

    unsigned long long ToULongLong() {return 0;}

    long ToLong() {return 0;}

    unsigned long ToULong() {return 0;}

    int ToInt() {return 0;}

    unsigned int ToUInt() {return 0;}

    short ToShort() {return 0;}

    unsigned short ToUShort() {return 0;}

    char ToChar() {return 0;}


    #pragma endregion
    #pragma region >>__________ Node Value Informational ________________________________________________________________________

    //returns a string of the current node type. Each node type should have a const string defined. returns "standardNode"
    ValueType GetType() {return Invalid;}

    bool IsNumeric() {return false;}

    bool IsContinous() {return false;}

    bool IsDiscrete() {return false;}

    #pragma endregion
    #pragma endregion
    #pragma endregion
}