typedef struct _DXGKARG_ACQUIRESWIZZLINGRANGE {
  [in]     HANDLE           hAllocation;
  [in]     UINT             PrivateDriverData;
  [in]     UINT             RangeId;
  [in]     UINT             SegmentId;
  [in]     SIZE_T           RangeSize;
  [in/out] PHYSICAL_ADDRESS CPUTranslatedAddress;
} DXGKARG_ACQUIRESWIZZLINGRANGE;