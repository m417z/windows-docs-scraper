typedef struct _D3DKMT_DISPLAYMODE {
  [out] UINT                                  Width;
  [out] UINT                                  Height;
  [out] D3DDDIFORMAT                          Format;
  [out] UINT                                  IntegerRefreshRate;
  [out] D3DDDI_RATIONAL                       RefreshRate;
  [out] D3DDDI_VIDEO_SIGNAL_SCANLINE_ORDERING ScanLineOrdering;
  [out] D3DDDI_ROTATION                       DisplayOrientation;
  [out] UINT                                  DisplayFixedOutput;
  [out] D3DKMDT_DISPLAYMODE_FLAGS             Flags;
} D3DKMT_DISPLAYMODE;