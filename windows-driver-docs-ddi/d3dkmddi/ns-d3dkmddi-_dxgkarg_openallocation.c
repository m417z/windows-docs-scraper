typedef struct _DXGKARG_OPENALLOCATION {
  [in]     UINT                     NumAllocations;
  [in/out] DXGK_OPENALLOCATIONINFO  *pOpenAllocation;
  [in]     VOID                     *pPrivateDriverData;
  [in]     UINT                     PrivateDriverSize;
  [in]     DXGK_OPENALLOCATIONFLAGS Flags;
  [in]     UINT                     SubresourceIndex;
  [out]    SIZE_T                   SubresourceOffset;
  [out]    UINT                     Pitch;
} DXGKARG_OPENALLOCATION;