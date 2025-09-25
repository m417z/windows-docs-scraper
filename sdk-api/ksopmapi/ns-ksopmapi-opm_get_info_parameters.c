typedef struct _OPM_GET_INFO_PARAMETERS {
  OPM_OMAC          omac;
  OPM_RANDOM_NUMBER rnRandomNumber;
  GUID              guidInformation;
  ULONG             ulSequenceNumber;
  ULONG             cbParametersSize;
  BYTE              abParameters[OPM_GET_INFORMATION_PARAMETERS_SIZE];
} OPM_GET_INFO_PARAMETERS;