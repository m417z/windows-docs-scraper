typedef struct _D3DKMT_ACQUIREKEYEDMUTEX2 {
  D3DKMT_HANDLE         hKeyedMutex;
  D3DKMT_ALIGN64 UINT64 Key;
  PLARGE_INTEGER        pTimeout;
  D3DKMT_ALIGN64 UINT64 FenceValue;
  VOID                  *pPrivateRuntimeData;
  UINT                  PrivateRuntimeDataSize;
} D3DKMT_ACQUIREKEYEDMUTEX2;