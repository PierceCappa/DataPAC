#include "DPFloat.h"

namespace DataPAC
{

    #pragma region ____________ Methods _____________________________________________________________________________________________
    #pragma region >___________ Constructors ________________________________________________________________________________________


    DPFloat::DPFloat(){}

    DPFloat::DPFloat(char* newValue){
        try{
            this->Value = atof(newValue); 
        }
        catch(const std::exception& e)
        {
            this->Value = 0;
        }
    }

    DPFloat::DPFloat(float newValue){this->Value = newValue;}

    #pragma endregion
    #pragma region >___________ Node Value Virtual Methods __________________________________________________________________________
    #pragma region >>__________ Virtual Copy Constructor and Deconstructor __________________________________________________________


    DPFloat::~DPFloat(){}

    NodeValue* DPFloat::CreateNewNode(){return new DPFloat();}
    
    NodeValue* DPFloat::CreateNewNode(char* newValue, int length){return new DPFloat(newValue);}

    NodeValue* DPFloat::CreateNewNode(void* newValue)
    {
        try
        {
            return new DPFloat(*(float*)newValue);
        }
        catch(std::invalid_argument)
        {
            return NULL;
        }    
    }

    NodeValue* DPFloat::CreateNewNode(NodeValue newValue){return new DPFloat(newValue.toFloat());}

    NodeValue* DPFloat::CreateNewNode(int newValue){return new DPFloat(newValue);}

    NodeValue* DPFloat::CreateNewNode(float newValue){return new DPFloat(newValue);}

    NodeValue* DPFloat::CreateNewNode(std::string newValue){return new DPFloat(std::stof(newValue));}

    #pragma endregion
    #pragma region >>__________ Setters _____________________________________________________________________________________________


    bool DPFloat::setValue(std::string newValue)
    {
        try
        {
            this->Value = stof(newValue);
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }

    bool DPFloat::setValue(char* newValue)
    {
        try
        {
            this->Value = atof(newValue);
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }

    bool DPFloat::setValue(float newValue)
    {
        try
        {
            this->Value = newValue;
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }

    bool DPFloat::setValue(int newValue)
    {
        try
        {
            this->Value = newValue;
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }

    bool DPFloat::setValue(NodeValue* newValue)
    {
        try
        {
            this->Value = newValue->toFloat();
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }

    bool DPFloat::setValue(void* newValue)
    {
        try
        {
            this->Value = *(float*)newValue;
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }

    #pragma endregion
    #pragma region >>__________ NodeTypeOpertors ____________________________________________________________________________________

    ValueType DPFloat::GetType(){return ValueType::Float;}

    std::string DPFloat::toString(){return std::to_string(this->Value);}

    void* DPFloat::getValue(){return (void*)&this->Value;}

    float DPFloat::toFloat(){return this->Value;}

    int DPFloat::toInt(){return this->Value;}

    bool DPFloat::IsNumeric(){return true;}

    bool DPFloat::IsContinous(){return true;}

    bool DPFloat::IsDiscrete(){return false;}

    unsigned int DPFloat::toHash(){return this->Value;}

    #pragma endregion
    #pragma region >>__________ Logic Operators _____________________________________________________________________________________


    bool DPFloat::operator==(NodeValue* rightSide)
    {
        if(rightSide->IsNumeric())
        {
            return this->Value == rightSide->toFloat();
        }
        return false;
    }



    bool DPFloat::operator!=(NodeValue* rightSide)
    {
        if(rightSide->IsNumeric())
        {
            return  this->Value != rightSide->toFloat();
        }
        return true;
    }



    bool DPFloat::operator<(NodeValue* rightSide)
    {
        if(rightSide->IsNumeric())
        {
            return this->Value < rightSide->toFloat();
        }
        return false;
    }


    bool DPFloat::operator>(NodeValue* rightSide)
    {
        if(rightSide->IsNumeric())
        {
            return this->Value > rightSide->toFloat();
        }
        return false;
    }



    bool DPFloat::operator<=(NodeValue* rightSide)
    {
        if(rightSide->IsNumeric())
        {
            return this->Value <= rightSide->toFloat();
        }
        return false;
    }



    bool DPFloat::operator>=(NodeValue* rightSide)
    {
        if(rightSide->IsNumeric())
        {
            return this->Value >= rightSide->toFloat();
        }
        return false;
    }




    NodeValue DPFloat::operator+(NodeValue* rightSide)
    {
        if(rightSide->IsNumeric())
        {
            return DPFloat(this->Value + rightSide->toFloat());
        }
        return DPFloat((float)0);
    }



    NodeValue DPFloat::operator-(NodeValue* rightSide)
    {
        if(rightSide->IsNumeric())
        {
            return DPFloat(this->Value - rightSide->toFloat());
        }
        return DPFloat((float)0);        
    }



    NodeValue DPFloat::operator*(NodeValue* rightSide)
    {
        if(rightSide->IsNumeric())
        {
            return DPFloat(this->Value * rightSide->toFloat());
        }
        return DPFloat((float)0);              
    }




    NodeValue DPFloat::operator/(NodeValue* rightSide)
    {
        if(rightSide->IsNumeric())
        {
            return DPFloat(this->Value / rightSide->toFloat());
        }
        return DPFloat((float)0);              
    }

    

    NodeValue DPFloat::operator%(NodeValue* rightSide)
    {
        if(rightSide->IsNumeric())
        {
            return DPFloat();
        }
        return DPFloat((int)this->Value);              
    }

    #pragma endregion
    #pragma endregion
    #pragma endregion

}