typedef struct _DXGKARG_DESTROYALLOCATION {
  [in]     UINT                        NumAllocations;
  [in]     const HANDLE                *pAllocationList;
  [in/out] HANDLE                      hResource;
  [in]     DXGK_DESTROYALLOCATIONFLAGS Flags;
} DXGKARG_DESTROYALLOCATION;