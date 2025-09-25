typedef struct _DXGK_OVERLAYINFO {
  [in] HANDLE           hAllocation;
  [in] PHYSICAL_ADDRESS PhysicalAddress;
  [in] UINT             SegmentId;
  [in] RECT             DstRect;
  [in] RECT             SrcRect;
  [in] VOID             *pPrivateDriverData;
  [in] UINT             PrivateDriverDataSize;
} DXGK_OVERLAYINFO;