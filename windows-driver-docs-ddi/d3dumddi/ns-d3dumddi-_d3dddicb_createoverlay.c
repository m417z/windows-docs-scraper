typedef struct _D3DDDICB_CREATEOVERLAY {
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in]  D3DDDI_KERNELOVERLAYINFO       OverlayInfo;
  [out] D3DKMT_HANDLE                  hKernelOverlay;
} D3DDDICB_CREATEOVERLAY;