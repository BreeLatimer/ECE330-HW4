/**
 * ECE-330 HW4 Problem #3
 * Author: Bree Latimer
 * Date: 3/20/2022
 * 
 * This program takes in 3 sides and calculates the area and perimeter of the triangle
 * 
 * You will notice that I changed the formula. I noticed that the formula that was provided
 * on the handout was wrong and that Heron's formula is actually
 * sqrt(s(s-a)(s-b)(s-c))
 * and not
 * 0.5(s(s-a)(s-b)(s-c)) 
 * 
 * The value to obtain s was still correct
 */

#include <stdio.h>
#include <math.h>

double perim();
double area();
double read_input();
double print_value();

int main(int argc, char *argv[]){

    printf("Enter the value of a:\n");
    double a = read_input();
    printf("Enter the value of b:\n");
    double b = read_input();
    printf("Enter the value of c:\n");
    double c = read_input();

    double perimVal = perim(a, b, c);
    double areaVal = area(a,  b, c);

    printf("The perimeter of this triangle is:\n");
    print_value(perimVal);
    printf("The area of this triangle is:\n");
    print_value(areaVal);

    return 0;
}

double perim(double a, double b, double c){
    return a + b + c;
}

double area(double a, double b, double c){
    double s = 0.5 * (perim(a, b, c));

    double retVal = sqrt(s * (s - a) * (s - b) * (s - c));
    return retVal;
}

double read_input(){
    double retVal;

    scanf("%lf", &retVal);

    return retVal;
}

//I don't understand what the point of this function is. I can simply have it print in my main,
//and if it wants me to print HERE then why am I having to return a double? I could simply
//have it take in one value for perim and one for area and print both in a nice formatted way.
double print_value(double val){
    printf("%lf\n", val);
    return val;
}