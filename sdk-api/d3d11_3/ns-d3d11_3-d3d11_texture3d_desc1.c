typedef struct D3D11_TEXTURE3D_DESC1 {
  UINT                 Width;
  UINT                 Height;
  UINT                 Depth;
  UINT                 MipLevels;
  DXGI_FORMAT          Format;
  D3D11_USAGE          Usage;
  UINT                 BindFlags;
  UINT                 CPUAccessFlags;
  UINT                 MiscFlags;
  D3D11_TEXTURE_LAYOUT TextureLayout;
} D3D11_TEXTURE3D_DESC1;