typedef struct _OPM_GET_INFO_PARAMETERS {
  OPM_OMAC          omac;
  OPM_RANDOM_NUMBER rnRandomNumber;
  GUID              guidInformation;
  ULONG             ulSequenceNumber;
  ULONG             cbParametersSize;
  BYTE              abParameters[4056];
} OPM_GET_INFO_PARAMETERS;