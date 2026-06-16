// WAP to calculate simple interest 
using System;

public class Program1
{
    public static void Main(string [] args)
    {
        Console.WriteLine("Enter P T and R : ");
        double p = double.Parse(Console.ReadLine());
        double t = double.Parse(Console.ReadLine());
        double r = double.Parse(Console.ReadLine());

        Console.WriteLine("Simple Interest : "+((p*t*r)/100));
    }
}