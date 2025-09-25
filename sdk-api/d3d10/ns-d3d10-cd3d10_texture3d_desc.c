struct CD3D10_TEXTURE3D_DESC : D3D10_TEXTURE3D_DESC {
  void CD3D10_TEXTURE3D_DESC();
  void CD3D10_TEXTURE3D_DESC(
    const D3D10_TEXTURE3D_DESC & o
  );
  void CD3D10_TEXTURE3D_DESC(
    DXGI_FORMAT format,
    UINT        width,
    UINT        height,
    UINT        depth,
    UINT        mipLevels,
    UINT        bindFlags,
    D3D10_USAGE usage,
    UINT        cpuaccessFlags,
    UINT        miscFlags
  );
  void ~CD3D10_TEXTURE3D_DESC();
};