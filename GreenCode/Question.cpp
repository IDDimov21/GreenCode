#include "Question.h"

Question::Question(const std::string& text, const std::string& correctAnswer)
    : text(text), correctAnswer(correctAnswer) {
}

const std::string& Question::getText() const {
    return text;
}

const std::string& Question::getCorrectAnswer() const {
    return correctAnswer;
}
