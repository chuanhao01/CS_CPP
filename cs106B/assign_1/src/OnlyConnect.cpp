/* File: OnlyConnect.cpp
 *
 * TODO: Edit these comments to describe anything interesting or noteworthy in your implementation.
 *
 * TODO: Edit these comments to leave a puzzle for your section leader to solve!
 */
#include "OnlyConnect.h"
#include "Testing/OnlyConnectTests.h"

using namespace std;

string onlyConnectize(string phrase) {
    // In this function we will remove the vowels and any other none alphabets characters in the string, then turn all the characters into uppercase
    if(phrase == ""){
        return "";
    }
    else{
        if(isalpha(phrase[0])){
            // Checking if the current char is ann alphabet
            // Get the cureent char in upper case
            char current_char = putchar(toupper(phrase[0]));
            if(current_char == 'A' || current_char == 'E' || current_char == 'I' || current_char == 'O' || current_char == 'U'){
                // if the char is a vowel, remove it
                return "" + onlyConnectize(phrase.substr(1));
            }
            else{
                return current_char + onlyConnectize(phrase.substr(1));
            }
        }
        else{
            return "" + onlyConnectize(phrase.substr(1));
        }
    }
}






/* * * * * * Test Cases * * * * * */

ADD_TEST("Converts lower-case to upper-case.") {
    EXPECT_EQUAL(onlyConnectize("lowercase"), "LWRCS");
    EXPECT_EQUAL(onlyConnectize("uppercase"), "PPRCS");
}

ADD_TEST("Handles non-letter characters properly.") {
    EXPECT_EQUAL(onlyConnectize("2.718281828459045"), "");
    EXPECT_EQUAL(onlyConnectize("'Hi, Mom!'"), "HMM");
}

ADD_TEST("Handles single-character inputs.") {
    EXPECT_EQUAL(onlyConnectize("A"), "");
    EXPECT_EQUAL(onlyConnectize("+"), "");
    EXPECT_EQUAL(onlyConnectize("Q"), "Q");
}

/* TODO: You will need to add your own tests into this suite of test cases. Think about the sorts
 * of inputs we tested here, and, importantly, what sorts of inputs we *didn't* test here. Some
 * general rules of testing:
 *
 *    1. Try extreme cases. What are some very large cases to check? What are some very small cases?
 *
 *    2. Be diverse. There are a lot of possible inputs out there. Make sure you have tests that account
 *       for cases that aren't just variations of one another.
 *
 *    3. Be sneaky. Don't just try standard inputs. Try weird ones that you wouldn't expect anyone to
 *       actually enter, but which are still perfectly legal.
 *
 * Happy testing!
 */






