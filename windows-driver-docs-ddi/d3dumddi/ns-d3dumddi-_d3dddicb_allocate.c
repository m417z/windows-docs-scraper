typedef struct _D3DDDICB_ALLOCATE {
  [in]  const VOID            *pPrivateDriverData;
  [in]  UINT                  PrivateDriverDataSize;
  [in]  HANDLE                hResource;
  [out] D3DKMT_HANDLE         hKMResource;
  [in]  UINT                  NumAllocations;
  union {
    [in]  D3DDDI_ALLOCATIONINFO  *pAllocationInfo;
    [in]  D3DDDI_ALLOCATIONINFO2 *pAllocationInfo2;
  };
  [in]  D3DDDI_ALLOCATIONINFO *pAllocationInfo;
} D3DDDICB_ALLOCATE;