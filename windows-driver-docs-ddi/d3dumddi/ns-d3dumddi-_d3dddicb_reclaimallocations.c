typedef struct _D3DDDICB_RECLAIMALLOCATIONS {
  [in]  const HANDLE        *pResources;
  [in]  const D3DKMT_HANDLE *HandleList;
  [out] BOOL                *pDiscarded;
  [in]  UINT                NumAllocations;
} D3DDDICB_RECLAIMALLOCATIONS;