struct CD3D11_TEXTURE3D_DESC : D3D11_TEXTURE3D_DESC {
  void CD3D11_TEXTURE3D_DESC();
  void CD3D11_TEXTURE3D_DESC(
    const D3D11_TEXTURE3D_DESC & o
  );
  void CD3D11_TEXTURE3D_DESC(
    DXGI_FORMAT format,
    UINT        width,
    UINT        height,
    UINT        depth,
    UINT        mipLevels,
    UINT        bindFlags,
    D3D11_USAGE usage,
    UINT        cpuaccessFlags,
    UINT        miscFlags
  );
  void ~CD3D11_TEXTURE3D_DESC();
};