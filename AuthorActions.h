#pragma once
#include<iostream>
#include<string>
#include"CredentialsManagement.h"
#include"Quiz.h"

void Author_call()   // Author screen option (Author page)
{
    std::system("cls");
    int choice;
    int Score = 0;
    bool CheckUserAccess = false;
    Author t1;



    //Quiz Quiz1;     //creating quiz object


    do
    {

        std::cout << "1 -> Author login!" << std::endl;
        std::cout << "2 -> Author New Registration!" << std::endl;
        std::cout << "3 -> Back menu" << std::endl;
        std::cout << "4 -> Exit!" << std::endl;
        std::cin >> choice;

        switch (choice)
        {
        case 1:

            std::system("cls");

            CheckUserAccess = t1.userAuthentication("Author_Id_Password.txt");

            if (CheckUserAccess == true)
            {
                std::cout << "Login Sucess full!" << std::endl;
                std::system("cls");

                /* std::cout << "1:- Creat Exams !" << std::endl;
                 std::cout << "2:- Show Student Details:-" << std::endl;
                 std::cout << "3:- Show Test Question:-" << std::endl;

                 int userChoice = 0;

                 std::cout << "select one:- ";
                 std::cin >> userChoice;

                 switch (userChoice)
                 {
                     case 1:
                         int ChooseVar;
                         std::cout << "1:- Computer test-" << std::endl;
                         std::cout << "2:-Maths test-" << std::endl;
                         std::cout << "3:- Python test-" << std::endl;
                         std::cout << "4:-OOPS test-" << std::endl;
                         std::cout << "5:- GeneralKnowledge test-" << std::endl;
                         std::cout << "6:- exit-" << std::endl;
                         std::cout << "Choose option:-";
                         std::cin >> ChooseVar;



                         switch (ChooseVar)
                         {
                         case 1:

                             Quiz1.CreateQuiz("Computer.txt");
                             std::system("cls");

                             break;

                         case 2:

                             Quiz1.CreateQuiz("Maths.txt");
                             std::system("cls");

                             break;

                         case 3:

                             Quiz1.CreateQuiz("Python.txt");
                             std::system("cls");

                             break;

                         case 4:

                              Quiz1.CreateQuiz("OOPS.txt");
                             std::system("cls");

                             break;

                         case 5:

                             Quiz1.CreateQuiz("generalKnowledge.txt");
                             std::system("cls");

                             break;



                         default:

                             std::cout << "entered a Wrong test!";

                         }

                         break;

                     case 2:
                         show_Student("Student_Id_Password.txt");
                         break;

                     case 3:
                         int ChooseShowVar;
                         std::cout << "1:- Computer test-" << std::endl;
                         std::cout << "2:-Maths test-" << std::endl;
                         std::cout << "3:- Python test-" << std::endl;
                         std::cout << "4:-OOPS test-" << std::endl;
                         std::cout << "5:- GeneralKnowledge test-" << std::endl;
                         std::cout << "6:- exit-" << std::endl;
                         std::cout << "Choose option:-";
                         std::cin >> ChooseShowVar;



                         switch (ChooseShowVar)
                         {
                         case 1:

                             Show_Question("Computer.txt");


                             break;

                         case 2:

                             Show_Question("Maths.txt");


                             break;

                         case 3:

                             Show_Question("Python.txt");


                             break;

                         case 4:

                             Show_Question("OOPS.txt");


                             break;

                         case 5:

                             Show_Question("generalKnowledge.txt");


                             break;



                         default:

                             std::cout << "entered a Wrong test!";

                         }



                 }*/
                Author_Option1();

            }
            else
            {
                std::cout << "kindly try to login again!" << std::endl;
                break;
            }
            break;

        case 2:

            std::system("cls");
            t1.creatUser("Author_Id_Password.txt");
            break;

        case 3:
            main_call();

        case 4:
            exit(0);
            break;




        default:
            std::cout << "You entered a wrong option!" << std::endl;
            break;

        }
    } while (choice != 4);
}


void Author_Option1()  // Author option one(Login page)
{
    std::system("cls");
    // Quiz Quiz1;
    Author t1;
    std::cout << "1:- Creat Exams !" << std::endl;
    std::cout << "2:- Show Student Details:-" << std::endl;
    std::cout << "3:- Show Test Question:-" << std::endl;
    std::cout << "4:- Back menu:-" << std::endl;
    std::cout << "5:- main menu:-" << std::endl;


    int userChoice = 0;

    std::cout << "select one:- ";
    std::cin >> userChoice;

    switch (userChoice)
    {
    case 1:
        Author_option1_Label1();
        break;

    case 2:

        t1.show_Student("Student_Id_Password.txt");

        break;

    case 3:

        Author_option1_Label3();
        break;

    case 4:
        Author_call();
        break;

    case 5:

        main_call();
        break;

    default:

        std::cout << "you have entered a wrong option" << std::endl;
        break;
    }

}


void Author_option1_Label1() // Creat exams in Author page(Author>>login>>creat_exams
{
    std::system("cls");
    int ChooseVar;
    Quiz Quiz1;
    std::cout << "1:- Computer test-" << std::endl;
    std::cout << "2:- Maths test-" << std::endl;
    std::cout << "3:- Python test-" << std::endl;
    std::cout << "4:- OOPS test-" << std::endl;
    std::cout << "5:- GeneralKnowledge test-" << std::endl;
    std::cout << "6:- Back menu :-" << std::endl;
    std::cout << "7:- Main menu-" << std::endl;
    std::cout << "8:- exit-" << std::endl;
    std::cout << "Choose option:-";
    std::cin >> ChooseVar;



    switch (ChooseVar)
    {
    case 1:

        Quiz1.CreateQuiz("Computer.txt");
        std::system("cls");

        break;

    case 2:

        Quiz1.CreateQuiz("Maths.txt");
        std::system("cls");

        break;

    case 3:

        Quiz1.CreateQuiz("Python.txt");
        std::system("cls");

        break;

    case 4:

        Quiz1.CreateQuiz("OOPS.txt");
        std::system("cls");

        break;

    case 5:

        Quiz1.CreateQuiz("generalKnowledge.txt");
        std::system("cls");

        break;

    case 6:
        Author_Option1();
        break;

    case 7:
        main_call();
        break;

    case 8:
        exit(0);
        break;

    default:

        std::cout << "entered a Wrong test!";
        break;

    }
}


void Author_option1_Label3() // shows quewstions in Author page(Author >> login >> show test question)
{
    std::system("cls");
    int ChooseVar;
    Author t1;;
    std::cout << "1:- Computer test-" << std::endl;
    std::cout << "2:- Maths test-" << std::endl;
    std::cout << "3:- Python test-" << std::endl;
    std::cout << "4:- OOPS test-" << std::endl;
    std::cout << "5:- GeneralKnowledge test-" << std::endl;
    std::cout << "6:- Back menu :-" << std::endl;
    std::cout << "7:- Main menu-" << std::endl;
    std::cout << "8:- exit-" << std::endl;
    std::cout << "Choose option:-";
    std::cin >> ChooseVar;



    switch (ChooseVar)
    {
    case 1:

        t1.Show_Question("Computer.txt");
        std::system("cls");

        break;

    case 2:

        t1.Show_Question("Maths.txt");
        std::system("cls");

        break;

    case 3:

        t1.Show_Question("Python.txt");
        std::system("cls");

        break;

    case 4:

        t1.Show_Question("OOPS.txt");
        std::system("cls");

        break;

    case 5:

        t1.Show_Question("generalKnowledge.txt");
        std::system("cls");

        break;

    case 6:
        Author_Option1();
        break;

    case 7:
        main_call();
        break;

    case 8:
        exit(0);
        break;

    default:

        std::cout << "entered a Wrong test!";
        break;

    }
}
