#include<iostream>
#include<string>
#include<ostream>
#include<fstream>
#include"CredentialsManagement.h"
#include"Quiz.h"


void Author::show_Student(std::string filename)
{
   
    std::string strUserFName; //extract username from files
    std::string strFPassword;//exytract password from files
    std::string strData;


    std::fstream studentDetails;
    studentDetails.open(filename);

    if (!studentDetails)  //file exists or not
    {
        std::cout << "Error in  genrating file !";
    }
    else
    {
       
        while (getline(studentDetails, strData)) {
            studentDetails >> strUserFName;
            studentDetails >> strFPassword;

             std::cout<<strUserFName<< std::endl;
             std::cout<<strFPassword<< std::endl;

        }
       

    }
    studentDetails.close(); // Close the file
}

void Author::Show_Question(std::string filename)
{
    
    std::string strQuestion;
    std::string strOption_A;
    std::string strOption_B;
    std::string strOption_c;
    std::string strOption_D;
    std::string strAnswer;

    std::ifstream QuizFile;
    QuizFile.open(filename);

    if (!QuizFile)
    {
        std::cout << "file doesn't Exist !";
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
            std::cout << "Answer:- " << strAnswer << std::endl;
        }
    }
    QuizFile.close();

}




