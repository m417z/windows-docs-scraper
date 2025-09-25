typedef struct _DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS {
  DXGKMDT_OPM_RANDOM_NUMBER rnRandomNumber;
  GUID                      guidInformation;
  ULONG                     ulSequenceNumber;
  ULONG                     cbParametersSize;
  BYTE                      abParameters[DXGKMDT_OPM_GET_INFORMATION_PARAMETERS_SIZE];
} DXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS, *PDXGKMDT_OPM_COPP_COMPATIBLE_GET_INFO_PARAMETERS;