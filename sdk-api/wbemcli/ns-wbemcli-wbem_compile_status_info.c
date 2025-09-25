typedef struct tag_CompileStatusInfo {
  long    lPhaseError;
  HRESULT hRes;
  long    ObjectNum;
  long    FirstLine;
  long    LastLine;
  DWORD   dwOutFlags;
} WBEM_COMPILE_STATUS_INFO;