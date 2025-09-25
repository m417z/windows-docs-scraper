typedef struct _DXGK_TARGETMODE_DETAIL_TIMING {
  [in] D3DKMDT_VIDEO_SIGNAL_STANDARD    VideoStandard;
  [in] UINT                             TimingId;
  [in] DISPLAYID_DETAILED_TIMING_TYPE_I DetailTiming;
} DXGK_TARGETMODE_DETAIL_TIMING;