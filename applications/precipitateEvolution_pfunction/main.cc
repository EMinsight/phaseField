// Precipitate evolution example application
// Header files
#include "../../include/dealIIheaders.h"

#include "parameters.h"
#include "../../src/models/coupled/generalized_model.h"
#include "PLibrary/PLibrary.cc"
#include "PLibrary/PLibrary.hh"
#include "equations.h"
#include "ICs_and_BCs.h"
#include "../../src/models/coupled/generalized_model_functions.h"

//main
int main (int argc, char **argv)
{
	// Load PFunctions from the PLibrary (put this in a separate function?)
	PRISMS::PLibrary::checkout("pfunct_faV", pfunct_faV);
	PRISMS::PLibrary::checkout("pfunct_fbV", pfunct_fbV);
	PRISMS::PLibrary::checkout("pfunct_McV", pfunct_McV);
	PRISMS::PLibrary::checkout("pfunct_Mn1V", pfunct_Mn1V);
	PRISMS::PLibrary::checkout("pfunct_Mn2V", pfunct_Mn2V);
	PRISMS::PLibrary::checkout("pfunct_Mn3V", pfunct_Mn3V);

	Utilities::MPI::MPI_InitFinalize mpi_initialization(argc, argv,numbers::invalid_unsigned_int);
	try
	{
		deallog.depth_console(0);
		generalizedProblem<problemDIM> problem;

		problem.setBCs();
		problem.buildFields();
		problem.init ();
		problem.solve();
	}
	catch (std::exception &exc)
	{
		std::cerr << std::endl << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		std::cerr << "Exception on processing: " << std::endl
				<< exc.what() << std::endl
				<< "Aborting!" << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << std::endl << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		std::cerr << "Unknown exception!" << std::endl
				<< "Aborting!" << std::endl
				<< "----------------------------------------------------"
				<< std::endl;
		return 1;
	}

	return 0;
}
