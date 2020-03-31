#include "YouGotHufflepuff.h"
#include "Testing/YouGotHufflepuffTests.h"
using namespace std;

void administerQuiz(const HashSet<Question>& questions,
                    int numQuestions,
                    const HashSet<Person>& people) {
    // Init hashmap of the score to keep track
    HashMap<char, int> personality_score;
    const Vector<char> personality_model = {'O', 'C', 'E', 'A', 'N'};
    int model_length = personality_model.size() ;
    for(int i=0; i<model_length; i++){
        personality_score[personality_model[i]] = 0;
    }
    // Init asked questions
    HashSet<Question> asked_questions;
    // Asking all the questions
    for(int i=0; i<numQuestions; i++){
        // Getting a random question from the set
        const HashSet<Question> questions_can_be_asked = questions - asked_questions;
        const Question random_question = randomElement(questions_can_be_asked);
        // Asking the question and getting the result
        const int result = askPersonalityQuestion(random_question) - 3;

        // Saving the result to the person personality score
        const HashMap<char, int> question_factors = random_question.factors;
        // Iterate through all options and check if its affected by the question
        for(int j=0; j<model_length; j++){
            // Getting the personality model char
            const char p_char = personality_model[j];
            // Contains the personality model
            if(question_factors.containsKey(p_char)){
                // Getting the multiplier for the personality from the question
                const int score_multiplier = question_factors[p_char];
                // Updating the personality score
                personality_score[p_char] += score_multiplier * result;
            }
        }

        // Removing the question from the set
        asked_questions.add(random_question);
    }
    displayScores(personality_score);
}


/* * * * *   Test Cases Below This Point   * * * * */

/* Because administerQuiz is a function that requires interaction with the user,
 * you won't be able to directly test that administerQuiz returns the correct
 * values. Similarly, you can't call the askPersonalityQuestion, displayScores,
 * or displayMessage functions, as those are wired into the demo and don't
 * work in testing.
 *
 * However, you are welcome to add test cases to test any helper functions you
 * write! To do so, use the ADD_TEST macro to define tests, just as you did in
 * Assignment 1 and for Rising Tides.
 *
 * You aren't required to include test cases in this part of the assignment,
 * though we definitely would encourage you to do so! This is a multistep
 * assignment that's going to require each individual function to work
 * correctly, and adding tests for the functions you write is a great way to
 * find and fix bugs early on.
 */

