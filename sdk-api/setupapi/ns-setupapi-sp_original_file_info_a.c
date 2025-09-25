typedef struct _SP_ORIGINAL_FILE_INFO_A {
  DWORD cbSize;
  CHAR  OriginalInfName[MAX_PATH];
  CHAR  OriginalCatalogName[MAX_PATH];
} SP_ORIGINAL_FILE_INFO_A, *PSP_ORIGINAL_FILE_INFO_A;