typedef struct _SP_DRVINFO_DATA_V2_W {
  DWORD     cbSize;
  DWORD     DriverType;
  ULONG_PTR Reserved;
  WCHAR     Description[LINE_LEN];
  WCHAR     MfgName[LINE_LEN];
  WCHAR     ProviderName[LINE_LEN];
  FILETIME  DriverDate;
  DWORDLONG DriverVersion;
} SP_DRVINFO_DATA_V2_W, *PSP_DRVINFO_DATA_V2_W;