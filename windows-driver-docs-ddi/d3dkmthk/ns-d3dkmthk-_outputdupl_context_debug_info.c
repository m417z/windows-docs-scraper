typedef struct _OUTPUTDUPL_CONTEXT_DEBUG_INFO {
  OUTPUTDUPL_CONTEXT_DEBUG_STATUS Status;
  HANDLE                          ProcessID;
  UINT32                          AccumulatedPresents;
  D3DKMT_ALIGN64 LARGE_INTEGER    LastPresentTime;
  D3DKMT_ALIGN64 LARGE_INTEGER    LastMouseTime;
  CHAR                            ProcessName[DXGK_DIAG_PROCESS_NAME_LENGTH];
} OUTPUTDUPL_CONTEXT_DEBUG_INFO;