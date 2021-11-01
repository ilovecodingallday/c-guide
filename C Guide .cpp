
Timestamps:
1:13 - Intro
7:15 - Linux
17:20 - Basics - Input and Output
33:09 - Variables and Data Types
49:32 - Operators
1:03:13 - Logic (If, Switch, Ternary)
1:19:35 - Loops (for, While, Do While)
1:31:50 - Arrays
1:41:44 - Strings
1:50:00 - Functions
2:07:58 - Creating a Function Library
2:15:55 - Intro to Pointers
2:25:17 - Intro to Structs
2:34:07 - Intro to Memory Management
2:51:16 - Conclusion








1.1-intro.c
/*
C Programming is a compiled language
    This means that all syntax has to be legal in order to create an executable file
C is one of the oldest languages still used today
    Inspired numerous other languages (C++, C#, Java, etc)
C is not object oriented
C is statically typed (all variables are given a type at compile time)
C is not forgiving - Simple mistakes are not told to you
C is dangerous but helps you learn the details and behind the scenes
C is valuable - Still in demand, foundational concepts help everyone
C is hard - Highest learning curve second to assembly
C is not TOO hard - Once you get the hang of it :)
C is low level - Console apps and working with memory directly
C is a very popluar language for system programmers or low level programmers
C has all the same programming structures used in other languages
    -   Variables and data types
    -   Operators
    -   Control flow statemtns
    -   Arrays and Strings
    -   Functions
    -   Structs
    -   And some additional goodies: Pointers and Memory Management

You won't be dissapointed going through this course.
*/












==================================================================================================

1.2-linux.c

/* Getting started with linux.

Figure out what directory you're in:
    -   pwd

List content of current directory. Think "List":
    -   ls

Get more information with a flag. Think "List Long":
    -   ls -l

Get all files (including hidden). Think List All":
    -   ls -a

You can combine flags. Think "List Long All":
    -   ls -la

Change current directory to a new directory 'directoryname':
    -   cd directoryname

Change current directory up one directory:
    -   cd ..

You can also use an absolute path over relative path.
Where / starts from root of directory structure:
    -   cd /absolute/path

Shortcut to change to home directory:
    -   cd ~

Change to directory within home directory (to show variety):
    -   cd ~/folderInHomeDirectory

List the files of two directories up:
    -   ls ../..

Change directory up two directories and then in to 'directory':
    -   cd ../../directoryname

Create a file:
    -   touch filename.c

Remember, you can verify it was created:
    -   ls -la

Move a file to a directory inside root directory:
    -   mv filename.c /directoryname

Rename a file. Same command as moving a file:
    -   mv before.c after.c

We can delete a file with:
    -   rm test.c

remove a directory:
    -   rm -r directoryname

Create a directory:
    -   mkdir test

Make multiple directories:
    -   mkdir folder1 folder2

Print something back to console:
    -   echo "Hello World"

Write to file (overwrite):
    -   echo "Hello World" > output

See file content:
    -   cat output

Write to file (append):
    -   echo " Nice to meet you" >> output

Verify nothing was destroyed:
    -   cat output

Output any command to a file
    -   ls -la > lsOutput

Another way to read a file
    -   less lsOutput

*/




====================================================================================================







=============================================================

1.3-basic-io.c




//First thing - Get a compiler
//#Type 'gcc' in terminal
//   -   gcc

/*
compile:
    -   gcc hello.c

Execute
   -   ./a.out
*/


#include <stdio.h>

int main() //Everything wrapped within main function
{
    printf("Hello World\n"); //hello world
    int x = 50; //How to create a variable
    int y; //Declaration
    y = 10; //Initialization using assignment operator

    /////////////   Output   /////////////

    //Operators work on values and in the context these values are known as operands.
    //Expressions evaluate to a single value.
    //In this case, evaluated to a value and then assigned to y:
    y = x/2; //use of operators.

    printf("%s there\n", "Hello"); //hello there
    //Argument - Each value passed in is known as an argument. Here we are passing 2.
    //Argument 1 - format string
    //Argument 2 - value to replace %s
    //We are essnetially "parameterizing" our string
    //Newline character (\n) - Evaluated as new line

    printf("The value of x is %d.\n", x); //Can use variables
    printf("X: %d\nY: %d\n", x, y); //multiple values can be printed

    /////////////   Input   /////////////

    int radius; //Make sure the variable is declared
    scanf("%i", &radius); //Use address-of-operator
    printf("The given radius was: %i\n", radius); //Verify value was stored

    //Address-of-operator (&) is used because we will change the value of the variable
    //This is how we pass a pointer (what the function needs to change the value)

    //The reason printf() does not need the address-of operator is because it doesn’t change the value
    //It just displays it on the screen, so it’s okay to have a copy of the value given to the function.

    //Getting strings is a little different
    char name[20]; //max size 19. Reserve one for '\0' (null character)
    scanf("%19s", name); //NO address-of-operator required
    //Arrays and strings decay to pointers when passed as arugments
    //A pointer is what scanf needs so no changes needed. Just variable name

    /*/////////////   Conversion Characters   /////////////

        %c	Single character
        %d	Signed decimal integer (int)
        %e	Signed floating-point value in E notation
        %f	Signed floating-point value (float)
        %g	Signed value in %e or %f format, whichever is shorter
        %i	Signed decimal integer (int)
        %o	Unsigned octal (base 8) integer (int)
        %s	String of text
        %u	Unsigned decimal integer (int)
        %x	Unsigned hexadecimal (base 16) integer (int)

    src - http://www.java2s.com/Tutorial/C/0080__printf-scanf/TheprintfConversionCharactersandflags.htm*/

    //scanf has it's limitations - https://stackoverflow.com/questions/9278226/which-is-the-best-way-to-get-input-from-user-in-c
    //consider learning the multitude of input/output functions in C

    /*/////////////   Escape Sequences   /////////////
        \b	Backspace
        \f	Form feed
        \n	Newline
        \r	Return
        \t	Horizontal tab
        \v	Vertical tab
        \\	Backslash
        \'	Single quotation mark
        \"	Double quotation mark
        \?	Question mark
        \0	Null character

source -https://www.programiz.com/c-programming/c-variables-constants

        %% One percent sign
        */
    return 0;
}



========================================================================================




2.1-variable-data-types.c





#include <stdio.h>
#include <stdbool.h>

int main()
{
    int a = 10; //integer
    double b = 10.0; //double
    float c = 10.0; //float (similar to double but less precise)
    char d = 'a'; //string
    char e[] = "The easiest way to define a string";
    bool f = false; //requires stdbool.h

    /////////////   Legal Variable Names   /////////////
    //Cannot change type of variables
    //d = "hello"; will cause an error

    d = 10; //int is directly convertable to char based on ASCII table values (type cast needed? no compiler installed)
    //http://www.asciitable.com/

    //Understand that integers truncate (crop), THEY DO NOT ROUND
    int zero = 0;
    a = zero + 1.99999999999; //a == 1
    printf("a = %d\n", a);
    //This puts us at risk of logic errors (where it compiles but we may have unexpected results)

    /////////////   Type Casting   /////////////

    int slices = 17;
    int people = 2;
    double slicesPerPerson = slices / people;  //WRONG!
    slicesPerPerson = (double) slices / people; //CORRECT!

    // casting is a unary operator (one operand)
    //(double) slices / people == (double) (slices) / people


    //As long as one operand of arithmetic operator is double, double arithmetic is used.
    //This does not mean entire expression is done with double arithmetic
    //these will both print 24. 25 / 2 is 14 * 2 or 2.0 is 24.
    double test1 = 25 / 2 * 2; //24.0
    double test2 = 25 / 2 * 2.0; //24.0

    printf("test1: %f\n", test1);
    printf("test2: %f\n", test2);

    //To fix this, cast in the appropriate location:
    double test3 = 25.0 / 2 * 2; //add .0 to int to make double
    double test4 = (double) 25 / 2 * 2.0; //cast 25 to double

    printf("test3: %f\n", test3);
    printf("test4: %f\n", test4);
}



=================================================================================================


2.2-operators.c




#include <stdio.h>

int main()
{
    /*
    //reference - https://www.tutorialspoint.com/cprogramming/c_operators.htm

    //so far we've worked with some basic operators
    /////////////   Plus and Minus   ///////////// (unary)
        +
        -

    /////////////   Arithmetic   ///////////// (binary)
        +
        -
        /
        *
        %

    /////////////   Increment Decrement Operators   ///////////// (unary)
        ++
        --

    /////////////   Assignment Operators   ///////////// (binary)
        =
        +=
        -=
        /=
        *=
        %=

    /////////////   Comparison Operators   ///////////// (binary)
        ==
        !=
        <
        >
        <=
        >=

    /////////////   Logical operators   ///////////// (binary)
        &&
        ||
        !

    /////////////   Conditional operator   ///////////// (ternary)
        ? :

    /////////////   Precdence and Associativity  /////////////

    Reference - https://en.cppreference.com/w/c/language/operator_precedence
    */

    printf("\nforce precedence with ()\n");
    int x = 2 * (3 + 3);
    int y = (2 * 3) + 3;

    printf("x = %d\n", x);
    printf("y = %d\n", y);

    printf("Modulus operator: \n");
    int c = 10 % 3;
    printf("10 %% 3 = %d\n", c);

    printf("Unary minus:\n");
    int a = 5;

    int b = -a;
    printf("b = %d\n", b);
    printf("a = %d\n", a); // A doesn't change

    printf("post increment:\n");
    a = 5;
    b = 5;
    b = a++;
    printf("b = %d\n", b); //b gets assigned to first
    printf("a = %d\n", a); //Then A is incremented

    b = 5;
    a = 5; //start fresh
    b = ++a;

    printf("Pre increment:\n");
    printf("b = %d\n", b); //B gets assigned to second
    printf("a = %d\n", a); //A is incremented first

    printf("Assignmnet operators:\n");
    a = 5;
    b = 5;
    b += a;
    printf("b += a = %d\n", b); //5 + 5;
    a *= 30;
    printf("a *= 30 = %d\n", a); //5 * 30
    a %= 140;
    printf("a %%= 140 = %d\n", a); //150 % 140
}












==========================================================================================

3.1-logic.c











        V/*

Everything inside of if is ultimately evaluated to true or false

*/

#include <stdio.h>
#include <stdbool.h>

int main()
{
    if (true)
    {
        printf("True\n");
    }
    else
    {
        printf("false\n");
    }

    if (!true)
    {
        printf("True\n");
    }
    else
    {
        printf("false\n");
    }

    //comparison operators resolve to true or false

    int age = 17;
    if (age > 18)
    {
        printf("You are an adult\n");
    } else
    {
        printf("You are not an adult\n");
    }

    //logical operators used to make compound comparisons

    double money = 30000; //no comma

    if(age > 17 && money > 25000)
    {
        printf("Welcome with &&\n");
    }

    if(age > 17 || money > 25000)
    {
        printf("Welcome with || \n");
    }

    bool isGraduated  = true;


    //if(age > 17 && money > 25000 || isGraduated)
    //{
    //THIS WILL BE HIT!  //WILL GIVE WARNING
    //printf("You are a graduated 18+ yr old with $25k\n");
    //}

    //default precedence
    if((age > 17 && money > 25000) || isGraduated)
    {
        printf("1\n");
    }
    if(age > 17 && (money > 25000 || isGraduated))
    {
        printf("2\n");
    }

    /////////////   if, else if, else   /////////////

    if(age < 13)
    {
        printf("You're a youngling\n");
    }
    else if(age > 12 && age < 20) //NOT  12 < age < 20
    {
        printf("You're a teenager\n");
    } else
    {
        printf("You're an old man\n");
    }
    /////////////   single line if  /////////////
    //only for one statement
    if (age < 150) printf("You're possibly alive\n"); printf("This always executes\n");

    /////////////   switch   /////////////
    // Good for few options for numeric or char data

    int menuChoice = 2;

    switch(menuChoice)
    {
        case 0:
            printf("Case 0\n");
            break;
        case 1:
            printf("Case 1\n");
            break;
        case 2:
            printf("Case 2\n");
            break;
        case 3:
            printf("Case 3\n");
            break;
        default:
            printf("Case default\n");
            break;
    }

    switch(menuChoice)
    {
        case 0:
        case 1:
        case 2:
            printf("Case 0, 1, or 2\n");
            break;
        case 3:
            printf("Case 3\n");
            break;
        default:
            printf("Case default\n");
            break;
    }

    //DON'T FORGET THE BREAK!::
    menuChoice = 0;

    printf("WITHOUT BREAK (Don't do this):\n");
    switch(menuChoice)
    {
        case 0:
            printf("Case 0\n"); //DON'T DO THIS!
        case 1:
            printf("Case 1\n");
        case 2:
            printf("Case 2\n");
        case 3:
            printf("Case 3\n");
        default:
            printf("Case default\n\n");
    }

    /////////////   Conditional Operator (ternary operator)  /////////////

    double balance = -5000;

    balance > 0 ? printf("You has money\n") : printf("You has no money\n");

    //can also use ternary operator for more general things (like assignment)
    //Basically returns one value if true. other if false.
    bool hasMoney;
    hasMoney = balance > 0 ? 1 : 0;

    printf("HasMoney? 1 is yes 0 is no: %d\n", hasMoney);

    //all of this branching is pointless if you do not get data from outside of hardcoded values
    //Usually from Db, file, or input.

    printf("Input your age yo:\n");
    scanf("%d", &age);
    if (age < 13)
    {
        printf("get outa here son\n");
    }
    return 0;
}


















================================================================================================================


3.2-loops.c


//loops. 3 main kinds

#include <stdio.h>

int main()
{
    //Each loop has three pieces and it happens at distinct times
    //initialization (once at beginning)
    //comparison (before each iteration)
    //update (at the end of each iteration)

    //you may need to declare i above the for and remove int from if:
    //int i;
    printf("standard:  ");
    for(int i = 0; i < 10; i++)
    {
        //standard format for loop.

        printf("%d ", i);
    }

    printf("\nDecrement: ");
    //you can do what ever you want.
    for(int i = 9; i >= 0; i--)
    {
        printf("%d ", i);
    }

    printf("\nIterate through an array\n");
    int size = 10;
    int ages[] = {12, 54, 34, 76, 34, 65, 99, 11, 34, 49};

    //iterate through an array:

    for(int i = 0; i < size; i++)
    {
        printf("ages[%d] = %d\n", i, ages[i]);
    }

    printf("\nNested for: \n");

    for (int i = 0; i < 10; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            printf("%d ", j);
        }
        printf("\n");
    }

    printf("\nWhile loops do the same thing\n");

    int i = 0; //initialization
    while (i < 10) //comparison
    {
        printf("%d ", i);
        i++; //increment
    }

    printf("\nDo while loops execute atleast once\n");
    //good for menus to show up atleast once
    printf("Choose a number 0-9: ");
    int input;
    do
    {
        scanf("%d", &input);
    }
    while(input < 0 || input > 9); //remember semicolon

    return 0;

}









============



4.1-arrays.c



#include <stdio.h>

int main()
{
    //arrays are pretty simple.
    //It's a collection of items all of same data type

    int ages[] = {1, 3, 4, 54, 34, 2};
    int size = 6;

    for (int i = 0; i < size; i++)
    {
        printf("%d ", ages[i]);
    }
    printf("\n");

    //That is the ideal way to initialize an array when hard coded.
    //often these values come from the user or a file
    //Then, you must hardcode the size like int ages[6];.
    //Either way it is statically sized.
    //First just gets sized by compiler.

    size = 20;
    int grades[size];

    //get from user input or assign manually.
    grades[0] = 10;
    grades[1] = 30;
    grades[2] = 40;
    //...

    //value inside [] is known as index
    //each item in the array is known as an element
    //You can fill all 20 spots (no need to reserve 1 like strings)
    //You can also change data:

    grades[0] = 100; //changed from 10 to 100;

    //grades is an int array
    //grades[0] is an int

    //Anywhere an int is expected, an array element will do
    // You cannot dynamically size an array
    //scanf("%d", &size);
    //int test[size]; //BAD
    //This is because we are using static memory (look it up if unknown)
    //We'll touch on dynamic memory later

    /////////////   Multidimensional Arrays   /////////////

    int rows = 3;
    int const columns = 4;
    int studentGrades[][columns] = {
            {1, 3, 4, 6},
            {3, 2, 4, 5},
            {32, 2, 4, 9}
    };  //atleast columns is required
    //in declaration

    for (int i = 0; i < rows; i++)
    {
        for (int k = 0; k < columns; k++)
        {
            printf("%d\t", studentGrades[i][k]);
        }
        printf("\n");
    }

    //Arrays don't have to contain ints, just easiest to start with
    //All data does need to be same type, though

    return 0;
}





==================================================

4.2-strings.c












#include <stdio.h>
#include <string.h>

int main()
{
    //strings are just character arrays
    //the string ends with \0 (null character)
    //not always the last possible index in the string.

    char name[20];
    scanf("%19s", name);
    //not passing a pointer with address-of-operator
    //limiting to 19 characters

    int letter = 0;
    while (name[letter] != '\0')
    {
        printf("%c\n", name[letter]);
        letter++;
    }
    //ends on 6th character.

    //DON'T OVERWRITE THE NULL CHARACTER!!!
    //Used to find end of string like above.

    printf("Size of name is %d\n", letter);

    /////////////   String functions   /////////////

    //strlen
    printf("Size of name is %lu\n", strlen(name));

    //strcmp - returns 0 if equal values
    if (strcmp(name, "Caleb") == 0) //make sure you remember == 0
    {
        printf("Your name is Caleb!\n");
    }

    //strcpy
    char copy[20];
    strcpy(copy, name); //destination must be first
    printf("Copy of name: %s\n", copy);

    //strcat (concatenation)
    char lastName[] = "Curry";
    strcat(copy,lastName);
    printf("Full name: %s\n", copy);

    //https://www.programiz.com/c-programming/string-handling-functions
}


====================================================================================


5.1-functions.c



#include <stdio.h>

int square (int input)
{
    return input * input;
}
int cube(int input)
{
    return input * input * input;
}

int power(int input, int exponent)
{
    int total = 1;
    for (int i = 0; i < exponent ; i++)
    {
        total *= input;
    }
    return total;
}

int recursivePower(int input, int exponent)
{
    if (exponent < 1) //base case
    {
        return 1;
    }

    return input * recursivePower(input, exponent-1);
}

void changeVal(int *a)
{
    *a *= 2;
}

int oldestValue(int ages[], int size)
{
    int largest = ages[0];
    for(int i = 1; i < size; i++)
    {
        if(ages[i] > largest)
        {
            largest = ages[i];
        }
    }
    return largest;
}


int main()
{
    //keywords:
    //argument - data passed
    //parameter - variable to hold argument
    //return - output from function which can be used in expression
    //return type - data type to be returned
    //void function - a function that doesn't return anything
    //recursive function - a function that calls itself

    printf("%d ", power(2, 4)); //keep output on calling side
    printf("%d ", recursivePower(2, 4));

    int val = 5;
    changeVal(&val);
    printf("Val = %d\n", val);

    int const size = 7;
    int ages[size] = {1,4, 53, 23, 23, 9, 52};
    printf("Oldest age: %d\n", oldestValue(ages,size));
    return 0;
}




=========================================================================================

5.2-libraries



#include "5.2-libraries.h"

int square (int input)
{
    return input * input * input;
}
int cube(int input)
{
    return input * input * input;
}

int power(int input, int exponent)
{
    int total = 1;
    for (int i = 0; i < exponent ; i++)
    {
        total *= input;
    }
    return total;
}

int recursivePower(int input, int exponent)
{
    if (exponent < 1) //base case
    {
        return 1;
    }

    return input * recursivePower(input, exponent-1);
}

void changeVal(int *a)
{
    *a *= 2;
}

//promise won't change with ages
int oldestValue( int *ages, int size)
{
    if(size < 1)
    {
        return -1;
    }
    int oldest = ages[0];
    for (int i = 0; i < size; i++)
    {
        if (ages[0] < ages[i])
        {
            oldest = ages[i];
        }
    }
    return oldest;
}





============================================================================================

5.2-libraries.....


/*
gcc -c 5.2-libraries.c
cc -c 5.2-libraries-main.c
gcc 5.2-libraries.o 5.2-libraries-main.o
./a.out

You can also get a custom name like this:
gcc -o main 5.2-libraries.o 5.2-libraries-main.o

//research makefile to make life easier

*/

#include "5.2-libraries.h"
#include <stdio.h>

int main()
{
    printf("%d ", power(2, 4)); //keep output on calling side
    printf("%d ", recursivePower(2, 4));

    int val = 5;
    changeVal(&val);
    printf("Val = %d\n", val);

    int const size = 7;
    int ages[size] = {1,4, 53, 23, 23, 9, 52};
    printf("Oldest age: %d\n", oldestValue(ages,size));
    return 0;
}





==============5.2................libraries

#ifndef HEADER_FILE //include guards prevent multiple includsion
#define HEADER_FILE //if not yet defined, define it
//optional but recommended

int square (int input);
int cube(int input);
int power(int input, int exponent);
int recursivePower(int input, int exponent);
void changeVal(int *a);
int oldestValue( int *ages, int size);

#endif


====================================================================================




6.1-pointers.c














#include <stdio.h>

void square(int *a)
{
    *a *= *a;
    //we can change value where pointer points to
}

//int getSizeIllustration (int data[])
//{
//return sizeof(data);
//THIS IS NOT THE CORRECT WAY TO DO IT
//ILLUSTRATION ONLY
//SEE COMMENTS IN CALLING CODE
//will get warning because getting size of int pointer
//(can still execute though)
//}

void printIntArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

int main()
{
    int a = 100;
    int *b; // how to declare a pointer
    b = &a; //&a creates a pointer to a. Assigning that to B.
    //aka the address-of-operator
    printf("a   = %d\n", a);
    printf("*b  = %d\n", *b); //dereferencing the pointer
    //aka the indirection operator
    //not same * as when declaring pointer

    //These both print the same value
    //they both refer to the same area of memory

    a = 200;
    printf("a   = %d\n", a);
    printf("*b  = %d\n", *b);

    *b = 300;
    printf("a   = %d\n", a);
    printf("*b  = %d\n", *b);

    //They always match.
    //We are touching a indirectly through b.

    //we can change the value of b (the pointer itself), as well.

    int c = 40;
    b = &c;
    //now b is attached to C.
    //some functions take pointers

    square(b);
    printf("c   = %d\n", c); //c changed through b.

    //arrays decay to pointers
    int ages[] = {2, 43, 64000, 23, 05, 53}; // 6 elements

    printf("memory size of ages = %lu\n", sizeof(ages)); // can divide by sizeof(ages[0]) to get element count
    //printf("memory size in func = %d\n", getSizeIllustration(ages));
    //uncomment this and the function definition and try this!

    //This is why you need to pass size to functions:

    printIntArray(ages, 6);

    return 0;
}







===============================================================================
6.2-structs.c


#include <stdio.h>
#include <string.h>

struct rectangle
{
    int length;
    int width;
};

typedef struct position //name here is optional
{
    int x;
    int y;
} position; //determines data type name

typedef struct buildingPlan //struct of structs
{
    //a struct to define the owner, size, and position of a house
    char owner[30];
    position position; // type being same as identifier is ok
    struct rectangle rectangle; //could remove struct keyword if used typedef
    //but will leave for demenstration
} buildingPlan;

typedef struct pointers
{
    int *a;
    int *b;
} pointers;

void logPosition(position pos)
{
    printf("Log - position: %d %d\n", pos.x, pos.y);
}

buildingPlan createPlan(char name[30], int length, int width, int x, int y)
{

    buildingPlan plan = {"", length, width, x, y};
    strcpy(plan.owner, name);
    return plan;
}
int main()
{
    struct rectangle house = {10, 20}; //non-standard initialization (compared to primitive types)
    position destination = {0,22}; // standard initialization (type identifier = value)

    house.length = 11; //can change values using dot operator
    destination.x = 20;
    printf("destination: %d %d\n", destination.x, destination.y);

    buildingPlan myHouse = {"Caleb Curry", {10, 20}, {11, 34}};
    myHouse.position.x = 30; //Now you can traverse structure using dot operator

    printf("The house at %d %d (size %d %d) is owned by %s\n",
           myHouse.position.x,
           myHouse.position.y,
           myHouse.rectangle.length,
           myHouse.rectangle.width,
           myHouse.owner);

    //You can make arrays of the new data types:

    static int size = 3;
    position path[] = {{0, 1}, {1, 2}, {3, 4}};

    for (int i = 0; i < size; i++)
    {
        if(i == 0)
        {
            printf("From ");
        } else
        {
            printf(" to ");
        }
        printf("(%d %d)", path[i].x, path[i].y);
    }
    printf(".\n");

    //You can pass structs to functions
    logPosition(destination);

    //You can return structs from functions
    buildingPlan myPlan = createPlan("Caleb", 10, 10, 30, 30);

    printf("The house at %d %d (size %d %d) is owned by %s\n",
           myPlan.position.x,
           myPlan.position.y,
           myPlan.rectangle.length,
           myPlan.rectangle.width,
           myPlan.owner);

    //You can have structs that contain pointers
    int a = 10;
    int b = 10;
    pointers myPointers = { &a, &b };


    *myPointers.a = 9001;

    printf("value at destination of myPointers.a: %d\n", *myPointers.a);

    //And you can make pointers to structs

    buildingPlan *pointerToStruct = &myPlan;
    printf("The owner is %s\n", pointerToStruct->owner); //arrow operator to navigate struct pointer

    return 0;
}


===================================================================================================




#include <stdio.h>
#include <stdlib.h> //required for the memory functions
#include <stdbool.h>
#include <string.h>

typedef struct user
{
    char name[30];
    int age;
    bool isVerified;
} user;

user *createUser(char name[], int age, bool isVerified)
{
    user *newUser = malloc(sizeof(user));
    strcpy(newUser->name, name);
    newUser->age = age;
    newUser->isVerified = isVerified;
    return newUser;
};

int main()
{
    //We've been creating statically sized arrays like so:
    int data[] = {1, 2, 3};
    //This is permanently sized to 3.

    //Typically we want dynamically sized;

    int size;
    printf("How many elements do you want to store?: ");
    scanf("%d", &size); //ONLY USE WHAT WE NEED :) #StopGlobalWarming

    printf("Enter each number followed by the enter key:\n");
    int *arr = malloc(size * sizeof (int));
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Your array:\n");
    for (int i = 0; i < size; i++)
    {
        printf("arr[%d] = %d\n",i, arr[i]);
    }

    //When done, make sure you call free! Otherwise memory leak
    free(arr);

    ////////////    null vs void pointer   ////////////
    //Malloc will return either a null pointer, or void pointer
    //null pointer means it points nowhere
    //void pointer means it points to unknown type
    //void = good
    //null = bad = Unable to allocate memory
    //cast from void to int pointer is implicit (C is partially weakly typed)

    //You may want to check if allocation was successful:
    int *grades = malloc(30000 * sizeof (int)); // 30000 ints

    if (grades == 0) // or == NULL
    {
        printf("Error Allocating Memory. Deleting Harddrive. 3...2...1...");
        return -1;
    } else
    {
        //printf("allocation success!\n"); //Usually you don't tell the users this lol
    }

    //Dynamic memory also allows variables to persist past there scope.
    //specifically, think of variables defined within functions.

    user *newUser = createUser("Caleb Curryyyy", 18, false);

    printf("\nuser name: %s\nage: %d\nisVerified: %d\n",
           newUser->name,
           newUser->age,
           newUser->isVerified
    );

    //REMEMBER TO FREE
    free(newUser);


    //can see this concept being useful in making a library
    //to work with a data structure such as a linked list
    //saving that for intermediate C ;)

    //You can see the effects of not freeing if you do this:
    //while(true)
    //{
    //  printf(".");
    //    int *test = malloc (10000000 * sizeof(int));
    //}

    //Other functions you may want to learn

    //realloc - used to resize amount of memory (say an array needs to grow)
    //calloc - similar to malloc but initializes everything to 0 (no "cruft")
    //much more to learn - statt here:
    //https://en.wikipedia.org/wiki/C_dynamic_memory_allocation

    return 0;
}











========================================================================================


7.1-conclusion.c


/*
So far we've covered the basics. What now?
Basically, deep dive the last section. Study up on structs, pointers, and memory management
Master input and output and data validation
Figure out how to connect to a database or file in C and make data driven applications
Study data structures and how to make them in C
    -   linked lists
    -   stack
    -   queue
    -   etc...
Then learn about more software development principles
    -   source control
    -   makefiles
    -   Deploying software to customers
    -   Testing
    -   Debugging

etc

I intend on continuing with an intermediary section that expands on a lot of this stuff.
*/