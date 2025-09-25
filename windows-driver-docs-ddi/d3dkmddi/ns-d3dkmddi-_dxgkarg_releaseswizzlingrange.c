typedef struct _DXGKARG_RELEASESWIZZLINGRANGE {
  [in] HANDLE hAllocation;
  [in] UINT   PrivateDriverData;
  [in] UINT   RangeId;
} DXGKARG_RELEASESWIZZLINGRANGE;