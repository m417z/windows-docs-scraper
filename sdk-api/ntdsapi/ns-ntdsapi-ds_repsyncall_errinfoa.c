typedef struct {
  LPSTR               pszSvrId;
  DS_REPSYNCALL_ERROR error;
  DWORD               dwWin32Err;
  LPSTR               pszSrcId;
} DS_REPSYNCALL_ERRINFOA, *PDS_REPSYNCALL_ERRINFOA;