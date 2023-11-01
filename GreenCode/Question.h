#ifndef QUESTION_H
#define QUESTION_H

#include <string>

class Question {
public:
    Question(const std::string& text, const std::string& correctAnswer);

    const std::string& getText() const;
    const std::string& getCorrectAnswer() const;

private:
    std::string text;
    std::string correctAnswer;
};

#endif
