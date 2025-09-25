typedef struct _D3DKMT_CREATEALLOCATION {
  [in]     D3DKMT_HANDLE                hDevice;
  [in/out] D3DKMT_HANDLE                hResource;
  [out]    D3DKMT_HANDLE                hGlobalShare;
  [in]     const VOID                   *pPrivateRuntimeData;
  [in]     UINT                         PrivateRuntimeDataSize;
  union {
    [in]     D3DKMT_CREATESTANDARDALLOCATION *pStandardAllocation;
    [in]     const VOID                      *pPrivateDriverData;
  };
  [in/out] UINT                         PrivateDriverDataSize;
  [in]     UINT                         NumAllocations;
  union {
    [in]     D3DDDI_ALLOCATIONINFO  *pAllocationInfo;
    [in]     D3DDDI_ALLOCATIONINFO2 *pAllocationInfo2;
  };
  [in]     D3DKMT_CREATEALLOCATIONFLAGS Flags;
  [in]     HANDLE                       hPrivateRuntimeResourceHandle;
} D3DKMT_CREATEALLOCATION;