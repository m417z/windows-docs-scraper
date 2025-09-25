typedef struct D3DDDI_MAKERESIDENT {
  [in]     D3DKMT_HANDLE             hPagingQueue;
  [in/out] UINT                      NumAllocations;
  [in]     const D3DKMT_HANDLE       *AllocationList;
  [in]     const UINT                *PriorityList;
  [in]     D3DDDI_MAKERESIDENT_FLAGS Flags;
  [out]    D3DKMT_ALIGN64 UINT64     PagingFenceValue;
  [out]    D3DKMT_ALIGN64 UINT64     NumBytesToTrim;
} D3DDDI_MAKERESIDENT;