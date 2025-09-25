typedef struct DXGI_SWAP_CHAIN_FULLSCREEN_DESC {
  DXGI_RATIONAL            RefreshRate;
  DXGI_MODE_SCANLINE_ORDER ScanlineOrdering;
  DXGI_MODE_SCALING        Scaling;
  BOOL                     Windowed;
} DXGI_SWAP_CHAIN_FULLSCREEN_DESC;