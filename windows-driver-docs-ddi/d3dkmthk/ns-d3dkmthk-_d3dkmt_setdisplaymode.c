typedef struct _D3DKMT_SETDISPLAYMODE {
  [in]  D3DKMT_HANDLE                         hDevice;
  [in]  D3DKMT_HANDLE                         hPrimaryAllocation;
  [in]  D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING ScanLineOrdering;
  [in]  D3DDDI_ROTATION                       DisplayOrientation;
  [out] UINT                                  PrivateDriverFormatAttribute;
  [in]  D3DKMT_SETDISPLAYMODE_FLAGS           Flags;
} D3DKMT_SETDISPLAYMODE;