struct TipReportingInfo
{
    unsigned int testCaseId;           
    PCSTR testCaseName;                
    unsigned int properties;         
    GUID testId;                       
    unsigned int flags;                   
    unsigned char completionKind; 
    unsigned short reason;             
    PCSTR reasonName;                  
    LONGLONG startPerformanceCounter;  
    unsigned int observedSleepTimeInMs;
    PCSTR data;                        
    HRESULT lastResult;                
    PCSTR lastFile;                    
    unsigned short lastLine;           
    unsigned int durationMs;           
    unsigned int hash;                 
    unsigned int metricsBucket;        
    unsigned int testCaseIdStart;      
};