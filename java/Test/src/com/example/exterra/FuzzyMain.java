
package com.example.exterra;

public class FuzzyMain {
	public static void main(String[] args) {
		// fuzzy calculation (fuzzyDAO) object created
		FuzzyDAO dao = new FuzzyDAO(); 
		
		// doFuzzy(High Standard Height = int, Average Rate (0.0~1.0) = double)
		dao.doFuzzy(180, 0.5);
	}
}