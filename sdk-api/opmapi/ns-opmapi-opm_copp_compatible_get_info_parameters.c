typedef struct _OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS {
  OPM_RANDOM_NUMBER rnRandomNumber;
  GUID              guidInformation;
  ULONG             ulSequenceNumber;
  ULONG             cbParametersSize;
  BYTE              abParameters[4056];
} OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS;