typedef struct _D3DKMT_CREATEKEYEDMUTEX2 {
  [in]  D3DKMT_ALIGN64 UINT64          InitialValue;
  [out] D3DKMT_HANDLE                  hSharedHandle;
  [out] D3DKMT_HANDLE                  hKeyedMutex;
  [in]  VOID                           *pPrivateRuntimeData;
  [in]  UINT                           PrivateRuntimeDataSize;
  [in]  D3DKMT_CREATEKEYEDMUTEX2_FLAGS Flags;
} D3DKMT_CREATEKEYEDMUTEX2;