typedef struct _D3DKMT_UNLOCK {
  [in] D3DKMT_HANDLE       hDevice;
  [in] UINT                NumAllocations;
  [in] const D3DKMT_HANDLE *phAllocations;
} D3DKMT_UNLOCK;