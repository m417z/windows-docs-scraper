typedef struct _DXGK_MULTIPLANE_OVERLAY_PLANE_WITH_SOURCE {
  HANDLE                              hAllocation;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID      VidPnSourceId;
  UINT                                LayerIndex;
  DXGK_MULTIPLANE_OVERLAY_ATTRIBUTES2 PlaneAttributes;
} DXGK_MULTIPLANE_OVERLAY_PLANE_WITH_SOURCE;