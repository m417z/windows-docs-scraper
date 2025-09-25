typedef struct _D3DKMT_CREATEOVERLAY {
  [in]  D3DDDI_VIDEO_PRESENT_SOURCE_ID VidPnSourceId;
  [in]  D3DKMT_HANDLE                  hDevice;
  [in]  D3DDDI_KERNELOVERLAYINFO       OverlayInfo;
  [out] D3DKMT_HANDLE                  hOverlay;
} D3DKMT_CREATEOVERLAY;