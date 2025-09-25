typedef struct CRYPTCATCDF_ {
  DWORD  cbStruct;
  HANDLE hFile;
  DWORD  dwCurFilePos;
  DWORD  dwLastMemberOffset;
  BOOL   fEOF;
  LPWSTR pwszResultDir;
  HANDLE hCATStore;
} CRYPTCATCDF;