 /*
  *  main.cpp
  *
  *  COSC 052 Fall 2019
  *  Project #1
  *
  *  Due on: SEP 19, 2019
  *  Author: jsk142
  *
  *
  *  In accordance with the class policies and Georgetown's
  *  Honor Code, I certify that, with the exception of the
  *  class resources and those items noted below, I have neither
  *  given nor received any assistance on this project.
  *
  *  References not otherwise commented within the program source code.
  *  Note that you should not mention any help from the TAs, the professor,
  *  or any code taken from the class textbooks.
  */

#include "main.h"

int main(int argc, const char * argv[])
{        
  string inputFileName = "";
    char inputFormat = '?';

    if ( argc < 2)
    {
       string errMsg = "Not enough command line arguments, please pass the complete path and name\n";
       errMsg += "with character that is the code for the file format\n";
       errMsg += "processing cannot continue... goodbye.\n";

       throw invalid_argument(errMsg);
    }

    inputFileName = argv[1];
    inputFormat = argv[2][0];
  
    try
    {
        IncidentLog log;
        log.read(inputFileName, inputFormat);
        log.displayReports();
        
        
    }


    catch (std::invalid_argument &e)
    { 
        cout << "ERROR: ";
        cout << "caught invalid_argument exception in function main\n";
        cout << e.what() << endl;
     
    }
    catch (...)
    {
        cout << "ERROR: unknown exception caught in function main \n";
    }
    
    return 0;  

}