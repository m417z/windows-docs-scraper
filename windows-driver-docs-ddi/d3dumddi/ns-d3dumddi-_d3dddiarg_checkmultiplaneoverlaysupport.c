typedef struct _D3DDDIARG_CHECKMULTIPLANEOVERLAYSUPPORT {
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID                     VidPnSourceId;
  [out] UINT                                               NumPlanes;
  [out] D3DDDI_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE_INFO *pPlanes;
  [out] BOOL                                               Supported;
} D3DDDIARG_CHECKMULTIPLANEOVERLAYSUPPORT;