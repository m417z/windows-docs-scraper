typedef struct _QUERY_ON_CREATE_ECP_CONTEXT {
  ULONG                                 RequestedClasses;
  ULONG                                 ClassesProcessed;
  ULONG                                 ClassesWithErrors;
  ULONG                                 ClassesWithNoData;
  QUERY_ON_CREATE_FILE_STAT_INFORMATION StatInformation;
  QUERY_ON_CREATE_FILE_LX_INFORMATION   LxInformation;
  QUERY_ON_CREATE_EA_INFORMATION        EaInformation;
  ULONG                                 Reserved;
  ULONG                                 CommonBufferSize;
  PVOID                                 CommonBuffer;
  QUERY_ON_CREATE_USN_INFORMATION       UsnInformation;
  SECURITY_INFORMATION                  SecurityInformationRequested;
  QUERY_ON_CREATE_SECURITY_INFORMATION  SecurityInformation;
} QUERY_ON_CREATE_ECP_CONTEXT, *PQUERY_ON_CREATE_ECP_CONTEXT;