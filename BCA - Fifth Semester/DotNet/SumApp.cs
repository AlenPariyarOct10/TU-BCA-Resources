using System;

public class CommandLineArgs
{
	public static void Main(string [] args)
	{
		int sum = 0;
		foreach(string i in args)
		{
			sum+=int.Parse(i);
		}
		Console.WriteLine("Sum of nums : "+sum);
	}
}