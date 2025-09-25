typedef struct D3D12_STATIC_SAMPLER_DESC {
  D3D12_FILTER               Filter;
  D3D12_TEXTURE_ADDRESS_MODE AddressU;
  D3D12_TEXTURE_ADDRESS_MODE AddressV;
  D3D12_TEXTURE_ADDRESS_MODE AddressW;
  FLOAT                      MipLODBias;
  UINT                       MaxAnisotropy;
  D3D12_COMPARISON_FUNC      ComparisonFunc;
  D3D12_STATIC_BORDER_COLOR  BorderColor;
  FLOAT                      MinLOD;
  FLOAT                      MaxLOD;
  UINT                       ShaderRegister;
  UINT                       RegisterSpace;
  D3D12_SHADER_VISIBILITY    ShaderVisibility;
} D3D12_STATIC_SAMPLER_DESC;