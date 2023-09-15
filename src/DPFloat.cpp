#include "DPFloat.h"

namespace DataPAC
{

	//-----------------------Initialization Methods BEGIN-----------------------

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

    DPFloat::~DPFloat(){}

    NodeValue* DPFloat::createNewNode(){return new DPFloat();}
    
    NodeValue* DPFloat::createNewNode(char* newValue, int length){return new DPFloat(newValue);}

    NodeValue* DPFloat::createNewNode(void* newValue)
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

    NodeValue* DPFloat::createNewNode(NodeValue newValue){return new DPFloat(newValue.toFloat());}

    NodeValue* DPFloat::createNewNode(int newValue){return new DPFloat(newValue);}

    NodeValue* DPFloat::createNewNode(float newValue){return new DPFloat(newValue);}

    NodeValue* DPFloat::createNewNode(std::string newValue){return new DPFloat(std::stof(newValue));}

	//-----------------------Initialization Methods END-----------------------
    //-----------------------Set Value Methods BEGIN-----------------------

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

    //-----------------------Set Value Methods END-----------------------
	//-----------------------General node value operators for overide BEGIN-----------------------
    
    ValueType DPFloat::getType(){return ValueType::Float;}

    std::string DPFloat::toString(){return std::to_string(this->Value);}

    void* DPFloat::getValue(){return (void*)&this->Value;}

    float DPFloat::toFloat(){return this->Value;}

    int DPFloat::toInt(){return this->Value;}

    bool DPFloat::isNumeric(){return true;}

    bool DPFloat::isContinous(){return true;}

    bool DPFloat::isDiscrete(){return false;}

    unsigned int DPFloat::toHash(){return this->Value;}

	//-----------------------General node value operators for overide END-----------------------
    //-----------------------Object Operators Methods BEGIN-----------------------

    bool DPFloat::operator==(NodeValue* rightSide)
    {
        if(rightSide->isNumeric())
        {
            return this->Value == rightSide->toFloat();
        }
        return false;
    }

    bool DPFloat::operator==(float rightSide){return this->Value == rightSide;}

    bool DPFloat::operator==(int rightSide){return this->Value == rightSide;}

    bool DPFloat::operator==(char* rightSide){ return false; }

    bool DPFloat::operator==(std::string rightSide){ return false; }

    bool DPFloat::operator==(void* rightSide)
    {
        try
        {
            return this->Value == *(float*)rightSide;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }



    bool DPFloat::operator!=(NodeValue* rightSide)
    {
        if(rightSide->isNumeric())
        {
            return  this->Value != rightSide->toFloat();
        }
        return true;
    }

    bool DPFloat::operator!=(float rightSide){return rightSide != this->Value;}

    bool DPFloat::operator!=(int rightSide){return rightSide != this->Value;}

    bool DPFloat::operator!=(char* rightSide){return true;}

    bool DPFloat::operator!=(std::string rightSide){return true;}

    bool DPFloat::operator!=(void* rightSide)
    {
        try
        {
            return this->Value != *(float*)rightSide;
        }
        catch(std::invalid_argument)
        {
            return true;
        }
    }



    bool DPFloat::operator<(NodeValue* rightSide)
    {
        if(rightSide->isNumeric())
        {
            return this->Value < rightSide->toFloat();
        }
        return false;
    }
    
    bool DPFloat::operator<(float rightSide){return rightSide < this->Value;}

    bool DPFloat::operator<(int rightSide){return this->Value < rightSide;}

    bool DPFloat::operator<(char* rightSide){return false;}

    bool DPFloat::operator<(std::string rightSide){return false;}

    bool DPFloat::operator<(void* rightSide)
    {
        try
        {
            return this->Value < *(float*)rightSide;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }



    bool DPFloat::operator>(NodeValue* rightSide)
    {
        if(rightSide->isNumeric())
        {
            return this->Value > rightSide->toFloat();
        }
        return false;
    }
    
    bool DPFloat::operator>(float rightSide){return this->Value > rightSide;}

    bool DPFloat::operator>(int rightSide){return this->Value > rightSide;}

    bool DPFloat::operator>(char* rightSide){return false;}

    bool DPFloat::operator>(std::string rightSide){return false;}

    bool DPFloat::operator>(void* rightSide)
    {
        try
        {
            return this->Value > *(float*)rightSide;
        }
        catch(std::invalid_argument)
        {
            return false;
        }        
    }



    bool DPFloat::operator<=(NodeValue* rightSide)
    {
        if(rightSide->isNumeric())
        {
            return this->Value <= rightSide->toFloat();
        }
        return false;
    }

    bool DPFloat::operator<=(float rightSide){return this->Value <= rightSide;}

    bool DPFloat::operator<=(int rightSide){return this->Value <= rightSide;}

    bool DPFloat::operator<=(char* rightSide){return false;}

    bool DPFloat::operator<=(std::string rightSide){return false;}

    bool DPFloat::operator<=(void* rightSide)
    {
        try
        {
            return this->Value <= *(float*)rightSide;
        }
        catch(std::invalid_argument)
        {
            return false;
        }        
    }



    bool DPFloat::operator>=(NodeValue* rightSide)
    {
        if(rightSide->isNumeric())
        {
            return this->Value >= rightSide->toFloat();
        }
        return false;
    }

    bool DPFloat::operator>=(float rightSide){return this->Value >= rightSide;}

    bool DPFloat::operator>=(int rightSide){return this->Value >= rightSide;}

    bool DPFloat::operator>=(char* rightSide){return false;}

    bool DPFloat::operator>=(std::string rightSide){return false;}

    bool DPFloat::operator>=(void* rightSide)
    {
        try
        {
            return this->Value >= *(float*)rightSide;
        }
        catch(std::invalid_argument)
        {
            return false;
        }    
    }





    NodeValue DPFloat::operator+(NodeValue* rightSide)
    {
        if(rightSide->isNumeric())
        {
            return DPFloat(this->Value + rightSide->toFloat());
        }
        return DPFloat((float)0);
    }

    float DPFloat::operator+(float rightSide){return this->Value + rightSide;}

    float DPFloat::operator+(int rightSide){return this->Value + rightSide;}

    std::string DPFloat::operator+(std::string rightSide){return rightSide;}

    void* DPFloat::operator+(void* rightSide)
    {
        try
        {
            *(float*)rightSide += this->Value;
            return rightSide;
        }
        catch(std::invalid_argument)
        {
            return (void*)&this->Value;
        }    
    }



    NodeValue DPFloat::operator-(NodeValue* rightSide)
    {
        if(rightSide->isNumeric())
        {
            return DPFloat(this->Value - rightSide->toFloat());
        }
        return DPFloat((float)0);        
    }

    float DPFloat::operator-(float rightSide){return this->Value - rightSide;}

    float DPFloat::operator-(int rightSide){return this->Value - rightSide;}

    void* DPFloat::operator-(void* rightSide)
    {
        try
        {
            *(float*)rightSide -= this->Value;
            return rightSide;
        }
        catch(std::invalid_argument)
        {
            return (void*)&this->Value;
        }    
    }



    NodeValue DPFloat::operator*(NodeValue* rightSide)
    {
        if(rightSide->isNumeric())
        {
            return DPFloat(this->Value * rightSide->toFloat());
        }
        return DPFloat((float)0);              
    }
    
    float DPFloat::operator*(float rightSide){return this->Value * rightSide;}

    float DPFloat::operator*(int rightSide){return this->Value * rightSide;}

    void* DPFloat::operator*(void* rightSide)
    {
        try
        {
            *(float*)rightSide *= this->Value;
            return rightSide;
        }
        catch(std::invalid_argument)
        {
            return (void*)&this->Value;
        }    
    }




    NodeValue DPFloat::operator/(NodeValue* rightSide)
    {
        if(rightSide->isNumeric())
        {
            return DPFloat(this->Value / rightSide->toFloat());
        }
        return DPFloat((float)0);              
    }
    
    float DPFloat::operator/(float rightSide){return this->Value / rightSide;}

    float DPFloat::operator/(int rightSide){return this->Value / rightSide;}

    void* DPFloat::operator/(void* rightSide)
    {
        try
        {
            *(float*)rightSide /= this->Value;
            return rightSide;
        }
        catch(std::invalid_argument)
        {
            return (void*)&this->Value;
        }    
    }

    

    NodeValue DPFloat::operator%(NodeValue* rightSide)
    {
        if(rightSide->isNumeric())
        {
            return DPFloat();
        }
        return DPFloat((int)this->Value);              
    }
    
    float DPFloat::operator%(float rightSide){return (int)this->Value % (int)rightSide;}

    float DPFloat::operator%(int rightSide){return (int)this->Value % rightSide;}

    void* DPFloat::operator%(void* rightSide)
    {
        try
        {
            *(float*)rightSide = (int)this->Value % (int)*(float*)rightSide;
            return rightSide;
        }
        catch(std::invalid_argument)
        {
            return rightSide;
        }    
    }

    //-----------------------Object Operators Methods END-----------------------

}