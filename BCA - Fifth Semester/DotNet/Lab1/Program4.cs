// WAP to convert (Degree) Celsius to (Degree) Forenheight
using System;

public class Program1
{
    public static void Main(string [] args)
    {
        Console.WriteLine("Enter Temprature in Celsius : ");
        float c = float.Parse(Console.ReadLine());

        float f = (float)(c*9/5)+32;

        Console.WriteLine(c+" Celsius = "+f+" Fahrenheit");
        

    }
}