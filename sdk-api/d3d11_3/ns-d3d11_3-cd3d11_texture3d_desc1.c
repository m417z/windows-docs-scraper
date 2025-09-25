struct CD3D11_TEXTURE3D_DESC1 : D3D11_TEXTURE3D_DESC1 {
  void CD3D11_TEXTURE3D_DESC1();
  void CD3D11_TEXTURE3D_DESC1(
    const D3D11_TEXTURE3D_DESC1 & o
  );
  void CD3D11_TEXTURE3D_DESC1(
    DXGI_FORMAT          format,
    UINT                 width,
    UINT                 height,
    UINT                 depth,
    UINT                 mipLevels,
    UINT                 bindFlags,
    D3D11_USAGE          usage,
    UINT                 cpuaccessFlags,
    UINT                 miscFlags,
    D3D11_TEXTURE_LAYOUT textureLayout
  );
  void CD3D11_TEXTURE3D_DESC1(
    const D3D11_TEXTURE3D_DESC & desc,
    D3D11_TEXTURE_LAYOUT         textureLayout
  );
  void ~CD3D11_TEXTURE3D_DESC1();
};