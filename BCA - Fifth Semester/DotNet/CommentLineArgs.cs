using System;

public class CommandLineArgs
{
	public static void Main(string [] args)
	{
		int sum = int.Parse(args[0])+int.Parse(args[1]);
		Console.WriteLine("Sum of two nums : "+sum);
	}
}