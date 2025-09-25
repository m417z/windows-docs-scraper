typedef struct D3D11_SAMPLER_DESC {
  D3D11_FILTER               Filter;
  D3D11_TEXTURE_ADDRESS_MODE AddressU;
  D3D11_TEXTURE_ADDRESS_MODE AddressV;
  D3D11_TEXTURE_ADDRESS_MODE AddressW;
  FLOAT                      MipLODBias;
  UINT                       MaxAnisotropy;
  D3D11_COMPARISON_FUNC      ComparisonFunc;
  FLOAT                      BorderColor[4];
  FLOAT                      MinLOD;
  FLOAT                      MaxLOD;
} D3D11_SAMPLER_DESC;