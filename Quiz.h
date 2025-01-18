#pragma once
#include<iostream>
#include<string>
#include<vector>

class Quiz
{
public:
    void CreateQuiz(std::string filename);
    int TakeQuiz(std::string filename);
    void showResult(int num);

private:
    struct Question {
        std::string question;
        std::string optionA;
        std::string optionB;
        std::string optionC;
        std::string optionD;
        std::string answer;
    };

    std::vector<Question> LoadQuiz(const std::string filename);
   
};

