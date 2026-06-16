// WAP to calculate area and perimeter of rectangle using input from Console.ReadLine()
using System;

public class Program1
{
    public static void Main(string [] args)
    {
        Console.WriteLine("Enter L and B : ");
        int l = int.Parse(Console.ReadLine());
        int b = int.Parse(Console.ReadLine());

        Console.WriteLine("Area : "+(2*(l+b)));
        Console.WriteLine("Perimeter : "+((l*b)));
    }
}