typedef struct _DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY {
  [in] UINT                             ContextCount;
       HANDLE                           Context[1 + D3DDDI_MAX_BROADCAST_CONTEXT];
  [in] DXGK_SETVIDPNSOURCEADDRESS_FLAGS Flags;
       D3DDDI_VIDEO_PRESENT_SOURCE_ID   VidPnSourceId;
       UINT                             PlaneCount;
       DXGK_MULTIPLANE_OVERLAY_PLANE    *pPlanes;
       UINT                             Duration;
} DXGKARG_SETVIDPNSOURCEADDRESSWITHMULTIPLANEOVERLAY;