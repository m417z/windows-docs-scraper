typedef struct D3D10_TEXTURE3D_DESC {
  UINT        Width;
  UINT        Height;
  UINT        Depth;
  UINT        MipLevels;
  DXGI_FORMAT Format;
  D3D10_USAGE Usage;
  UINT        BindFlags;
  UINT        CPUAccessFlags;
  UINT        MiscFlags;
} D3D10_TEXTURE3D_DESC;