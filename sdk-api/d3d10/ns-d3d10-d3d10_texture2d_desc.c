typedef struct D3D10_TEXTURE2D_DESC {
  UINT             Width;
  UINT             Height;
  UINT             MipLevels;
  UINT             ArraySize;
  DXGI_FORMAT      Format;
  DXGI_SAMPLE_DESC SampleDesc;
  D3D10_USAGE      Usage;
  UINT             BindFlags;
  UINT             CPUAccessFlags;
  UINT             MiscFlags;
} D3D10_TEXTURE2D_DESC;