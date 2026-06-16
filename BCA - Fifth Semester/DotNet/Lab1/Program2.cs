// WAP to add, subtract, multiply and division of two number using input from command line
using System;

public class Program2
{
    public static void Main(string [] args)
    {
        int num1 = int.Parse(args[0]);
        
        int num2 = int.Parse(args[2]);

        switch(args[1])
        {
            case "+":
                Console.WriteLine(args[0]+" "+args[1]+" "+args[2]+" = "+(num1+num2));
                break;
            case "-":
                Console.WriteLine(args[0]+" "+args[1]+" "+args[2]+" = "+(num1-num2));
                break;
            case "*":
                Console.WriteLine(args[0]+" "+args[1]+" "+args[2]+" = "+(num1*num2));
                break;
            case "/":
                Console.WriteLine(args[0]+" "+args[1]+" "+args[2]+" = "+(num1/num2));
                break;
            default:
                Console.WriteLine("Invalid Values");
                break;

        }
    }
}