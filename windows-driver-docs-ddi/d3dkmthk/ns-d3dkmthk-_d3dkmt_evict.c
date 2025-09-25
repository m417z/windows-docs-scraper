typedef struct _D3DKMT_EVICT {
  [in]  D3DKMT_HANDLE         hDevice;
  [in]  UINT                  NumAllocations;
  [in]  const D3DKMT_HANDLE   *AllocationList;
  [in]  D3DDDI_EVICT_FLAGS    Flags;
  [out] D3DKMT_ALIGN64 UINT64 NumBytesToTrim;
} D3DKMT_EVICT;