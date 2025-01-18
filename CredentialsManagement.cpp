#include "CredentialsManagement.h"

#include<iostream>
#include<fstream>
#include<string>


int CreatUserIdPassword::creatUser(std::string filename)
{
    //std::cout << "Create Student" << std::endl;
    /* char strName[30];
     char strPassword[8];

     ofstream studentDetails("Student_Id_Password.txt");  //connect studentDetails to the file "Student_Id_Password.txt"

     //read student detail
     std::cout<<" Enter Name:- ";
     std::cin>>strName;
     std::cout<<"enter password maximum of 8 character:-";
     std::cin>>strPassword;

     //write to file
     studentDetails<<strName<<" ";
     studentDetails<<strPassword;

     studentDetails.close();

     ifstream fin("Student_Id_Password.txt");
     //read details

     fin>>strName;
     fin>>strPassword;

     cout<<strName<<"     -"<<strPassword;*/


     std::string strName;
     std::string strPassword;
     std::string newData;

     std::ofstream UserDetails;  //connect studentDetails to the file "Student_Id_Password.txt"
     UserDetails.open(filename, std::ios::app);

     if(!UserDetails)
     {
         std::cout<<"file doesnt Exist !";
     }
     else
     {
         /*std::cout << " Enter Name:- ";
         std::cin>>strName;
         std::cout<<"enter password maximum of 8 character:-";
         std::cin>>strPassword;*/
         std::cout << " Enter Name:- ";
         std::cin.ignore(); // Clear input buffer
         std::getline(std::cin, strName);     //take whole line as input
         std::cout << "enter password maximum of 8 character:-";
        
         std::getline(std::cin, strPassword);     //take whole line as input

         newData = strName + " " +strPassword;

         UserDetails << newData << std::endl;

     }
     UserDetails.close(); // Close the file


     std::cout << "Data appended successfully." << std::endl; // Display a success message
    return 0;
}


bool CreatUserIdPassword::userAuthentication(std::string filename)
{
    std::string strName;       // for teke username from user
    std::string strPassword; // for take password from user
    std::string strUserFName; //extract username from files
    std::string strFPassword;//exytract password from files
    std::string strData;
    bool AuthSuccess = false;   //authentication sucess or not


    std::fstream UserDetails;
    UserDetails.open(filename);

    if(!UserDetails)  //file exists or not
    {
        std::cout<<"Error in  genrating file !";
    }
    else
    {
        std::cout<<"  UserName:- ";
        std::cin>>strName;
        std::cout<<"Password:-";
        std::cin>>strPassword;

       // int linenumber = 0;

        while (getline(UserDetails, strData)) {
            //linenumber++;
           // std::cout << linenumber << std::endl;
            UserDetails >>strUserFName>>strFPassword;
           // UserDetails >>strFPassword;

           // std::cout<<strUserFName<< std::endl;
           // std::cout<<strFPassword<< std::endl;

            

            if(strUserFName != strName  &&  strFPassword != strPassword)
            {
                std::cout<<"userName and password are wrong"<<std::endl;
                break;
            }
            else if(strUserFName == strName  )
            {
                if( strFPassword == strPassword)
                {
                    //std::cout << "authentication successfull!" << std:: endl;
                    AuthSuccess = true;
                    break;
                }
                else
                {
                    std::cout<<"wrong Password!"<<std::endl;
                    break;
                }


            }
            else
            {
                std::cout<<"wrong user name!"<<std::endl;
                break;
            }

        }
        if(AuthSuccess == false)
        {
            std::cout<<std::endl <<"Authentication fails!"<<std::endl;
            std::cout<<"try to login again!"<< std::endl;
            std::cout<<"or creat a new user"<< std::endl<< std::endl;

        }

    }
    UserDetails.close(); // Close the file
    return AuthSuccess;

}


/*int main()
{
    bool checkSucessLogin = true;
    CreatStudentIdPassword st;
    checkSucessLogin = st.userAuthentication();

    if(checkSucessLogin)
    {
        cout<<"login sucess full!"<<endl;
    }
    else
    {
        cout<<"you have enter wrong cretentials! plese retry to login or creat a new user account!"<<endl;

    }
}*/