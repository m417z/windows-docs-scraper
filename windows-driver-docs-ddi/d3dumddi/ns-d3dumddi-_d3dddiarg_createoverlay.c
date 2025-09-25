typedef struct _D3DDDIARG_CREATEOVERLAY {
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in]  D3DDDI_OVERLAYINFO             OverlayInfo;
  [out] HANDLE                         hOverlay;
} D3DDDIARG_CREATEOVERLAY;