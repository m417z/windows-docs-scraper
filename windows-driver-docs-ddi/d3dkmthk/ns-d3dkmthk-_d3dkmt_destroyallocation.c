typedef struct _D3DKMT_DESTROYALLOCATION {
  [in] D3DKMT_HANDLE       hDevice;
  [in] D3DKMT_HANDLE       hResource;
  [in] const D3DKMT_HANDLE *phAllocationList;
  [in] UINT                AllocationCount;
} D3DKMT_DESTROYALLOCATION;