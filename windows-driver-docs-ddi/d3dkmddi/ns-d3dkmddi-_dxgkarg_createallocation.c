typedef struct _DXGKARG_CREATEALLOCATION {
  [in]     const VOID                 *pPrivateDriverData;
  [in]     UINT                       PrivateDriverDataSize;
  [in]     UINT                       NumAllocations;
  [in/out] DXGK_ALLOCATIONINFO        *pAllocationInfo;
  [in/out] HANDLE                     hResource;
  [in]     DXGK_CREATEALLOCATIONFLAGS Flags;
} DXGKARG_CREATEALLOCATION;