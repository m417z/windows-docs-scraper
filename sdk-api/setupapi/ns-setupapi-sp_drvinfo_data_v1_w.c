typedef struct _SP_DRVINFO_DATA_V1_W {
  DWORD     cbSize;
  DWORD     DriverType;
  ULONG_PTR Reserved;
  WCHAR     Description[LINE_LEN];
  WCHAR     MfgName[LINE_LEN];
  WCHAR     ProviderName[LINE_LEN];
} SP_DRVINFO_DATA_V1_W, *PSP_DRVINFO_DATA_V1_W;