#pragma once
#include <iostream>
#include <cstring>

class string
{
public:
    string(const char* m_other); 
    string();
    string(char*&& ptr);
    //string(string& str) = delete;
    ~string();

    int length();

    friend std::ostream& operator<<(std::ostream& stream, string& str) { stream << str.m_data; return stream; }
    
    friend string operator+(string& string1, string& string2)
    {
        int string1_size = string1.calculate_size(string1.m_data),string2_size = string2.calculate_size(string2.m_data);

        char* str = new char(string1_size + string2_size + 1); str[string1_size + string2_size + 1] = '\0';
        strcat(str,string1.m_data);
        strcat(str,string2.m_data);
        
        
        string result(std::move(str));
        //string1.~string();
        //string2.~string();
        return result;
    }
/*
    friend string operator+(const char* string1, string new_str)
    {
        int total_size = new_str.calculate_size(string1) + new_str.calculate_size(new_str.m_data);
    }
*/
    explicit operator const char*() const { return m_data; }
private:
    int calculate_size(const char* m_other);
    char* m_data;
    int m_size;
    bool m_data_mem;
};
