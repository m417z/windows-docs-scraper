typedef struct D3D10_TEXTURE1D_DESC {
  UINT        Width;
  UINT        MipLevels;
  UINT        ArraySize;
  DXGI_FORMAT Format;
  D3D10_USAGE Usage;
  UINT        BindFlags;
  UINT        CPUAccessFlags;
  UINT        MiscFlags;
} D3D10_TEXTURE1D_DESC;