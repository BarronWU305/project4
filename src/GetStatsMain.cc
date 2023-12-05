#include<iostream>
#include<iomanip>
#include<string>
#include<StatCalculator.h>

using namespace std;

// RPW: This is how we read command-line arguments.  The argc parameter
//      gives us the *number* of command-line arguments.  The *argv[] 
//      parameter is an array of the old-style C strings (not the C++
//      "string" class).  The argv array is a little strange:  The argv[0]
//      actually holds the *name of the program*.  The argv[1] holds the 
//      first true command-line argument.  I convert argv[1] to a string
//      on line 26, below.
int main(int argc, char *argv[]) {
  // Check to make sure a file name is specified,
  // exit with a bad status if not.
  if (argc < 2) {
    cerr << "ERROR:  Please specify a file name at the command line." << endl;
    return 1;
  }

  // Store the name of the file to read as a string, convert from old C-style
  // to newer C++ string class here.  The argv[1] holds the first command-line
  // argument.
  try {
  string filename(argv[1]);
  StatCalculator calculator(filename);

  // Report out all the summary statistics:
  cout << "n:      " << calculator.GetSampleSize() << endl;
  cout << "Mean:   " << setprecision(4) << calculator.EstimateMean() << endl;
  cout << "StdDev: " << setprecision(4) << calculator.EstimateStandardDeviation() << endl;
  cout << "Max:    " << setprecision(4) << calculator.FindMax() << endl;
  cout << "Min:    " << setprecision(4) << calculator.FindMin() << endl;
  }
  
  catch (const ios_base::failure &e) {
    cerr << "An I/O Exception was caught: " << e.what() << endl; 
    return 1; 
  }

  catch (const exception &e) {
    cerr << "An exception was caught: " << e.what() << endl; 
    return 1; 
  }

  // Everything is okay
  return 0;
}
