struct CD3D10_BUFFER_DESC : D3D10_BUFFER_DESC {
  void CD3D10_BUFFER_DESC();
  void CD3D10_BUFFER_DESC(
    const D3D10_BUFFER_DESC & o
  );
  void CD3D10_BUFFER_DESC(
    UINT        byteWidth,
    UINT        bindFlags,
    D3D10_USAGE usage,
    UINT        cpuaccessFlags,
    UINT        miscFlags
  );
  void ~CD3D10_BUFFER_DESC();
};