// Lexical Analyzer.cpp 
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <fstream>
#include <sstream>
//#include "functions.h"


// create gobal scope enum variable to define token types
enum tokenType
{
    keyWord, identifier, num, addOp, mulOp, relOp, andType, orType, notType, lPar, rPar,
    lBrac, rBrack, lBrace, rBrace, undefined
};

/* create a structure to hold token values
   these will be used for function reading
*/

struct token
{
    tokenType type;
    std::string value;
};

// function used to analyze tokens
tokenType tokenAnalyzer(const std::string& token)
{
    /* we will begin by checking for all the different token types we want
       using if/else beginning with keyword
    */
    if (token == "while" || token == "if" || token == "else" || token == "return"
        || token == "break" || token == "continue" || token == "int" || token ==
        "float" || token == "void")
    {
        return keyWord;
    }
    else
    {
        std::cout << "Placeholder" << std::endl;
        return undefined;
    }

}

int main()
{

    // tokenAnalyzer(test);

    std::cout << "placeholder" << std::endl;

    return 0;
}

