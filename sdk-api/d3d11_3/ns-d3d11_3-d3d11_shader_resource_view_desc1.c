typedef struct D3D11_SHADER_RESOURCE_VIEW_DESC1 {
  DXGI_FORMAT         Format;
  D3D11_SRV_DIMENSION ViewDimension;
  union {
    D3D11_BUFFER_SRV        Buffer;
    D3D11_TEX1D_SRV         Texture1D;
    D3D11_TEX1D_ARRAY_SRV   Texture1DArray;
    D3D11_TEX2D_SRV1        Texture2D;
    D3D11_TEX2D_ARRAY_SRV1  Texture2DArray;
    D3D11_TEX2DMS_SRV       Texture2DMS;
    D3D11_TEX2DMS_ARRAY_SRV Texture2DMSArray;
    D3D11_TEX3D_SRV         Texture3D;
    D3D11_TEXCUBE_SRV       TextureCube;
    D3D11_TEXCUBE_ARRAY_SRV TextureCubeArray;
    D3D11_BUFFEREX_SRV      BufferEx;
  };
} D3D11_SHADER_RESOURCE_VIEW_DESC1;