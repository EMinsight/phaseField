// Calls the unit tests for the PRISMS-PF code
// Orignal author: Stephen DeWitt (stvdwtt@umich.edu)

#include <iostream>
#include "unitTest.h"

int main()
{
	std::cout << "Beginning unit tests..." << std::endl;


	// Unit tests for the method "computeStress"
	bool pass = false;
	int tests_passed = 0;

	unitTest<1> computeStress_tester_1D;
	pass = computeStress_tester_1D.test_computeStress();
	tests_passed += pass;

	unitTest<2> computeStress_tester_2D;
	pass = computeStress_tester_2D.test_computeStress();
	tests_passed += pass;

	unitTest<3> computeStress_tester_3D;
	pass = computeStress_tester_3D.test_computeStress();
	tests_passed += pass;


	// Unit tests for the method "getRHS"
	unitTest<2> getRHS_tester_2D;
	pass = getRHS_tester_2D.test_getRHS();
	tests_passed += pass;

	// Unit tests for the method "computeRHS"
	unitTest<2> computeRHS_tester_2D;
	//pass = computeRHS_tester_2D.test_computeRHS();
	tests_passed += pass;

	std::cout << std::endl;
	std::cout << "Number of tests passed: " << tests_passed << std::endl;

	return 0;
}





