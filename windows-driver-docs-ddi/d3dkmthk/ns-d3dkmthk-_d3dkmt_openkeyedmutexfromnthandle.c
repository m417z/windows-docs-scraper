typedef struct _D3DKMT_OPENKEYEDMUTEXFROMNTHANDLE {
  HANDLE        hNtHandle;
  D3DKMT_HANDLE hKeyedMutex;
  VOID          *pPrivateRuntimeData;
  UINT          PrivateRuntimeDataSize;
} D3DKMT_OPENKEYEDMUTEXFROMNTHANDLE;