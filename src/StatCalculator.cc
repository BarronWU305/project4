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
    if (textFile >> x) {
      numberList_.push_back(x);
    }
    else {
      throw runtime_error("Error: Non-numeric data found in the file.");
      // RPW:  So *any* misread and you just bail out without providing
      //       meaningful context to the user?  What if there is a typo in
      //       line 100 of a data file with 10,000 points?  How will the user
      //       know what to fix?
    }
  }

  // VERIFY IF READ OPERATION WAS SUCCESSFUL
  if (textFile.fail() && !textFile.eof()) {
     throw runtime_error("Error: We encountered some formatting issue in the file.");
  }
  // RPW:  If the file has a terminating newline on the last line, your code
  //       will toss out the whole file.  But this is a pretty normal thing in
  //       OSs other than Windows.  

  textFile.close();
}

/**
 *  Return the total number of values in the sample.
 *  @return The sample size
 **/
//DELETED OG TEST AND ADDED THE TEST BELOW TO TEST IF THERE ARE ENOUGH NUMBERS IN THE FILE.
//IF THERE IS LESS THAN 2 NUMBERS, THE PROGRAM CANNOT RUN PROPERLY. 
unsigned int StatCalculator::GetSampleSize() const {
  // RPW:  This is a good idea, but a brittle location for it.  It only works
  //       in this case because the main calls this function first.  If it
  //       called FindMin first, for example, it would be problematic.
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

