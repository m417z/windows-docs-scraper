typedef struct DXGI_MODE_DESC1 {
  UINT                     Width;
  UINT                     Height;
  DXGI_RATIONAL            RefreshRate;
  DXGI_FORMAT              Format;
  DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
  DXGI_MODE_SCALING        Scaling;
  BOOL                     Stereo;
} DXGI_MODE_DESC1;