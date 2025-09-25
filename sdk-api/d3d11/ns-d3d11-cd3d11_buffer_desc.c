struct CD3D11_BUFFER_DESC : D3D11_BUFFER_DESC {
  void CD3D11_BUFFER_DESC();
  void CD3D11_BUFFER_DESC(
    const D3D11_BUFFER_DESC & o
  );
  void CD3D11_BUFFER_DESC(
    UINT        byteWidth,
    UINT        bindFlags,
    D3D11_USAGE usage,
    UINT        cpuaccessFlags,
    UINT        miscFlags,
    UINT        structureByteStride
  );
  void ~CD3D11_BUFFER_DESC();
};