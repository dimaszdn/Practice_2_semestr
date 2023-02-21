#pragma once
#include<string>
#include<vector>
#include<iostream>
#include<math.h>

class Scrambler
{
private:
    std::string m_str = "";
    std::vector<int> fibPosl;
    std::vector<std::string> sliceString;
    std::vector<int> key;
    bool fl = true;

public:
    Scrambler()
    {

    }

    ~Scrambler() {}

    void Split(std::vector<std::string>& v, std::string& str)
    {
        std::string tmp = "";
        for (int i = 0; i < str.size(); ++i)
        {
            if (str[i] != ' ')
                tmp += str[i];
            else
            {
                v.push_back(tmp);
                tmp = "";
            }
        }
        v.push_back(tmp);
    }

    void InputString()
    {
        std::cout << "Enter string:" << " ";
        std::getline(std::cin, m_str);
        for (int i = 0; i < m_str.size(); ++i)
        {
            if ((int)(char)m_str[i] >= 48 && (int)(char)m_str[i] <= 57)
            {
                std::cout << "Invalid string!" << "\n";
                fl = false;
                break;
            }
        }
    }

    void CorrectLength()
    {
        if (sliceString.size() > 30)
        {
            fl = false;
            std::cout << "Invalid length" << "\n";
        }
    }

    void InputKey()
    {
        std::cout << "Enter a key length of " << sliceString.size() << ": ";
        int number;
        while (std::cin >> number)
        {
            if ((!std::cin >> number) || (!isFibonacci(number)))
            {
                std::cout << "Is not a Fibonacci number or the wrong data type!" << "\n";
                fl = false;
                break;
            }
            else
                key.push_back(number);
            if (key.size() == sliceString.size())
            {
                break;
            }
        }
    }

    void Encode()
    {
        Split(sliceString, m_str);
        Fibonacci(fibPosl, sliceString.size());
        CorrectLength();
        if (fl)
            InputKey();
        if (fl)
        {
            for (int i = 0; i < key.size(); ++i)
            {
                for (int j = 0; j < fibPosl.size(); ++j)
                {
                    if (key[i] == fibPosl[j])
                    {
                        std::swap(fibPosl[i], fibPosl[j]);
                        std::swap(sliceString[i], sliceString[j]);
                    }
                }
            }
            std::cout << "Encode is complete!" << "\n";
            std::cout << "Your string: ";
            GetSliceString();
            std::cout << "\n";
        }
    }

    void Decode()
    {
        if (fl)
        {
            BubbleSort(fibPosl);
            std::vector<int> tmp = key;
            for (int i = 0; i < fibPosl.size(); ++i)
            {
                for (int j = 0; j < key.size(); ++j)
                {
                    if (fibPosl[i] == key[j]) {
                        std::swap(key[i], key[j]);
                        std::swap(sliceString[i], sliceString[j]);
                    }
                }
            }
            std::cout << "Decode is complete!" << "\n";
            std::cout << "Your string: ";
            GetSliceString();
            std::cout << "\n";
            key = tmp;
        }
    }

    void Fibonacci(std::vector<int>& v, size_t N)
    {
        v.push_back(1);
        v.push_back(2);
        for (int i = 2; i < N; ++i)
            v.push_back(v[i - 1] + v[i - 2]);
    }

    void GetSliceString()
    {
        for (int i = 0; i < sliceString.size(); ++i)
            std::cout << sliceString[i] << " ";
        //std::cout << "\n";
    }

    void GetKey()
    {
        if (fl)
        {
            std::cout << "Key: ";
            for (size_t i = 0; i < key.size(); ++i)
                std::cout << key[i] << " ";
            std::cout << "\n";
        }
    }

    bool isPerfectSquare(int x)
    {
        int s = sqrt(x);
        return (s * s == x);
    }

    bool isFibonacci(int n)
    {
        return isPerfectSquare(5 * n * n + 4) || isPerfectSquare(5 * n * n - 4);
    }

    void BubbleSort(std::vector<int>& values)
    {
        for (size_t i = 0; i + 1 < values.size(); ++i)
        {
            for (size_t j = 0; j + 1 < values.size() - i; ++j)
            {
                if (values[j + 1] < values[j])
                {
                    std::swap(values[j], values[j + 1]);
                }
            }
        }
    }
};

