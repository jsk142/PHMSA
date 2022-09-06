 /*
  *  IncidentLog.h
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
 
 
 
 #ifndef _COSC052_FALL2019_P1_INCIDENT_LOG_H
 #define _COSC052_FALL2019_P1_INCIDENT_LOG_H
 
 
 #include <iostream>
 #include <fstream>
 #include <sstream>
 #include <exception>
 #include <stdexcept>
 
 #include "PHMSA7000.h"
 #include "Resources.h"
 
 using std::ostream;
 using std::cout;
 using std::logic_error;
 
 
 /****************************************************************************
  *                                                                          *
  *                  class IncidentLog declaration                           *
  *                                                                          *
  ****************************************************************************/
 
 class IncidentLog
 {
 private:
     
     vector<HazMat7k> allIncidents; 
 public:
     
     IncidentLog();
     ~IncidentLog();
     
     void displayReports(string outputFileName) const;
     void displayReports(ostream &os = cout) const;
    
     HazMat7k& find(string incidentNum);
     
     void read( string inputFileName, char fileFormat );
     void read( istream& in, char fileFormat );
     
     void write( string outputFileName ) const;
     void write( ostream& out = cout ) const;
     
     unsigned long size() const { return allIncidents.size(); }
     
 }; //END class IncidentLog declaration
 
 
 
 
 
 
 #endif   /*  _COSC052_FALL2019_P1_INCIDENT_LOG_H  */