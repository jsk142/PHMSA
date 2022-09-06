 /*
  *  IncidentLog.cpp
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

#include "IncidentLog.h"

IncidentLog::IncidentLog()
{
} // END default constructor for IncidentLog class

IncidentLog::~IncidentLog()
{
} // END destructor for IncidentLog class

void IncidentLog::displayReports(string outputFileName) const
{
    std::ofstream outFile;

    outFile.open(outputFileName.c_str());	

    std::string errOutStream = "ERROR: in IncidentLog class displayReports member function\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";

    if (!outFile)
    {
        throw std::logic_error(errOutStream);
    }

    this->displayReports(outFile);

    outFile.close();
       
} 

void IncidentLog::displayReports(ostream &os) const
{  
    std::string errOutStream = "ERROR: in IncidentLog class displayReports member function<<\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";

    if (!os)
    {
        throw std::invalid_argument(errOutStream);
    }  

    for ( unsigned long i = 0; i < allIncidents.size(); i++ )
    { 
        allIncidents.at(i).summaryReport();
    }

}

HazMat7k& IncidentLog::find(string incidentNum)
{
    bool incidentFound = false;
    int count = 0;
    int i = 0;

    std::string errFind = "ERROR: in IncidentLog class find member function<<\n";
    errFind += "no incident was matched...\n";

    while ( i < allIncidents.size() && !incidentFound )
    {
        if ( allIncidents.at(i).getReportNumber() == incidentNum )
        {
            incidentFound = true;
            count = i;
        }
  
        i++;
    }

    if ( !incidentFound )
    {
        throw std::logic_error(errFind);
    }

    return allIncidents.at(count);
           
}

void IncidentLog::read( string inputFileName, char fileFormat )
{
    char B, b , Q, q;

    std::string errFileFormat = "ERROR: in IncidentLog class read member function\n";
    errFileFormat += "the character specifying file format is not valid...\n";

    if ( fileFormat != 'B' && fileFormat != 'b' && fileFormat != 'Q' && fileFormat != 'q' )
    { 
        throw std::invalid_argument(errFileFormat);
    }

    std::ifstream inFile;

    inFile.open(inputFileName.c_str());

    std::string errInStream = "ERROR: in IncidentLog class read member function\n";
    errInStream += "the file did not open successfully...\n";

    if (!inFile)
    {   
        throw std::logic_error(errInStream);
    }
    else
    {
        this->read( inFile, fileFormat );
    }

    inFile.close();
    
}

void IncidentLog::read( istream& in, char fileFormat )
{
    char B, b , Q, q;
    string throwaway;
 
    std::string errInStream = "ERROR: in HazMat7k class overloaded operator>>\n";
    errInStream += "the input stream is in a failed state, no processing can take place...\n";

    if (!in)
    {
        throw std::invalid_argument(errInStream);
    }

    if ( fileFormat == 'Q' || fileFormat == 'q' )
    {
        bool answer = true;
        HazMat7k h1;

        try
        {
           in >> h1;
        }
        catch (std::invalid_argument &e)
        { 
            std::cout << "ERROR: caught invalid argument exception";
            std::cout << " in IncidentLog class read member function\n";
            std::cout << e.what() << endl;
            getline(in, throwaway);
            answer = false;
        }
        catch (...)
        {
            std::cout << "ERROR: unknown exception caught";
            std::cout << " in IncidentLog class read member function\n";
            answer = false;
        } 
 
        while ( in )
        {
            if ( answer)
            {           
                allIncidents.push_back(h1);

            }
        
            answer = true;

	    try
	    { 
                in >> h1;
            }
            catch (std::invalid_argument &e)
            { 
                std::cout << "ERROR: caught invalid_argument exception";
                std::cout << " in IncidentLog class read member function\n";
                std::cout << e.what() << endl;	
                getline(in, throwaway);
                answer = false;
            }
            catch (...)
            {
                std::cout << "ERROR: unknown exception caught";
                std::cout << " in IncidentLog class read member function\n";
                answer = false;
            }

        } // END while

    } // END if


    if ( fileFormat == 'B' || fileFormat == 'b' )
    {
        HazMat7k h2;
        HazMatData hd2;
        bool answer = true;

        try
        {
            in.read( reinterpret_cast<char *>(&hd2), sizeof(hd2) );
            h2 = HazMat7k( hd2 );
        }
    
        catch (std::invalid_argument &e)
        { 
            std::cout << "ERROR: caught invalid_argument exception";
            std::cout << " in IncidentLog class read member function\n";
            std::cout << e.what() << endl;
            answer = false;
        }
        catch (...)
        {
            std::cout << "ERROR: unknown exception caught";
            std::cout << "  in IncidentLog class read member function\n";
            answer = false;
        } 
 
        while ( in )
        {
            if ( answer)
            {           
                allIncidents.push_back(h2);
            }
        
            answer = true;

	    try
	    {
                in.read( reinterpret_cast<char *>(&hd2), sizeof(hd2) );
        	        h2 = HazMat7k( hd2 );
            }
            catch (std::invalid_argument &e)
            { 
                std::cout << "ERROR: caught invalid_argument exception";
                std::cout << " in IncidentLog class read member function\n";
                std::cout << e.what() << endl;
                answer = false;
            }
            catch (...)
            {
                std::cout << "ERROR: unknown exception caught";
                std::cout << " in IncidentLog class read member function\n";
                answer = false;
            }

        } // END while

    } // END if

} // END function

void IncidentLog::write( string outputFileName ) const
{
    std::ofstream outFile;

    outFile.open(outputFileName.c_str());

    std::string errOutStream = "ERROR: in IncidentLog class write member function\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";

    if (!outFile)
    {
        throw std::logic_error(errOutStream);
    }

    this->write(outFile);

    outFile.close();
    
}

void IncidentLog::write( ostream& os ) const
{
    std::string errOutStream = "ERROR: in IncidentLog class displayReports member function<<\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";

    if (!os)
    {
        throw std::invalid_argument(errOutStream);
    }

    for ( unsigned long i = 0; i < allIncidents.size(); i++ )
    {
        os << allIncidents.at(i);
    }
}