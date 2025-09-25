typedef struct _D3D12DDICB_RECLAIMALLOCATIONS2 {
  [in]  UINT                NumAllocations;
  [in]  const D3DKMT_HANDLE *HandleList;
  [out] BOOL                *pDiscarded;
  [out] UINT64              PagingFenceValue;
} D3D12DDICB_RECLAIMALLOCATIONS2;