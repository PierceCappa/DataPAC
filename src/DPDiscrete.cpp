#include "DPDiscrete.h"


namespace DataPAC
{
    #pragma region ____________ Methods _____________________________________________________________________________________________
    #pragma region >___________ Constructors ________________________________________________________________________________________

    DPDiscrete::DPDiscrete(){this->createHashTable(200);}

    DPDiscrete::DPDiscrete(char* newValue, std::vector<std::string*>* newHashTable){this->hashTable = newHashTable; this->storeValue(newValue);}

    DPDiscrete::DPDiscrete(std::string newValue, std::vector<std::string*>* newHashTable){this->hashTable = newHashTable; this->storeValue(newValue);}

    DPDiscrete::DPDiscrete(int newValue, std::vector<std::string*>* newHashTable){this->hashTable = newHashTable; this->Value = newValue;}

    DPDiscrete::DPDiscrete(DPDiscrete* newValue){this->hashTable = newValue->hashTable; this->Value = newValue->Value;}

    #pragma endregion
    #pragma region >___________ Node Value Virtual Methods __________________________________________________________________________
    #pragma region >>__________ Virtual Copy Constructor and Deconstructor __________________________________________________________


    DPDiscrete::~DPDiscrete(){}

    NodeValue* DPDiscrete::createNewNode(){return new DPDiscrete();}
    
    NodeValue* DPDiscrete::createNewNode(char* newValue, int length){return new DPDiscrete(newValue, this->hashTable);}

    NodeValue* DPDiscrete::createNewNode(std::string newValue){return new DPDiscrete(newValue, this->hashTable);}

    NodeValue* DPDiscrete::createNewNode(int newValue){return new DPDiscrete(newValue, this->hashTable);}

    NodeValue* DPDiscrete::createNewNode(void* newValue){return new DPDiscrete(*(std::string*)newValue, this->hashTable);}

    NodeValue* DPDiscrete::createNewNode(NodeValue newValue){return new DPDiscrete(newValue.toString(), this->hashTable);}

    NodeValue* DPDiscrete::createNewNode(float newValue){return new DPDiscrete(newValue, this->hashTable);}

    #pragma endregion
    #pragma region >>__________ Setters _____________________________________________________________________________________________

    bool DPDiscrete::setValue(std::string newValue)
    {
        try
        {
            this->storeValue(newValue);
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }

    bool DPDiscrete::setValue(char* newValue)
    {
        try
        {
            this->storeValue(newValue);
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }

    bool DPDiscrete::setValue(float newValue)
    {
        try
        {
            this->storeValue(std::to_string(newValue));
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }

    bool DPDiscrete::setValue(int newValue)
    {
        try
        {
            this->storeValue(std::to_string(newValue));
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }

    bool DPDiscrete::setValue(NodeValue* newValue)
    {
        try
        {
            this->storeValue(newValue->toString());
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }

    bool DPDiscrete::setValue(void* newValue)
    {
        try
        {
            this->storeValue(*(std::string*)newValue);
            return true;
        }
        catch(std::invalid_argument)
        {
            return false;
        }
    }

    #pragma endregion
    #pragma region >>__________ NodeTypeOpertors ____________________________________________________________________________________


    ValueType DPDiscrete::getType(){ return Discrete; }

    std::string DPDiscrete::toString(){ return this->getString(this->Value); }

    void* DPDiscrete::getValue(){return (void*)&this->Value;}

    float DPDiscrete::toFloat(){return this->Value;}

    int DPDiscrete::toInt(){return this->Value;}

    bool DPDiscrete::isNumeric(){return false;}

    bool DPDiscrete::isContinous(){return false;}

    bool DPDiscrete::isDiscrete(){return true;}

    unsigned int DPDiscrete::toHash(){return this->hash(*(*this->hashTable)[this->Value]);}


    #pragma endregion
    #pragma region >>__________ Logic Operators _____________________________________________________________________________________


    bool DPDiscrete::operator==(NodeValue* rightSide)
    {
        if(rightSide->isDiscrete())
        {
            return this->Value == rightSide->toInt();
        }
        return false;
    }



    bool DPDiscrete::operator!=(NodeValue* rightSide)
    {
        if(rightSide->isDiscrete())
        {
            return this->Value != rightSide->toInt();
        }
        return true;
    }


    bool DPDiscrete::operator<(NodeValue* rightSide)
    {
        if(rightSide->isDiscrete())
        {
            return this->Value < rightSide->toInt();
        }
        return false;
    }



    bool DPDiscrete::operator>(NodeValue* rightSide)
    {
        if(rightSide->isDiscrete())
        {
            return this->Value > rightSide->toInt();
        }
        return false;
    }



    bool DPDiscrete::operator<=(NodeValue* rightSide)
    {
        if(rightSide->isDiscrete())
        {
            return this->Value <= rightSide->toInt();
        }
        return false;
    }




    bool DPDiscrete::operator>=(NodeValue* rightSide)
    {
        if(rightSide->isDiscrete())
        {
            return this->Value >= rightSide->toInt();
        }
        return false;
    }





    NodeValue DPDiscrete::operator+(NodeValue* rightSide){return DPDiscrete(this);}


    NodeValue DPDiscrete::operator-(NodeValue* rightSide){return DPDiscrete(this);}



    NodeValue DPDiscrete::operator*(NodeValue* rightSide){return DPDiscrete(this);}
    


    NodeValue DPDiscrete::operator/(NodeValue* rightSide){return DPDiscrete(this);}
    
    

    NodeValue DPDiscrete::operator%(NodeValue* rightSide){return DPDiscrete(this);}

    #pragma endregion
    #pragma endregion
    #pragma region >__________ Discrete Operators ___________________________________________________________________________________


    //Using this hash: http://www.cse.yorku.ca/~oz/hash.html
    //Thanks Dan Bernstein
    unsigned int DPDiscrete::hash(std::string input)
    {
        unsigned int hash = 5381;
        int c;
        int i = 0;
        for(int i = 0; i < input.size(); i++)
        {
            c = input.size();
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
        }
        return hash; 
    }

    bool DPDiscrete::findString(unsigned int& hashIndex, std::string aString)
    {
        hashIndex = hashIndex % this->hashTable->size();
        while((*this->hashTable)[hashIndex] != NULL)
        {
            if(aString == *(*this->hashTable)[hashIndex])
            {
                return true;
            }
            hashIndex++;
            hashIndex %= this->hashTable->size();
        }
        return false;
    }

    unsigned int DPDiscrete::addStringToTable(unsigned int& hashIndex, std::string* aString)
    {
        if((*this->hashTable)[hashIndex] == NULL)
        {
            (*this->hashTable)[hashIndex] = aString;
        }
        return false;
    }

    std::string DPDiscrete::getString(int index)
    {
        return *(*this->hashTable)[index];
    }

    void DPDiscrete::createHashTable(int defaultNum)
    {
        this->hashTable = new std::vector<std::string*>();
        int DEFAULT_HASHTABLE_SIZE = 100;
        for(int i = 0; i < DEFAULT_HASHTABLE_SIZE; i++)
        {
            this->hashTable->push_back(NULL);
        }
    }

    void DPDiscrete::storeValue(std::string newValue)
    {
        unsigned int hashIndex = this->hash(newValue) % this->hashTable->size();
        bool found = this->findString(hashIndex, newValue);
        if(found)
        {
            this->Value = hashIndex;
        }
        else
        {
            this->addStringToTable(hashIndex, new std::string(newValue));
            this->Value = hashIndex;
        }
    }

    void DPDiscrete::clearDictionary()
    {
        for(int i = 0; i < this->hashTable->size(); i++)
        {
            free( (*this->hashTable)[i]);
            (*this->hashTable)[i] = NULL;
        }
    }

    void DPDiscrete::replaceHashValue(int valueIndex, std::string newValue)
    {
        if((*this->hashTable)[valueIndex] != NULL)
        {
            *(*this->hashTable)[valueIndex] = newValue;
        }
    }

    #pragma endregion
    #pragma endregion
}