#ifndef STATCALCULATOR_H_
#define STATCALCULATOR_H_

#include<iostream>
#include<vector>

using namespace std;

/**
 *  StatCalculator is a class that estimates certain summary statistics
 *  over a list of numbers.  Internally, it stores the list as a vector
 *  of doubles.  The class is responsible for reading a file containing
 *  doubles and storing into the internal vector.  It does this upon
 *  construction, so the constructor requires the file name.
**/
class StatCalculator {
public:
  // Constructor reads the file in
  StatCalculator(const string &filename);

  // Calculator functions
  unsigned int GetSampleSize() const;
  double EstimateMean() const;
  double EstimateStandardDeviation() const;
  double FindMax() const;
  double FindMin() const;

private:
  vector<double> numberList_;  // List containing the sample

};

#endif
