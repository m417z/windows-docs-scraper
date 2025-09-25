typedef struct _D3DKMT_PRESENT_MULTIPLANE_OVERLAY3 {
  D3DKMT_HANDLE                              hAdapter;
  UINT                                       ContextCount;
  D3DKMT_HANDLE                              *pContextList;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID             VidPnSourceId;
  UINT                                       PresentCount;
  D3DKMT_PRESENT_MULTIPLANE_OVERLAY_FLAGS    Flags;
  UINT                                       PresentPlaneCount;
  D3DKMT_MULTIPLANE_OVERLAY3                 **ppPresentPlanes;
  D3DKMT_MULTIPLANE_OVERLAY_POST_COMPOSITION *pPostComposition;
  UINT                                       Duration;
  D3DDDI_HDR_METADATA_TYPE                   HDRMetaDataType;
  UINT                                       HDRMetaDataSize;
  const VOID                                 *pHDRMetaData;
  UINT                                       BoostRefreshRateMultiplier;
} D3DKMT_PRESENT_MULTIPLANE_OVERLAY3;