typedef struct _DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYSUPPORT {
  [in]  DXGI_DDI_HDEVICE                                     hDevice;
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID                       VidPnSourceId;
  [out] UINT                                                 NumPlaneInfo;
  [out] DXGI_DDI_CHECK_MULTIPLANE_OVERLAY_SUPPORT_PLANE_INFO *pPlaneInfo;
  [out] BOOL                                                 Supported;
} DXGI_DDI_ARG_CHECKMULTIPLANEOVERLAYSUPPORT;