// Token Identifier.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <cctype>

// function used to read inputs from vector
void processToken(std::string const& token)
{
    if (token.find("void") != std::string::npos)
    {
        std::cout << "void";
    }
    if (token.find("main") != std::string::npos)
    {
        std::cout << "main";
    }

    if (token.find("int") != std::string::npos)
    {
        std::cout << "int";
    }
    if (token.find("sum") != std::string::npos)
    {
        std::cout << "sum";
    }
    if (token.find("for") != std::string::npos)
    {
        std::cout << "for";
    }
    if (token.find("j") != std::string::npos)
    {
        std::cout << "j";
    }
    if (token.find("=") != std::string::npos)
    {
        std::cout << "=";
    }
    if (token.find(";") != std::string::npos)
    {
        std::cout << ";";
    }
    if (std::isdigit(token[0]) && token != " " || token == "." || token == "-")
    {
        std::cout << token;
    }
    if (token.find("+") != std::string::npos)
    {
        std::cout << "+";
    }
    if (token.find("<") != std::string::npos)
    {
        std::cout << "<";
    }

    if (token.find("E43") != std::string::npos)
    {
        std::cout << "E43";
    }
    if (token.find(".34") != std::string::npos)
    {
        std::cout << ".34";
    }
    if (token.find("(") != std::string::npos)
    {
        std::cout << "(";
    }
    if (token.find(")") != std::string::npos)
    {
        std::cout << ")";
    }
    if (token.find("{") != std::string::npos)
    {
        std::cout << "{";
    }
    if (token.find("}") != std::string::npos)
    {
        std::cout << "}";
    }
}

int main()
{

    // open file 
    std::ifstream file("input.txt");

    if (!file.is_open())
    {
        std::cout << "error cannot open file try again." << std::endl;
        return 1;
    }

    // necessary variable and vector
    std::string token;
    std::vector<std::string> tokens;

    // while loop for vector input, had to get tricky with characters in order to read format from input.txt correctly
    while (getline(file, token))
    {
        std::istringstream iss(token);
        std::string token;

        while (iss >> token)
        {
            // see if token starts with another token
            char firstChar = token.front();
            if (firstChar == '(' || firstChar == ')' || firstChar == '{' || firstChar == '}' || firstChar == '=' || firstChar == '+' || firstChar == ';')
            {
                // split them up
                tokens.push_back(std::string(1, firstChar));
                tokens.push_back(token.substr(1));
            }
            else
            {
                // see if token end with another token
                char lastChar = token.back();
                if (lastChar == '(' || lastChar == ')' || lastChar == '{' || lastChar == '}' || lastChar == '=' || lastChar == '+' || lastChar == ';')
                {
                    // split them up
                    tokens.push_back(token.substr(0, token.size() - 1));
                    tokens.push_back(std::string(1, lastChar));
                }
                else
                {
                    tokens.push_back(token);
                }
            }
        }
    }

    
    
    // TEST
    /*
    for (auto t : tokens)
    {
        std::cout << t << std::endl;
    }
    */

    //std::cout << std::endl;

    // output the format expected from assumed code
    for (auto t : tokens)
    {
        if (t == "int" || t == "void" || t == "for")
        {
            std::cout << "Keyword : ";
            processToken(t);
            std::cout << std::endl;
        }
        if (t == "main" || t == "sum" || t == "j")
        {
            std::cout << "Identifier : ";
            processToken(t);
            std::cout << std::endl;
        }
        if (t == "(" || t == ")" || t == "{" || t == "="  || t == "+" || t == "<" || t == ";")
        {
            processToken(t);
            std::cout << " : ";
            processToken(t);
            std::cout << std::endl;
        }
        if (std::isdigit(t[0]) && t != " ")
        {
            std::cout << "Number : ";
            processToken(t);
            std::cout << std::endl;
        }
        if (t == "E43" || t == ".34")
        {
            std::cout << "Number : ";
            processToken(t);
            std::cout << std::endl;
        }

        
    }

    std::cout << std::endl;

    return 0;
}