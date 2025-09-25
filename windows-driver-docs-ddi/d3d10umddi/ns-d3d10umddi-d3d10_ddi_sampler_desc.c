typedef struct D3D10_DDI_SAMPLER_DESC {
  [in] D3D10_DDI_FILTER               Filter;
  [in] D3D10_DDI_TEXTURE_ADDRESS_MODE AddressU;
  [in] D3D10_DDI_TEXTURE_ADDRESS_MODE AddressV;
  [in] D3D10_DDI_TEXTURE_ADDRESS_MODE AddressW;
  [in] FLOAT                          MipLODBias;
  [in] UINT                           MaxAnisotropy;
  [in] D3D10_DDI_COMPARISON_FUNC      ComparisonFunc;
       FLOAT                          BorderColor[4];
  [in] FLOAT                          MinLOD;
  [in] FLOAT                          MaxLOD;
} D3D10_DDI_SAMPLER_DESC;