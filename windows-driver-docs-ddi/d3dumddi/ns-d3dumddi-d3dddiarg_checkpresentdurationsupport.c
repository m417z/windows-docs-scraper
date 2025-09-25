typedef struct D3DDDIARG_CHECKPRESENTDURATIONSUPPORT {
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in]  UINT                           DesiredPresentDuration;
  [out] UINT                           ClosestSmallerDuration;
  [out] UINT                           ClosestLargerDuration;
} D3DDDIARG_CHECKPRESENTDURATIONSUPPORT;