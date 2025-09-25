typedef struct D3DDDICB_EVICT {
  [in]  UINT                NumAllocations;
  [in]  const D3DKMT_HANDLE *AllocationList;
  [in]  D3DDDI_EVICT_FLAGS  Flags;
  [out] UINT64              NumBytesToTrim;
} D3DDDICB_EVICT;