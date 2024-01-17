#pragma once
#ifndef DATAFRAMENODE
#define DATAFRAMENODE

#include <bitset>
#include <cstddef>

namespace DataPAC 
{
    template <typename T> T DataFrameNode(T Value) 
    {
    private:
        #pragma region  __________________________ Private ____________________________________
        #pragma region  __________________________ Properties ____________________________________

        T Value;

        #pragma endregion      
        #pragma region __________________________ Constructors __________________________


        

        #pragma endregion
        #pragma endregion         
    public:
        #pragma region  __________________________ Public ____________________________________
        #pragma region  __________________________ static ToByte methods ____________________________________

        static std::byte[] ToBytes(char value);

        static std::byte[] ToBytes(ushort value);

        static std::byte[] ToBytes(short value); 

        #pragma endregion
        #pragma region  __________________________ static FromBytes operators ____________________________________

        //returns true if successful, also populates value variable
        static bool FromBytes(std::byte[] bytes, char &value)

        static bool FromBytes(std::byte[] bytes, ushort &value)

        static bool FromBytes(std::byte[] bytes, ushort &value)

        #pragma endregion
        #pragma endregion

    }
}

#endif