#include<StatCalculator.h>
#include<cmath>
#include<fstream>


/**
 *  Constructor for the stat calculator.  This reads a text file and populates an internal
 *  list of sample values.
 *  @param filename The name of the file to read
 **/
StatCalculator::StatCalculator(const string &filename) {
  // Open a text file for reading
  ifstream textFile;
  textFile.open(filename.c_str());

  //UNABLE TO OPEN FILE
  if (!textFile.is_open()) {
    throw runtime_error("Error opening file.");
  }

  // Read numbers in and push them into the numbersList vector
  while (!textFile.eof()) {
    double x; 
    textFile >> x;
    numberList_.push_back(x);
  }

  textFile.close();

   // EMPTY FILE
  if (numberList_.empty()) {
      throw runtime_error("Error: The file is empty or does not contain valid numbers.");
    }
}
/**
 I WAS UNSURE ABOUT CHANGING THE STRUCTURE OF THE WHILE LOOP ABOVE, 
 BUT COULD WE CHANGE IT IN ORDER TO HANDLE STRINGS BEING GIVEN?
*/


/**
 *  Return the total number of values in the sample.
 *  @return The sample size
 **/
//DELETED OG TEST AND ADDED THE TEST BELOW TO TEST IF THERE ARE ENOUGH NUMBERS IN THE FILE.
unsigned int StatCalculator::GetSampleSize() const {
  if (numberList_.size() < 2) {
    throw runtime_error("There are less than 2 numbers in the file. Needs more info."); 
  }
  return numberList_.size();
}


/**
 *  This function returns the sample mean.  This is the sum of the values in the sample
 *  divided by the sample size.
 *  @return The sample mean
 **/
double StatCalculator::EstimateMean() const {
  double sum = 0;

  // Add up all the doubles int he list
  for (vector<double>::const_iterator it=numberList_.begin(); it!=numberList_.end(); ++it)
    sum += (*it);

  // Return the result of the sum over the size of the sample
  return sum/(double)GetSampleSize();
}


/**
 *  This function returns the *sample* standard deviation.  Standard deviation is computed 
 *  this way:  Take the difference between each point in the list and the average.  Square 
 *  each difference, then sum those differences and divide that sum by n.  Then take the
 *  square root of that.
 * @return Sample standard deviation
 * https://en.wikipedia.org/wiki/Standard_deviation
 **/
double StatCalculator::EstimateStandardDeviation() const {
  unsigned int n = numberList_.size();
  double average = EstimateMean(); 
  double total = 0.0;

  for (vector<double>::const_iterator it=numberList_.begin(); it!=numberList_.end(); ++it)
    total += pow( (*it)-average ,2);

  return sqrt(total/(double)(n-1));
}


/**
 *  Find the largest value in the sample.
 *  @return The maximum sample value
 **/
double StatCalculator::FindMax() const {
  double maximum = numberList_[0];

  for (vector<double>::const_iterator it=numberList_.begin(); it!=numberList_.end(); ++it)
    if ( (*it) > maximum)
      maximum = (*it);

  return maximum;
}


/**
 *  Find the smallest value in the sample.
 *  @return The minimum sample value
 **/
double StatCalculator::FindMin() const {
  double minimum = numberList_[0];

  for (vector<double>::const_iterator it=numberList_.begin(); it!=numberList_.end(); ++it)
    if ( (*it) < minimum)
      minimum = (*it);
      
  return minimum;
}

