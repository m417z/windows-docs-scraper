typedef struct _D3DKMT_CREATEPROTECTEDSESSION {
  D3DKMT_HANDLE hDevice;
  D3DKMT_HANDLE hSyncObject;
  const VOID    *pPrivateDriverData;
  UINT          PrivateDriverDataSize;
  const VOID    *pPrivateRuntimeData;
  UINT          PrivateRuntimeDataSize;
  D3DKMT_HANDLE hHandle;
} D3DKMT_CREATEPROTECTEDSESSION;