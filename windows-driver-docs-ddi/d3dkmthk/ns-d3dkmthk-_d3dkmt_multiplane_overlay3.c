typedef struct _D3DKMT_MULTIPLANE_OVERLAY3 {
  UINT                                        LayerIndex;
  D3DKMT_PLANE_SPECIFIC_INPUT_FLAGS           InputFlags;
  D3DDDI_FLIPINTERVAL_TYPE                    FlipInterval;
  UINT                                        MaxImmediateFlipLine;
  UINT                                        AllocationCount;
  D3DKMT_HANDLE                               *pAllocationList;
  UINT                                        DriverPrivateDataSize;
  VOID                                        *pDriverPrivateData;
  const D3DKMT_MULTIPLANE_OVERLAY_ATTRIBUTES3 *pPlaneAttributes;
  D3DKMT_HANDLE                               hFlipToFence;
  D3DKMT_HANDLE                               hFlipAwayFence;
  D3DKMT_ALIGN64 UINT64                       FlipToFenceValue;
  D3DKMT_ALIGN64 UINT64                       FlipAwayFenceValue;
} D3DKMT_MULTIPLANE_OVERLAY3;