#include "YouGotHufflepuff.h"
#include "Testing/YouGotHufflepuffTests.h"
using namespace std;

// Returns the float coeff value
float calculateCosCoeff(const HashMap<char, int>& personality_scores){
    const Vector<char> personality_model = {'O', 'C', 'E', 'A', 'N'};
    const int model_length = personality_model.size();
    float cos_coeff = 0;
    // Loop through all scores and calculate the cos sim
    for(int i=0; i<model_length; i++) {
        const char p_char = personality_model[i];
        cos_coeff += pow(personality_scores[p_char], 2);
    }
    return sqrt(cos_coeff);
}

// Returns the cosine similarity score of 2 people
float calculateCosSim(const HashMap<char, int>& p1, const HashMap<char, int>& p2){
    const Vector<char> personality_model = {'O', 'C', 'E', 'A', 'N'};
    const int model_length = personality_model.size();
    const float p1_coeff = calculateCosCoeff(p1), p2_coeff = calculateCosCoeff(p2);
    float cos_sim_score = 0;
    // Calculating the score here
    for(int i=0; i<model_length; i++){
        const char p_char = personality_model[i];
        const float p1_p_score = p1[p_char] / p1_coeff, p2_p_score = p2[p_char]  / p2_coeff;
        cos_sim_score += (p1_p_score * p2_p_score);
    }
    return cos_sim_score;
}

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

    // Basic check for error
    if(calculateCosCoeff(personality_score) == 0.0){
        displayMessage("Personality score is 0, error");
        return;
    }

    // Finding the closest person
    // Init some vars i am using later
    Person cloest_person;
    float cloest_score;
    HashSet<Person>check_people;
    // While not all people are checked yet
    while(check_people != people){
        // Getting a new person from people which we have not checked yet
        const HashSet<Person> people_to_check = people - check_people;
        const Person person_to_check = people_to_check.first();

        // Check if the person personailty score is the closest so far
        if(check_people.isEmpty()){
            // Base case for first person
            cloest_person = person_to_check;
            cloest_score = calculateCosSim(personality_score, person_to_check.scores);
        }
        else{
            // Calculate the sim score and check if it is the largest so far
            const float check_sim_score = calculateCosSim(personality_score, person_to_check.scores);
            if(check_sim_score > cloest_score){
                cloest_person = cloest_person;
                cloest_score = check_sim_score;
            }
        }

        // Adding the checked person to the end of the line
        check_people.add(person_to_check);
    }

    displayMessage("The person you are most like is: " + cloest_person.name);

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

ADD_TEST("Cos sim is 0.0") {
    HashMap<char, int> test_scores;
    test_scores.add('O', 0);
    test_scores.add('C', 0);
    test_scores.add('E', 0);
    test_scores.add('A', 0);
    test_scores.add('N', 0);
    float cos_sim = calculateCosCoeff(test_scores);
    EXPECT_EQUAL(cos_sim, 0.0);
}
