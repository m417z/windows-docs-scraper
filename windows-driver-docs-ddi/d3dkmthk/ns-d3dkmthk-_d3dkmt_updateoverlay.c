typedef struct _D3DKMT_UPDATEOVERLAY {
  [in] D3DKMT_HANDLE            hDevice;
  [in] D3DKMT_HANDLE            hOverlay;
  [in] D3DDDI_KERNELOVERLAYINFO OverlayInfo;
} D3DKMT_UPDATEOVERLAY;