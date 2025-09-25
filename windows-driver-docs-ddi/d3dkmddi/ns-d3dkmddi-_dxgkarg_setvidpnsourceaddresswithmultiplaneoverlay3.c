typedef struct _DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3 {
  D3DDDI_VIDEO_PRESENT_SOURCE_ID           VidPnSourceId;
  DXGK_SETVIDPNSOURCEADDRESS_INPUT_FLAGS   InputFlags;
  DXGK_SETVIDPNSOURCEADDRESS_OUTPUT_FLAGS  OutputFlags;
  UINT                                     PlaneCount;
  DXGK_MULTIPLANE_OVERLAY_PLANE3           **ppPlanes;
  DXGK_MULTIPLANE_OVERLAY_POST_COMPOSITION *pPostComposition;
  UINT                                     Duration;
  DXGK_HDR_METADATA                        *pHDRMetaData;
  UINT64                                   TargetFlipTime;
} DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY3;