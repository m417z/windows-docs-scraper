typedef struct _D3DKMT_OPENKEYEDMUTEX {
  [in]  D3DKMT_HANDLE hSharedHandle;
  [out] D3DKMT_HANDLE hKeyedMutex;
} D3DKMT_OPENKEYEDMUTEX;