typedef struct _D3DKMT_GETOVERLAYSTATE {
  [in]  D3DKMT_HANDLE hDevice;
  [in]  D3DKMT_HANDLE hOverlay;
  [out] BOOLEAN       OverlayEnabled;
} D3DKMT_GETOVERLAYSTATE;