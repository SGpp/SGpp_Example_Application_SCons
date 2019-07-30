// Copyright (C) 2008-today The SG++ project
// This file is part of the SG++ project. For conditions of distribution and
// use, please see the copyright notice provided with SG++ or at
// sgpp.sparsegrids.org


// Include our example function
#include <example_function.hpp>

#include <iostream>


int main() {
	double x[2] = {2, 2};
	double erg = f(2, x, x);
	std::cout << "Hello function: " << erg << std::endl;
}
