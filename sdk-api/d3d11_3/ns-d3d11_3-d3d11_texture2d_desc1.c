typedef struct D3D11_TEXTURE2D_DESC1 {
  UINT                 Width;
  UINT                 Height;
  UINT                 MipLevels;
  UINT                 ArraySize;
  DXGI_FORMAT          Format;
  DXGI_SAMPLE_DESC     SampleDesc;
  D3D11_USAGE          Usage;
  UINT                 BindFlags;
  UINT                 CPUAccessFlags;
  UINT                 MiscFlags;
  D3D11_TEXTURE_LAYOUT TextureLayout;
} D3D11_TEXTURE2D_DESC1;