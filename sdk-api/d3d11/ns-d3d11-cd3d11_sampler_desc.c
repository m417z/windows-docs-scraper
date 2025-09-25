struct CD3D11_SAMPLER_DESC : D3D11_SAMPLER_DESC {
  void CD3D11_SAMPLER_DESC();
  void CD3D11_SAMPLER_DESC(
    const D3D11_SAMPLER_DESC & o
  );
  void CD3D11_SAMPLER_DESC(
    CD3D11_DEFAULT unnamedParam1
  );
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
  void ~CD3D11_SAMPLER_DESC();
};