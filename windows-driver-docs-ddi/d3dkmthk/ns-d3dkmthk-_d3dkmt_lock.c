typedef struct _D3DKMT_LOCK {
  [in]  D3DKMT_HANDLE          hDevice;
  [in]  D3DKMT_HANDLE          hAllocation;
  [in]  UINT                   PrivateDriverData;
  [in]  UINT                   NumPages;
  [in]  const UINT             *pPages;
  [out] VOID                   *pData;
  [in]  D3DDDICB_LOCKFLAGS     Flags;
        D3DGPU_VIRTUAL_ADDRESS GpuVirtualAddress;
} D3DKMT_LOCK;