typedef struct _D3DKMT_RELEASEKEYEDMUTEX2 {
  [in] D3DKMT_HANDLE         hKeyedMutex;
  [in] D3DKMT_ALIGN64 UINT64 Key;
  [in] D3DKMT_ALIGN64 UINT64 FenceValue;
  [in] VOID                  *pPrivateRuntimeData;
  [in] UINT                  PrivateRuntimeDataSize;
} D3DKMT_RELEASEKEYEDMUTEX2;