using System;

class Untitled
{
	static void Main(string[] args)
	{
		string res, n1, n2;
		n1 = "111101";
		n2 = "101";
		if(n1.Length < n2.Length){
			string t = n1;
			n1 = n2;
			n2 = t;
		}
		
		for(int i = 0; i < n1.Length - n2.Length; i++) n2 = "0" + n2;
		
		Console.WriteLine(n2);
		
	}
}