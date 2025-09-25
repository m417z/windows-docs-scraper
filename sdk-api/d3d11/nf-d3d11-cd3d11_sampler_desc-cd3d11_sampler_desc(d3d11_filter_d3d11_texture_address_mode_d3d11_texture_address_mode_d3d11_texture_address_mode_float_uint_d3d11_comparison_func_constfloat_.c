void CD3D11_SAMPLER_DESC(
  D3D11_FILTER               filter,
  D3D11_TEXTURE_ADDRESS_MODE addressU,
  D3D11_TEXTURE_ADDRESS_MODE addressV,
  D3D11_TEXTURE_ADDRESS_MODE addressW,
  FLOAT                      mipLODBias,
  UINT                       maxAnisotropy,
  D3D11_COMPARISON_FUNC      comparisonFunc,
  const FLOAT                *borderColor,
  FLOAT                      minLOD,
  FLOAT                      maxLOD
);