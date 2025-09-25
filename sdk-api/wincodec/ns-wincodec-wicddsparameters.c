typedef struct WICDdsParameters {
  UINT            Width;
  UINT            Height;
  UINT            Depth;
  UINT            MipLevels;
  UINT            ArraySize;
  DXGI_FORMAT     DxgiFormat;
  WICDdsDimension Dimension;
  WICDdsAlphaMode AlphaMode;
} WICDdsParameters;