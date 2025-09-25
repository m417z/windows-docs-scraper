typedef struct _D3DKMT_GETALLOCATIONPRIORITY {
  [in]  D3DKMT_HANDLE       hDevice;
  [in]  D3DKMT_HANDLE       hResource;
  [in]  const D3DKMT_HANDLE *phAllocationList;
  [in]  UINT                AllocationCount;
  [out] UINT                *pPriorities;
} D3DKMT_GETALLOCATIONPRIORITY;