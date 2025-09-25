typedef struct _DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2 {
  UINT                             ContextCount;
  HANDLE                           Context[1 + D3DDDI_MAX_BROADCAST_CONTEXT];
  DXGK_SETVIDPNSOURCEADDRESS_FLAGS Flags;
  D3DDDI_VIDEO_PRESENT_SOURCE_ID   VidPnSourceId;
  UINT                             PlaneCount;
  DXGK_MULTIPLANE_OVERLAY_PLANE2   *pPlanes;
  UINT                             Duration;
} DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY2;