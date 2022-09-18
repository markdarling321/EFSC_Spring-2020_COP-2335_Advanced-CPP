/************************************************************************************
*
*  COP 2335-70B  //  Module 1 Project A: Creating Your Own Class
*  NAME:    Mark Darling
*  PURPOSE: create our own class and test it
*  
*************************************************************************************/

#include <iostream>
using namespace std;

//INCLUDE THIS AT THE TOP OF "secretType.h"
//#ifndef H_secretType
//#define H_secretType

// INTERFACE FOR YOUR CLASS OR ADT

//#endif        // THIS GOES AFTER CLASS DEFINITION

//#include "secretType.h"       // CONTAINS CLASS FUNCT PROTOTYPES
// CREATE: secretType.cpp TO CONTAIN FUNCT DEFINITIONS

// CLASS DEFINITION
class secretType
{
public:
    // PRE CONDITION:   NONE
    // POST CONDITION:  OUTPUTS THE DATA STORED IN THE MEMBER VARIABLES
    //                  WITH THE APPROPRIATE TITLES
    void print() const;


    // PRE CONDITION:   NONE
    // POST CONDITION:  SETS MEMBER VARIABLE "name" OF TYPE "string" EQUAL TO INPUT
    void setName(string);


    // PRE CONDITION:   NONE
    // POST CONDITION:  SETS MEMBER VARIABLE "age" OF TYPE "int" EQUAL TO INPUT
    void setAge(int);


    // PRE CONDITION:   NONE
    // POST CONDITION:  SETS MEMBER VARIABLE "weight" OF TYPE "int" EQUAL TO INPUT
    void setWeight(int);


    // PRE CONDITION:   NONE
    // POST CONDITION:  SETS MEMBER VARIABLE "height" OF TYPE "double" EQUAL TO INPUT
    //                  ("height" IS IN INCHES)
    void setHeight(double);


    // PRE CONDITION:   NONE
    // POST CONDITION:  RETURNS THE DATA STORED IN MEMBER VARIABLE "name"
    string getName() const;


    // PRE CONDITION:   NONE
    // POST CONDITION:  RETURNS THE DATA STORED IN MEMBER VARIABLE "age"
    int getAge() const;


    // PRE CONDITION:   NONE
    // POST CONDITION:  RETURNS THE DATA STORED IN MEMBER VARIABLE "weight"
    int getWeight() const;


    // PRE CONDITION:   NONE
    // POST CONDITION:  RETURNS THE DATA STORED IN MEMBER VARIABLE "height"
    double getHeight() const;


    // PRE CONDITION:   NONE
    // POST CONDITION:  INITIALIZES MEMBER VARIABLES CONTAINED IN OBJECT
    //                  OF TYPE "secretType" TO RESPECTIVE VALUES OF THE
    //                  DATA CONTAINED WITHIN EACH VARIABLE PASSED AS A
    //                  PARAMETER
    secretType(string, int, int, double);   // CONSTRUCTOR WITH PARAMETERS


    // PRE CONDITION:   NONE
    // POST CONDITION:  INITIALIZES MEMBER VARIABLES CONTAINED IN OBJECT
    //                  OF TYPE "secretType" TO BLANK AND ZERO VALUES
    secretType();   // CONSTRUCTOR WITHOUT PARAMETERS

private:
    string name;
    int age;
    int weight;
    double height;
};


//  BEGIN MAIN PROGRAM
int main()
{
    // DEFINE CLASS OBJECTS
    secretType mySecret;                        // CALLS DEFAULT CONSTRUCTOR
    secretType yourSecret("Bob", 40, 200, 72);  // CALLS CONSTRUCTOR w/PARAMETERS

    // DEFINE VARIABLES
    string name, temp_name;
    int age, weight, temp_age, temp_weight;
    double height, temp_height;

    // TEST CLASS HERE
    cout << " SETTING mySecret MEMBER VARIABLES..." << endl;
    mySecret.setName("Mark");
    mySecret.setAge(31);
    mySecret.setWeight(225);
    mySecret.setHeight(68);
    cout << " mySecret MEMBER VARIABLES HAVE BEEN SET!" << endl << endl;

    // OUTPUT mySecret AND yourSecret DATA MEMBER VARIABLES TO SCREEN
    // mySecret HAS BEEN MANUALLY SET BY USER IN main() WHILE yourSecret
    // HAS BEEN INITIALIZED BY ITS CONSTRUCTOR w/PARAMETERS WHEN ITS
    // OBJECT INSTANCE WAS CREATED ABOVE IN main()
    cout << " PRINTING mySecret MEMBER VARIABLES TO SCREEN:" << endl;
    mySecret.print();
    cout << endl;
    cout << " PRINTING yourSecret MEMBER VARIABLES TO SCREEN:" << endl;
    yourSecret.print();
    cout << endl;

    // MANUALLY SET yourSecret DATA VARIABLES IN main()
    cout << " MANUALLY SETTING yourSecret MEMBER VARIABLES TO NEW VALUES..." << endl;
    yourSecret.setName("Mary");
    yourSecret.setAge(36);
    yourSecret.setWeight(150);
    yourSecret.setHeight(62);
    cout << " yourSecret MEMBER VARIABLES HAVE BEEN CHANGED!" << endl << endl;

    // OUTPUT mySecret AND yourSecret DATA MEMBER VARIABLES TO SCREEN
    // BOTH HAVE BEEN MANUALLY SET BY USE IN main()
    cout << " PRINTING mySecret MEMBER VARIABLES TO SCREEN: " << endl;
    mySecret.print();
    cout << endl;
    cout << " PRINTING yourSecret MEMBER VARIABLES TO SCREEN: " << endl;
    yourSecret.print();
    cout << endl;

    // GET EACH INDIVIDUAL DATA MEMBER VARIABLE FROM CLASS OBJECT INSTANCE
    // AND STORE IN A TEMPORARY VARIABLE CREATED IN main()
    cout << " STORING mySecret MEMBER VARIABLES INTO TEMP VARIABLES..." << endl;
    temp_name = mySecret.getName();
    temp_age = mySecret.getAge();
    temp_weight = mySecret.getWeight();
    temp_height = mySecret.getHeight();
    cout << " TEMP VARIABLES HAVE BEEN UPDATED!"  << endl << endl;

    // OUTPUT RETRIEVED DATA FROM EACH MEMBER VARIABLE
    // BY PRINTING THE CONTENTS OF EACH VARIABLE
    cout << " PRINT TEMP VARIABLES TO SCREEN: "<< endl;
    cout << " name:   " << temp_name << endl;
    cout << " age:    " << temp_age << endl;
    cout << " weight: " << temp_weight << endl;
    cout << " height: " << temp_height << endl;

    cout << endl;
    cout << " TAKE USER INPUT TO CHANGE TEMP VARIABLES TO NEW VALUES: ";
    cout << endl << endl;
    cout << " Enter a name:   ";
    cin >> temp_name;
    cout << " Enter an age:   ";
    cin >> temp_age;
    cout << " Enter a weight: ";
    cin >> temp_weight;
    cout << " Enter a height: ";
    cin >> temp_height;
    cout << endl << " TEMP VARIABLES VALUES HAVE BEEN CHANGED!" << endl << endl;

    cout << " SETTING yourSecret MEMBER VARIABLES EQUAL TO UPDATED TEMP VARIABLES...";
    cout << endl;
    yourSecret.setName(temp_name);
    yourSecret.setAge(temp_age);
    yourSecret.setWeight(temp_weight);
    yourSecret.setHeight(temp_height);
    cout << " yourSecret MEMBER VARIABLES HAVE BEEN UPDATED SUCCESSFULLY!" << endl << endl;

    cout << " PRINTING UPDATED yourSecret MEMBER VARIABLES TO SCREEN USING CLASS PRINT FUNCTION: ";
    cout << endl;
    yourSecret.print();

    return 0;
}   // END MAIN



// MEMBER FUNCTION DEFINITIONS

// ACCESSOR - PRINT
void secretType::print() const
{
    cout << " name:   " << name << endl;
    cout << " age:    " << age << endl;
    cout << " weight: " << weight << endl;
    cout << " height: " << height << endl;
}

// SETTER - NAME
void secretType::setName(string name)
{
    this->name = name;
}

// SETTER - AGE
void secretType::setAge(int age)
{
    if (age < 0)
        age = 0;
    this->age = age;
}

// SETTER - WEIGHT
void secretType::setWeight(int weight)
{
    if (weight < 0)
        weight = 0;
    this->weight = weight;
}

// SETTER - HEIGHT
void secretType::setHeight(double height)
{
    if (height < 0)
        height = 0;
    this->height = height;
}

// GETTER - NAME
string secretType::getName() const
{
    return name;
}

// GETTER - AGE
int secretType::getAge() const
{
    return age;
}

// GETTER - WEIGHT
int secretType::getWeight() const
{
    return weight;
}

// GETTER - HEIGHT
double secretType::getHeight() const
{
    return height;
}

// CONSTRUCTOR WITH PARAMETERS
secretType::secretType(string name, int age, int weight, double height)
{
    setName(name);
    setAge(age);
    setWeight(weight);
    setHeight(height);
}

// DEFAULT CONSTRUCTOR
secretType::secretType()
{
    name = "";
    age = 0;
    weight = 0;
    height = 0;
}
