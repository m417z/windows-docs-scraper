typedef struct _D3DKMT_OPENKEYEDMUTEX2 {
  [in]  D3DKMT_HANDLE hSharedHandle;
  [out] D3DKMT_HANDLE hKeyedMutex;
  [in]  VOID          *pPrivateRuntimeData;
  [in]  UINT          PrivateRuntimeDataSize;
} D3DKMT_OPENKEYEDMUTEX2;