
// 
// #ifndef CREATSTUDENTIDPASSWORD_H
// #define CREATSTUDENTIDPASSWORD_H
#include<iostream>
#include<string>
#pragma once



class CreatUserIdPassword
{
public:
    
    bool userAuthentication(std::string filename);
    int creatUser(std::string filename);
};

class Student:public CreatUserIdPassword

{
   
};

class Author:public CreatUserIdPassword
{
    public:
     void Show_Question(std::string filename);
     void show_Student(std::string filename);
     
};

//#endif // CREATSTUDENTIDPASSWORD_H

