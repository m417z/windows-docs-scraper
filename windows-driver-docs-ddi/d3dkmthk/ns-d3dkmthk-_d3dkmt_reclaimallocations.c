typedef struct _D3DKMT_RECLAIMALLOCATIONS {
  [in]  D3DKMT_HANDLE       hDevice;
  [in]  D3DKMT_HANDLE       *pResources;
  [in]  const D3DKMT_HANDLE *HandleList;
  [out] BOOL                *pDiscarded;
  [in]  UINT                NumAllocations;
} D3DKMT_RECLAIMALLOCATIONS;