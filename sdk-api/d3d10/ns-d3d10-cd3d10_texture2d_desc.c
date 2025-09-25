struct CD3D10_TEXTURE2D_DESC : D3D10_TEXTURE2D_DESC {
  void CD3D10_TEXTURE2D_DESC();
  void CD3D10_TEXTURE2D_DESC(
    const D3D10_TEXTURE2D_DESC & o
  );
  void CD3D10_TEXTURE2D_DESC(
    DXGI_FORMAT format,
    UINT        width,
    UINT        height,
    UINT        arraySize,
    UINT        mipLevels,
    UINT        bindFlags,
    D3D10_USAGE usage,
    UINT        cpuaccessFlags,
    UINT        sampleCount,
    UINT        sampleQuality,
    UINT        miscFlags
  );
  void ~CD3D10_TEXTURE2D_DESC();
};