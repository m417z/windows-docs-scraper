typedef struct _OPM_CONFIGURE_PARAMETERS {
  OPM_OMAC omac;
  GUID     guidSetting;
  ULONG    ulSequenceNumber;
  ULONG    cbParametersSize;
  BYTE     abParameters[4056];
} OPM_CONFIGURE_PARAMETERS;