typedef struct D3DKMT_CHECK_MULTIPLANE_OVERLAY_PLANE {
  D3DKMT_HANDLE                        hResource;
  LUID                                 CompSurfaceLuid;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID       VidPnSourceId;
  D3DKMT_MULTIPLANE_OVERLAY_ATTRIBUTES PlaneAttributes;
} D3DKMT_CHECK_MULTIPLANE_OVERLAY_PLANE;