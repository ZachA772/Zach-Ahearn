//Zach Ahearn
//14/11/23
//Test Class of each different class file made

import java.util.Scanner;

public class ZachAhearn

{
	static Scanner scan = new Scanner(System.in);
		
	public static void main (String [] args)
	{
		
		int option = 0;
		
		System.out.println("Main Menu");
		
		do{
		System.out.println("1.	Add 2 vectors");
		System.out.println("2.	Multiply a vector by a number");
		System.out.println("3.	Calculate the dot product of 2 vectors");
		System.out.println("4.	Calculate the magnitude of a vector");
		System.out.println("5.	Calculate the angle between 2 vectors");
		System.out.println("6.	Calculate the conjugate of a complex number");
		System.out.println("7.	Calculate the reciprocal of a complex number ");
		System.out.println("8.	Multiply two complex numbers");
		System.out.println("9.	Exit");
		
		option = scan.nextInt();
		switch(option)
		
		{
		 case 1: option1();
		 break;
		 case 2: option2();
		 break;
		 case 3: option3();
		 break;
		 case 4: option4();
		 break;
		 case 5: option5();
		 break;
		 case 6: option6();
		 break;
		 case 7: option7();
		 break;
		 case 8: option8();
		 break;
		 case 9:
		 System.exit(0);
		 default: System.out.println("Invalid Entry");
		}
		
		}while(option!=9);
	}
		
	public static void option1()
	{
		System.out.println("Enter the x value for the first vector:");
        double vector1X = scan.nextDouble();
		
		System.out.println("Enter the y value for the first vector:");
		double vector1Y = scan.nextDouble();

        System.out.println("Enter the x value for the second vector:");
        double vector2X = scan.nextDouble();
		
		System.out.println("Enter the y value for the second vector:");
		double vector2Y = scan.nextDouble();
		
        double resultX = vector1X + vector2X;
        double resultY = vector1Y + vector2Y;

        System.out.println("Result of vector addition: (" + resultX + "i, " + resultY + "j)");
		
	}
	
	public static void option2()
	{
		System.out.println("Enter the x value for the vector:");
        double vector1X = scan.nextDouble();
		
		System.out.println("Enter the y value for the vector:");
		double vector1Y = scan.nextDouble();
		
		System.out.println("Enter number to multiply by the vector:");
		double multipler = scan.nextDouble();
		
		double resultX = vector1X * multipler;
        double resultY = vector1Y * multipler;

        System.out.println("Result of multiplying vector by " + multipler + ": (" + resultX + "i, " + resultY + "j)");
		
		
	}
	
	public static void option3()
	{
		System.out.println("Enter the x value for the first vector:");
        double vector1X = scan.nextDouble();
		
		System.out.println("Enter the y value for the first vector:");
		double vector1Y = scan.nextDouble();

        System.out.println("Enter the x value for the second vector:");
        double vector2X = scan.nextDouble();
		
		System.out.println("Enter the y value for the second vector:");
		double vector2Y = scan.nextDouble();
		
        double result = (vector1X * vector2X) + (vector1Y * vector2Y);
        
        System.out.println("Result of dot product of 2 vectors: (" + result + ")");
		
		
	}
	public static void option4()
	
	{
		System.out.println("Enter the x value for the vector:");
        double vector1X = scan.nextDouble();
		
		System.out.println("Enter the y value for the vector:");
		double vector1Y = scan.nextDouble();

		
        double result = Math.sqrt((vector1X * vector1X) + (vector1Y * vector1Y));
        
        System.out.println("Result of magnitude of vector: " + result);
		
	}
	
	public static void option5()
	
	{
		double vector1X;
		do{
		System.out.println("Enter the POSITIVE x value for the first vector:");
        vector1X = scan.nextDouble();
		}while(vector1X <1);
		
		double vector1Y;
		do{
		System.out.println("Enter the POSITIVE y value for the first vector:");
		vector1Y = scan.nextDouble();
		}while(vector1Y <1);
		
		double vector2X;
		do{
        System.out.println("Enter the POSITIVE x value for the second vector:");
        vector2X = scan.nextDouble();
		}while(vector2X <1);
		
		double vector2Y;
		do{
		System.out.println("Enter the POSITIVE y value for the second vector:");
		vector2Y = scan.nextDouble();
		}while(vector2Y <1);
		
        double dotProduct = (vector1X * vector2X) + (vector1Y * vector2Y);
		System.out.println("Dot product = " + dotProduct);
		double magVec1 = Math.sqrt((vector1X * vector1X) + (vector1Y * vector1Y));
		System.out.println("Magnitude of vector 1 = " + magVec1);
		double magVec2 = Math.sqrt((vector2X * vector2X) + (vector2Y * vector2Y));
		System.out.println("Magnitude of vector 2 = " + magVec2);
		
		double angleFormula = dotProduct / (magVec1 * magVec2);
		double radians = Math.acos(angleFormula);
		double degrees = Math.toDegrees(radians);
		System.out.println("Result of angle obetween 2  given vectors: " + degrees + " degrees");
	}
	
	public static void option6()
	
	{
		System.out.println("Enter the real value for the complex number:");
        double complex1X = scan.nextDouble();
		
		System.out.println("Enter the imaginary value for the complex number:");
		double complex1Y = scan.nextDouble();
		
		complex1Y = complex1Y * (-1);
		
		System.out.println("Conjugate Result: " + complex1X + " + " + complex1Y + "i");
		
	}
	
	public static void option7()
	
	{
		System.out.println("Enter the real value for the complex number:");
        double complex1X = scan.nextDouble();
		
		System.out.println("Enter the imaginary value for the complex number:");
		double complex1Y = scan.nextDouble();
		
		double reciprocalReal = complex1X / ((complex1X * complex1X) + (complex1Y * complex1Y));
		
		double reciprocalImaginary = (-1*complex1Y) / (complex1X * complex1X + complex1Y * complex1Y);
		
		System.out.println("Reciprocal Result: " + reciprocalReal + " + " + reciprocalImaginary + "i");
		
	}
	
	public static void option8()
	
	{
		System.out.println("Enter the real value for the first complex number:");
        double complex1X = scan.nextDouble();
		
		System.out.println("Enter the imaginary value for the first complex number:");
		double complex1Y = scan.nextDouble();
		
		System.out.println("Enter the real value for the second complex number:");
        double complex2X = scan.nextDouble();
		
		System.out.println("Enter the imaginary value for the second complex number:");
		double complex2Y = scan.nextDouble();
		
		double resultRealX = (complex1X * complex2X) - (complex1Y * complex2Y);
        double resultImaginaryY = (complex1X * complex2Y) + (complex1Y * complex2X);
		
		System.out.println("Product Result of 2 Complex Numbers: " + resultRealX + " + " + resultImaginaryY + "i");

		
	}

}