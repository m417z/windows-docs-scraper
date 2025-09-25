struct CD3D11_TEXTURE1D_DESC : D3D11_TEXTURE1D_DESC {
  void CD3D11_TEXTURE1D_DESC();
  void CD3D11_TEXTURE1D_DESC(
    const D3D11_TEXTURE1D_DESC & o
  );
  void CD3D11_TEXTURE1D_DESC(
    DXGI_FORMAT format,
    UINT        width,
    UINT        arraySize,
    UINT        mipLevels,
    UINT        bindFlags,
    D3D11_USAGE usage,
    UINT        cpuaccessFlags,
    UINT        miscFlags
  );
  void ~CD3D11_TEXTURE1D_DESC();
};