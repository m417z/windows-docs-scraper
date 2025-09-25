typedef struct _SP_DRVINFO_DETAIL_DATA_W {
  DWORD     cbSize;
  FILETIME  InfDate;
  DWORD     CompatIDsOffset;
  DWORD     CompatIDsLength;
  ULONG_PTR Reserved;
  WCHAR     SectionName[LINE_LEN];
  WCHAR     InfFileName[MAX_PATH];
  WCHAR     DrvDescription[LINE_LEN];
  WCHAR     HardwareID[ANYSIZE_ARRAY];
} SP_DRVINFO_DETAIL_DATA_W, *PSP_DRVINFO_DETAIL_DATA_W;