package com.example.exterra;

public class FuzzyExceptions {
	public static int stringToInt(String _heightString){
		int heightInt = 0;
		try {
			heightInt = Integer.parseInt(_heightString);
		} catch (Exception e) {
			System.out.println("Height is only numbers not a character");	
			System.exit(1);
		}
		return heightInt;
	}
}
