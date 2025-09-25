typedef struct _DXGKARGCB_UPDATECONTEXTALLOCATION {
  [in] HANDLE hAllocation;
  [in] PVOID  pPrivateDriverData;
  [in] UINT   PrivateDriverDataSize;
} DXGKARGCB_UPDATECONTEXTALLOCATION;