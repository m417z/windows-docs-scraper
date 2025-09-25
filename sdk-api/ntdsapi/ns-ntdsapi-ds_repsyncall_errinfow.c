typedef struct {
  LPWSTR              pszSvrId;
  DS_REPSYNCALL_ERROR error;
  DWORD               dwWin32Err;
  LPWSTR              pszSrcId;
} DS_REPSYNCALL_ERRINFOW, *PDS_REPSYNCALL_ERRINFOW;