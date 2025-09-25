typedef struct _DXGKMDT_OPM_CONFIGURE_PARAMETERS {
  DXGKMDT_OPM_OMAC omac;
  GUID             guidSetting;
  ULONG            ulSequenceNumber;
  ULONG            cbParametersSize;
  BYTE             abParameters[DXGKMDT_OPM_CONFIGURE_SETTING_DATA_SIZE];
} DXGKMDT_OPM_CONFIGURE_PARAMETERS, *PDXGKMDT_OPM_CONFIGURE_PARAMETERS;