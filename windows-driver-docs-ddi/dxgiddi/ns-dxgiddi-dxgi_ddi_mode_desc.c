typedef struct DXGI_DDI_MODE_DESC {
  [out] UINT                         Width;
  [out] UINT                         Height;
  [out] DXGI_FORMAT                  Format;
  [out] DXGI_DDI_RATIONAL            RefreshRate;
  [out] DXGI_DDI_MODE_SCANLINE_ORDER ScanlineOrdering;
  [out] DXGI_DDI_MODE_ROTATION       Rotation;
  [out] DXGI_DDI_MODE_SCALING        Scaling;
} DXGI_DDI_MODE_DESC;