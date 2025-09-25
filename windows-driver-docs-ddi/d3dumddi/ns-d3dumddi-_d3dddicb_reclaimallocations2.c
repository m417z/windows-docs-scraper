typedef struct _D3DDDICB_RECLAIMALLOCATIONS2 {
  [in]  D3DKMT_HANDLE       PagingQueue;
  [in]  UINT                NumAllocations;
  [in]  const HANDLE        *pResources;
  [in]  const D3DKMT_HANDLE *HandleList;
  [out] BOOL                *pDiscarded;
  [out] UINT64              PagingFenceValue;
} D3DDDICB_RECLAIMALLOCATIONS2;