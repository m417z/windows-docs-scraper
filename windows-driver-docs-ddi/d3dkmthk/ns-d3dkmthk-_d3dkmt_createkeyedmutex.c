typedef struct _D3DKMT_CREATEKEYEDMUTEX {
  [in]  D3DKMT_ALIGN64 UINT64 InitialValue;
  [out] D3DKMT_HANDLE         hSharedHandle;
  [out] D3DKMT_HANDLE         hKeyedMutex;
} D3DKMT_CREATEKEYEDMUTEX;