typedef struct D3D10_SAMPLER_DESC {
  D3D10_FILTER               Filter;
  D3D10_TEXTURE_ADDRESS_MODE AddressU;
  D3D10_TEXTURE_ADDRESS_MODE AddressV;
  D3D10_TEXTURE_ADDRESS_MODE AddressW;
  FLOAT                      MipLODBias;
  UINT                       MaxAnisotropy;
  D3D10_COMPARISON_FUNC      ComparisonFunc;
  FLOAT                      BorderColor[4];
  FLOAT                      MinLOD;
  FLOAT                      MaxLOD;
} D3D10_SAMPLER_DESC;