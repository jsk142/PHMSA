 /*
  *  PHMSA7000.cpp
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

#include "PHMSA7000.h"

ostream& operator<<(ostream &os, const HazMat7k &rhsObj)
{
    std::string errOutStream = "ERROR: in HazMat7k class overloaded operator<<\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";

    if (!os)
    {
        throw std::invalid_argument(errOutStream);
    } // END if
    
    os << rhsObj.reportReceivedDate << " " << rhsObj.reportNumber << " " 
       << rhsObj.supplementalNumber << " " << "\"" << rhsObj.reportType << "\"" << " "
       << rhsObj.operatorID << " " << "\"" << rhsObj.name << "\"" << " " << "\"" 
       << rhsObj.operatorStreetAddress << "\"" << " " << "\"" << rhsObj.operatorCityName 
       << "\"" << " " << rhsObj.operatorStateAbbreviation << " " << "\"" 
       << rhsObj.operatorPostalCode << "\"" << " " << rhsObj.localDate << " " << rhsObj.localTime
       << " " << "\"" << rhsObj.commodityReleasedType << "\"" << " " 
       << rhsObj.unintentionalReleaseBbls << " " << rhsObj.intentionalReleaseBbls << " " 
       << rhsObj.recoveredBbls << " " << rhsObj.fatal << " " << rhsObj.injure << " " 
       << rhsObj.igniteInd << " " << rhsObj.explodeInd << " " << rhsObj.preparedDate << " "
       << "\"" << rhsObj.authorizerName << "\"" << " " << "\"" << rhsObj.authorizerEmail << "\""
       << " " << "\"" << rhsObj.narrative << "\"" << endl;
    
    return os;

} // END overloaded stream insertion operator for HazMat7k class

istream& operator>>(istream &is, HazMat7k &rhsObj)
{	
    Date rReceivedDate;
    string rNumber;
    string sNumber;
    string rType; 
    string oID;  
    string n;
    string oStreetAddress;
    string oCityName;
    string oStateAbbreviation;
    string oPostalCode;
    Date lDate;
    Time lTime;
    string cReleasedType;
    double uReleaseBbls;
    double iReleaseBbls;
    double rBbls;
    int f;
    int i;
    string iInd;
    string eInd;
    Date pDate;
    string aName;
    string aEmail;
    string narr;
 
    // if stream is originally in a failed throw an exception
    // this is thrown outside of the try block so it will not be
    // handled locally, but will immediately pass control back
    // to the calling function
    
    std::string errInStream = "ERROR: in HazMat7k class overloaded operator>>\n";
    errInStream += "the input stream is in a failed state, no processing can take place...\n";
    if (!is)
    {
        throw std::invalid_argument(errInStream);
    }

    try
    {
        bool streamFailed = false;
 
        is >> rReceivedDate;
        if (!is) { streamFailed = true; }

        is >> rNumber;
        if (!is) { streamFailed = true; }

        is >> sNumber;
        if (!is) { streamFailed = true; }

        rType = readDoubleQuotedString(is);       
        if (!is) { streamFailed = true; }

        is >> oID; 
        if (!is) { streamFailed = true; }

	n = readDoubleQuotedString(is);
        if (!is) { streamFailed = true; }

	oStreetAddress = readDoubleQuotedString(is);
        if (!is) { streamFailed = true; }        
    
	oCityName = readDoubleQuotedString(is);
        if (!is) { streamFailed = true; }
 
        is >> oStateAbbreviation;
        if (!is) { streamFailed = true; }

	oPostalCode = readDoubleQuotedString(is);
        if (!is) { streamFailed = true; }

        is >> lDate;
        if (!is) { streamFailed = true; }

	is >> lTime;
        if (!is) { streamFailed = true; }

	cReleasedType = readDoubleQuotedString(is);
        if (!is) { streamFailed = true; }

	is >> uReleaseBbls;
        if (!is) { streamFailed = true; }

	is >> iReleaseBbls;
        if (!is) { streamFailed = true; }
	
	is >> rBbls;
        if (!is) { streamFailed = true; }

	is >> f;
        if (!is) { streamFailed = true; }

	is >> i;
        if (!is) { streamFailed = true; }

	is >> iInd;
        if (!is) { streamFailed = true; }

	is >> eInd;
        if (!is) { streamFailed = true; }

	is >> pDate;
        if (!is) { streamFailed = true; }

	aName = readDoubleQuotedString(is);
        if (!is) { streamFailed = true; }

	aEmail = readDoubleQuotedString(is);
        if (!is) { streamFailed = true; }

	narr = readDoubleQuotedString(is);
        if (!is) { streamFailed = true; }

        
        // if stream entered a failed state while extracting values
        // throw an exception
        // this is thrown inside of the try block so it will be
        // handled locally
        // in this case, local processing does not rethrow
        // this technique assumes that the point in the program from which
        // the overloaded stream extraction operator was called will test
        // for the stream being in a failed state after the function
        // call and take appropriate action
        
        if(streamFailed)
        {
            std::string errInStream = "WARNING: in HazMat7k class overloaded operator>>\n";
            errInStream += "the input stream is in a failed state, ";
            errInStream += "possible attempt to read past end of file, ";
            errInStream += "HazMat7k object data members not updated ...\n";
            throw std::runtime_error(errInStream);
        }
        
        rhsObj.setReportReceivedDate(rReceivedDate);
        rhsObj.setReportNumber(rNumber);              
        rhsObj.setSupplementalNumber(sNumber);         
        rhsObj.setReportType(rType);                  
        rhsObj.setOperatorID(oID);                   
        rhsObj.setName(n);                         
        rhsObj.setOperatorStreetAddress(oStreetAddress);
        rhsObj.setOperatorCityName(oCityName);           
        rhsObj.setOperatorStateAbbreviation(oStateAbbreviation);
        rhsObj.setOperatorPostalCode(oPostalCode);     
        rhsObj.setLocalDate(lDate);        
        rhsObj.setLocalTime(lTime);                
        rhsObj.setCommodityReleasedType(cReleasedType);    
        rhsObj.setUnintentionalReleaseBbls(uReleaseBbls);
        rhsObj.setIntentionalReleaseBbls(iReleaseBbls);
        rhsObj.setRecoveredBbls(rBbls);
 
        rhsObj.setFatal(f);         
        rhsObj.setInjure(i);
        rhsObj.setIgniteInd(iInd);
        rhsObj.setExplodeInd(eInd);
        rhsObj.setPreparedDate(pDate); 
        rhsObj.setAuthorizerName(aName);
        rhsObj.setAuthorizerEmail(aEmail);
        rhsObj.setNarrative(narr);
         
    }

    catch (std::runtime_error &e)
    {
        std::cout << "WARNING: ";
        std::cout << "caught runtime_error exception in HazMat7k class overloaded operator>>\n";
        std::cout << e.what() << endl;
        // allow processing to continue, do not re-throw
    }
    catch (std::invalid_argument &e)
    {
        std::cout << "ERROR: ";
        std::cout << "caught invalid_argument exception in HazMat7k class overloaded operator>>\n";
        std::cout << e.what() << endl;
        // do not allow processing to continue, re-throw
        throw;
    }
    catch (...)
    {
        std::cout << "ERROR: unknown exception caught in Date class overloaded operator>>\n";
        throw;
    }
    
    return is;

} // END overloaded stream extraction operator for HazMat7k class

HazMat7k::~HazMat7k()
{
} // END destructor for HazMata7k class

HazMat7k::HazMat7k()
{
    Date defaultDate;
    Time defaultTime;

    try
    {
       setReportReceivedDate(defaultDate);
       setReportNumber("14920000");               
       setSupplementalNumber("");         
       setReportType("ORIGINAL");                  
       setOperatorID("");                   
       setName("");                         
       setOperatorStreetAddress("");     
       setOperatorCityName("");             
       setOperatorStateAbbreviation("");    
       setOperatorPostalCode("");       
       setLocalDate(defaultDate);             
       setLocalTime(defaultTime);                
       setCommodityReleasedType("");      
       setUnintentionalReleaseBbls(0.0);
       setIntentionalReleaseBbls(0.0);
       setRecoveredBbls(0.0);
 
       setFatal(0);           
       setInjure(0);    
       setIgniteInd("");  
       setExplodeInd("");  
       setPreparedDate(defaultDate);
       setAuthorizerName("");
       setAuthorizerEmail("");  
       setNarrative("");
    }

    catch (std::invalid_argument &e)
    {
        std::cout << "ERROR: ";
        std::cout << "caught invalid_argument exception in HazMat7k class default constructor>>\n";
        std::cout << e.what() << endl;
        // do not allow processing to continue, re-throw
        throw;
    }
    catch (...)
    {
        std::cout << "ERROR: unknown exception caught in HazMat7k class default constructor>>\n";
        throw;
    }


} // END default constructor for HazMat7k class


HazMat7k::HazMat7k( const HazMatData &hzData )
{
    try
    {
        this->setReportReceivedDate( hzData.report_received_date );
        this->setReportNumber( string(hzData.report_number) );               
        this->setSupplementalNumber( string(hzData.supplemental_number) );         
        this->setReportType( string(hzData.report_type) );                  
        this->setOperatorID( string(hzData.operator_id) );                   
        this->setName( string(hzData.name) );                         
        this->setOperatorStreetAddress( string(hzData.operator_street_address) );     
        this->setOperatorCityName( string(hzData.operator_city_name) );             
        this->setOperatorStateAbbreviation( string(hzData.operator_state_abbreviation) );    
        this->setOperatorPostalCode( string(hzData.operator_postal_code) );       
        this->setLocalDate( hzData.local_date );
        this->setLocalTime( hzData.local_time );                
        this->setCommodityReleasedType( string(hzData.commodity_released_type) );     
        this->setUnintentionalReleaseBbls( hzData.unintentional_release_bbls );
        this->setIntentionalReleaseBbls( hzData.intentional_release_bbls );
        this->setRecoveredBbls( hzData.recovered_bbls );
 
        this->setFatal( hzData.fatal );           
        this->setInjure( hzData.injure );
        this->setIgniteInd( string(hzData.ignite_ind) );
        this->setExplodeInd( string(hzData.explode_ind) );
        this->setPreparedDate( hzData.prepared_date ); 
        this->setAuthorizerName( string(hzData.authorizer_name) );
        this->setAuthorizerEmail( string(hzData.authorizer_email) );
        this->setNarrative( string(hzData.narrative) );
     
    } // END try

    catch(std::invalid_argument &e)
    {
        std::cout << "ERROR: ";
        std::cout << "caught invalid argument exception in HazMat7k class convert constructor\n";
        std::cout << e.what() << endl;
        throw;
    }
    catch (...)
    {
        std::cout << "ERROR: unknown exception caught in HazMat7k class convert` constructor>>\n";
        throw;
    }

        
}

void HazMat7k::setReportNumber(string value)
{
    bool setReportNumberFailed = false;

    if ( value.size() != 8 )
    {
       setReportNumberFailed = true;
    }

    string str = value.substr (0, 4);

    int num = stoi(str);

    if (num != reportReceivedDate.getYear() )
    {
        setReportNumberFailed = true;
    }

    if (setReportNumberFailed)
    {  
        std::string errReportNumber = "ERROR: in HazMat7k class setReportNumber member function\n";
        errReportNumber += "the year does not match the year of the reportReceived Date\n";
        std::invalid_argument e(errReportNumber);
        throw e;
    }
         
    reportNumber = value;
}

void HazMat7k::setReportType(string value)
{
    bool setReportTypeFailed = true;

    if ( value == "ORIGINAL" || value == "ORIGINAL FINAL" || value == "SUPPLEMENTAL" 
                             || value == "SUPPLEMENTAL FINAL" )
    {
        setReportTypeFailed = false;
    }
  
    if (setReportTypeFailed)
    {
         std::string errReportNumber = "ERROR: in HazMat7k class setReportType member function\n";
         errReportNumber += "the report type must be one of the following values\n";
         errReportNumber += "Original, ORIGINAL FINAL, SUPPLEMENTAL, SUPPLEMENTAL FINAL\n";
         std::invalid_argument e(errReportNumber);
         throw e; 
    }

    reportType = value;   
}	

void HazMat7k::summaryReport(ostream &os) const
{
    std::string errOutStream = "ERROR: in HazMat7k class summaryReport member function<<\n";
    errOutStream += "the output stream is in a failed state, no processing can take place...\n";

    if (!os)
    {
        throw std::invalid_argument(errOutStream);
    }
 
    os << "Report Number and Date:       " << reportNumber << "  ";
    os << reportReceivedDate << endl;    

    os << "Local Date and Time:          " << localDate << "  ";
    os << localTime << endl;

    os << "Number of Injuries:" << std::setw(8) << injure << endl;
    os << "Number of Fatalities:" << std::setw(6) << fatal << endl;
    os << "Narrative Length:" << std::setw(10) << narrative.size() << endl;
    os << "Narrative:  " << narrative << endl << endl << endl;
    
}