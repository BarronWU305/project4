# CSCI 208, Spring 2023, Programming Project 4

## Make a Stats Calculator Robust
The code I've given you can read a file containing numbers and report some basic statistics about that number (mean, standard deviation, min, and max).  But the code isn't very robust (it's easy to break it).  Your job is to make sure the program doesn't crash.  Deal with all potential errors in a *cosntructive* way that makes your program as robust as possible.  Put yourself in the shoes of the user:  How would you want the program to behave under different conditions if you were legitimately using this program?  That is:  If you can make your program run correctly in spite of a problem, then do so.  If you *must* stop the program, make sure you do so gracefully while informing the user of exactly what the problem is.

Some obvious ones include (but are not limited to):  
*  What if the filename given isn't a valid file?  
*  What if that file contains something other than numbers?
*  What happens if the file doesn't contain *any* numbers?
*  What happens if there is only *one* number?

You are required to handle at least one **exception**.  How you deal with other errors is up to you.  Your program should not return a status 0 if there is a significant error (e.g., the file cannot be found), so pay attend to the return status of the main, as well.

*I will test your program on my own data files, so be careful not to hardcode things.*


## Provided Code
I am giving you three source files, a Makefile, and an input file.  I have organized the project into directories.

* inc/StatCalculator.h -- a header for the class you must code
* src/StatCalculator.cc -- the body source implementing the class you must code
* src/GetStatsMain.cc -- the main code that I provide to you from which you will run your program
* input/simpletestfile.txt -- an example text file with numbers in it

The object files will be built into the *obj* directory.  And the binary executable file will be built into the *bin* directory.  So to run your program, you would type:

```
./bin/GetStatsMain ./input/simpletextfile.txt
```

To be clear:  You are responsible for implementing the *StatCalculator* class body.  You *cannot* coordinate or communicate with other students or copy code off the Internet.  This is *your own* work.


## Using GitHub Classroom
You have obtained this code by accepting my GitHub Classroom invitation link.  I will grade the materials I find in your repository on GitHub.  So you are responsible for making sure you have committed and pushed your code to the source repository *before* the due date.


## Expected Output
This is what the output for my implementation gives me for *simpletestfile.txt*:

```
n:      30
Mean:   0.5905
StdDev: 2.343
Max:    5.034
Min:    -5.577
```

## Do Your Own Coding
To be clear:  You are responsible for implementing this.  You *cannot* coordinate or communicate with others or copy code off the Internet.  This is *your own* work.  Copying other people's source code or using an AI without permission is considered *plagiarism*.

