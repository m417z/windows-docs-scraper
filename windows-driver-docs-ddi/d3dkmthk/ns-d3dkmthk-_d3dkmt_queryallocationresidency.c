typedef struct _D3DKMT_QUERYALLOCATIONRESIDENCY {
  [in]  D3DKMT_HANDLE                    hDevice;
  [in]  D3DKMT_HANDLE                    hResource;
  [in]  const D3DKMT_HANDLE              *phAllocationList;
  [in]  UINT                             AllocationCount;
  [out] D3DKMT_ALLOCATIONRESIDENCYSTATUS *pResidencyStatus;
} D3DKMT_QUERYALLOCATIONRESIDENCY;