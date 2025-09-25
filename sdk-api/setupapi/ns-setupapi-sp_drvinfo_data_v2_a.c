typedef struct _SP_DRVINFO_DATA_V2_A {
  DWORD     cbSize;
  DWORD     DriverType;
  ULONG_PTR Reserved;
  CHAR      Description[LINE_LEN];
  CHAR      MfgName[LINE_LEN];
  CHAR      ProviderName[LINE_LEN];
  FILETIME  DriverDate;
  DWORDLONG DriverVersion;
} SP_DRVINFO_DATA_V2_A, *PSP_DRVINFO_DATA_V2_A;