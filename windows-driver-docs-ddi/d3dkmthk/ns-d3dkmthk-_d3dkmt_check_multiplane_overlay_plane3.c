typedef struct _D3DKMT_CHECK_MULTIPLANE_OVERLAY_PLANE3 {
  UINT                                  LayerIndex;
  D3DKMT_HANDLE                         hResource;
  LUID                                  CompSurfaceLuid;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID        VidPnSourceId;
  D3DKMT_MULTIPLANE_OVERLAY_ATTRIBUTES3 *pPlaneAttributes;
} D3DKMT_CHECK_MULTIPLANE_OVERLAY_PLANE3;