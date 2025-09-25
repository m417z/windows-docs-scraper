typedef struct _D3DKMT_QUERYPROTECTEDSESSIONINFOFROMNTHANDLE {
  HANDLE     hNtHandle;
  const VOID *pPrivateDriverData;
  UINT       PrivateDriverDataSize;
  const VOID *pPrivateRuntimeData;
  UINT       PrivateRuntimeDataSize;
} D3DKMT_QUERYPROTECTEDSESSIONINFOFROMNTHANDLE;