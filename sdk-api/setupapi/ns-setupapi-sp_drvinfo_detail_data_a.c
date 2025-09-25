typedef struct _SP_DRVINFO_DETAIL_DATA_A {
  DWORD     cbSize;
  FILETIME  InfDate;
  DWORD     CompatIDsOffset;
  DWORD     CompatIDsLength;
  ULONG_PTR Reserved;
  CHAR      SectionName[LINE_LEN];
  CHAR      InfFileName[MAX_PATH];
  CHAR      DrvDescription[LINE_LEN];
  CHAR      HardwareID[ANYSIZE_ARRAY];
} SP_DRVINFO_DETAIL_DATA_A, *PSP_DRVINFO_DETAIL_DATA_A;