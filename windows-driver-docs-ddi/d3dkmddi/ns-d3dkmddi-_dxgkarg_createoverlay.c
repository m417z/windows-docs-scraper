typedef struct _DXGKARG_CREATEOVERLAY {
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in]  DXGK_OVERLAYINFO               OverlayInfo;
  [out] HANDLE                         hOverlay;
} DXGKARG_CREATEOVERLAY;