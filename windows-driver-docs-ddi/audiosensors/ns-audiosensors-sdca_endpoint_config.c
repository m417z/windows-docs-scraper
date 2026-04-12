typedef struct _SDCA_ENDPOINT_CONFIG {
  ULONG                     Size;
  UINT8                     Version;
  ULONG                     SdcaFunctionInformationCount;
  SDCA_FUNCTION_INFORMATION SdcaFunctionInformation[ANYSIZE_ARRAY];
} SDCA_ENDPOINT_CONFIG, *PSDCA_ENDPOINT_CONFIG;