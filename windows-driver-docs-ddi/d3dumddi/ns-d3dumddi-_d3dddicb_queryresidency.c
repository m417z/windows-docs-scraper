typedef struct _D3DDDICB_QUERYRESIDENCY {
  [in]  HANDLE                 hResource;
  [in]  UINT                   NumAllocations;
  [in]  const D3DKMT_HANDLE    *HandleList;
  [out] D3DDDI_RESIDENCYSTATUS *pResidencyStatus;
} D3DDDICB_QUERYRESIDENCY;