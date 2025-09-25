typedef struct _D3DKMT_DESTROYALLOCATION2 {
  [in] D3DKMT_HANDLE                    hDevice;
  [in] D3DKMT_HANDLE                    hResource;
  [in] const D3DKMT_HANDLE              *phAllocationList;
  [in] UINT                             AllocationCount;
  [in] D3DDDICB_DESTROYALLOCATION2FLAGS Flags;
} D3DKMT_DESTROYALLOCATION2;