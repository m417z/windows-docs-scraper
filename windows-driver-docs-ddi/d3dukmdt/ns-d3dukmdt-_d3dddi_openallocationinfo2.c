typedef struct _D3DDDI_OPENALLOCATIONINFO2 {
  [in]  D3DKMT_HANDLE                         hAllocation;
  [in]  const VOID                            *pPrivateDriverData;
  [in]  UINT                                  PrivateDriverDataSize;
  [out] D3DKMT_ALIGN64 D3DGPU_VIRTUAL_ADDRESS GpuVirtualAddress;
        D3DKMT_ALIGN64 ULONG_PTR              Reserved[6];
} D3DDDI_OPENALLOCATIONINFO2;