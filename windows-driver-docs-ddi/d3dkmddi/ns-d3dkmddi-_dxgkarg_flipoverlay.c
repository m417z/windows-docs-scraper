typedef struct _DXGKARG_FLIPOVERLAY {
  [in] HANDLE           hSource;
  [in] PHYSICAL_ADDRESS SrcPhysicalAddress;
  [in] UINT             SrcSegmentId;
  [in] VOID             *pPrivateDriverData;
  [in] UINT             PrivateDriverDataSize;
} DXGKARG_FLIPOVERLAY;