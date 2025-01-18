#include<iostream>
#include<string>
#include<vector>
#include<ostream>
#include<fstream>
#include"Quiz.h"
#include<algorithm>
#include<random>
#include<ctime>

void Quiz::CreateQuiz(std::string filename)
{
    std::string strQuestion;
    std::string strOption_A;
    std::string strOption_B;
    std::string strOption_c;
    std::string strOption_D;
    std::string strAnswer;
    

    std::ofstream QuizFile;  //connect studentDetails to the file "Student_Id_Password.txt"
    QuizFile.open(filename, std::ios::app);

    if (!QuizFile)
    {
        std::cout << "file doesnt Exist !";
    }
    else
    {
        for (int i = 0; i < 15; i++)
        {
            std::cout << " Enter question:- ";
            std::cin.ignore(); // Clear input buffer
            std::getline(std::cin, strQuestion);     //take whole line as input

            std::cout << "enter option A:-";
            //std::cin.ignore(); // Clear input buffer
            std::getline(std::cin, strOption_A);

            std::cout << " Enter option B:- ";
            // std::cin.ignore(); // Clear input buffer
            std::getline(std::cin, strOption_B);

            std::cout << "Enter option c:-";
            // std::cin.ignore(); // Clear input buffer
            std::getline(std::cin, strOption_c);

            std::cout << " Enter option D:- ";
            //std::cin.ignore(); // Clear input buffer
            std::getline(std::cin, strOption_D);

            std::cout << "Enter correct option :-";
            std::cin >> strAnswer;

            std::cout << strQuestion << std::endl;
            std::cout << strOption_A << std::endl;
            std::cout << strOption_B << std::endl;
            std::cout << strOption_c << std::endl;
            std::cout << strOption_D << std::endl;
            std::cout << strAnswer << std::endl;



            QuizFile << strQuestion << std::endl;
            QuizFile << strOption_A << std::endl;
            QuizFile << strOption_B << std::endl;
            QuizFile << strOption_c << std::endl;
            QuizFile << strOption_D << std::endl;
            QuizFile << strAnswer << std::endl;
        }

    }
    QuizFile.close(); // Close the file


    std::cout << "Data appended successfully." << std::endl; // Display a success message
    
}

/*int Quiz::TakeQuiz(std::string filename)
{
    std::string strQuestion;
    std::string strOption_A;
    std::string strOption_B;
    std::string strOption_c;
    std::string strOption_D;
    std::string strAnswer;
    std::string userAnswer;
    int ScoreCount = 0;

    std::ifstream QuizFile;
    QuizFile.open(filename);

    if (!QuizFile)
    {
        std::cout << "file doesnt Exist !";
    }
    else
    {
        while (getline(QuizFile, strQuestion))
        {
            getline(QuizFile, strOption_A);
            getline(QuizFile, strOption_B);
            getline(QuizFile, strOption_c);
            getline(QuizFile, strOption_D);
            getline(QuizFile, strAnswer);

            std::cout << "Que :- " << strQuestion << std::endl;
            std::cout << "A :- " << strOption_A << std::endl;
            std::cout << "B :- " << strOption_B << std::endl;
            std::cout << "C :- " << strOption_c << std::endl;
            std::cout << "D :- " << strOption_D << std::endl;

            std::cout << "answer:- ";
            std::cin >> userAnswer;

            if (strAnswer == userAnswer)
            {
                ScoreCount++;

            }
            
            
        }
    }
    return ScoreCount;
}*/

void Quiz::showResult(int num)
{
    std::cout << "Total Marks:- 15" << std::endl;
    std::cout << "you got :-" << num << std::endl;

    if (num > 13)
    {
        std::cout << "Awesome performance!";
    }
    else if (num > 10 && num < 13)
    {
        std::cout << " great job!";
    }
    else if (num > 6 && num < 10)
    {
        std::cout << " good ! ";
    }
    else
    {
        std::cout << "very poor Performance!"<<std::endl;
    }
}


std::vector<Quiz::Question>Quiz::LoadQuiz(std::string filename)
{
    std::vector<Question>Questions;
    std::ifstream QuizFile;
    QuizFile.open(filename);

    Question q;

    if (!QuizFile)
    {
        std::cout << "file doesnt Exist !";
        return Questions;
    }
    else
    {
        while (getline(QuizFile, q.question))
        {
            getline(QuizFile, q.optionA);
            getline(QuizFile, q.optionB);
            getline(QuizFile, q.optionC);
            getline(QuizFile, q.optionD);
            getline(QuizFile, q.answer);
            Questions.push_back(q);

        }
        
    }
    QuizFile.close();
    return Questions;

}

int Quiz::TakeQuiz(std::string filename)
{
    std::vector<Question>Questions = LoadQuiz(filename);
    std::string userAnswer;
    int ScoreCount = 0;
    

    if (Questions.empty())
    {
        return -1;
            
    }

    
    srand(unsigned(std::time(0)));// initializing the random generator using seed value
    //std::cout << std::time(0);

    
    std::random_shuffle(Questions.begin(), Questions.end()); //sufffle the data randomly

   

    for (int i = 0; i < Questions.size(); i++)
    {
        std::cout << "Que :- " << Questions[i].question << std::endl;
        std::cout << "A :- " << Questions[i].optionA << std::endl;
        std::cout << "B :- " << Questions[i].optionB << std::endl;
        std::cout << "C :- " << Questions[i].optionC << std::endl;
        std::cout << "D :- " << Questions[i].optionD << std::endl;
       // std::cout << "D :- " << Questions[i].answer << std::endl;

        std::cout << "answer:- ";
        std::cin >> userAnswer;

        if (Questions[i].answer == userAnswer)
        {
            ScoreCount++;

        }
    }
    return ScoreCount;
}


