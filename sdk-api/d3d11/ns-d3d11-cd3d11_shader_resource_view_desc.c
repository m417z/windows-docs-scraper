struct CD3D11_SHADER_RESOURCE_VIEW_DESC : D3D11_SHADER_RESOURCE_VIEW_DESC {
  void CD3D11_SHADER_RESOURCE_VIEW_DESC();
  void CD3D11_SHADER_RESOURCE_VIEW_DESC(
    const D3D11_SHADER_RESOURCE_VIEW_DESC & o
  );
  void CD3D11_SHADER_RESOURCE_VIEW_DESC(
    D3D11_SRV_DIMENSION viewDimension,
    DXGI_FORMAT         format,
    UINT                mostDetailedMip,
    UINT                mipLevels,
    UINT                firstArraySlice,
    UINT                arraySize,
    UINT                flags
  );
  void CD3D11_SHADER_RESOURCE_VIEW_DESC(
    ID3D11Buffer *unnamedParam1,
    DXGI_FORMAT  format,
    UINT         firstElement,
    UINT         numElements,
    UINT         flags
  );
  void CD3D11_SHADER_RESOURCE_VIEW_DESC(
    ID3D11Texture1D     *pTex1D,
    D3D11_SRV_DIMENSION viewDimension,
    DXGI_FORMAT         format,
    UINT                mostDetailedMip,
    UINT                mipLevels,
    UINT                firstArraySlice,
    UINT                arraySize
  );
  void CD3D11_SHADER_RESOURCE_VIEW_DESC(
    ID3D11Texture2D     *pTex2D,
    D3D11_SRV_DIMENSION viewDimension,
    DXGI_FORMAT         format,
    UINT                mostDetailedMip,
    UINT                mipLevels,
    UINT                firstArraySlice,
    UINT                arraySize
  );
  void CD3D11_SHADER_RESOURCE_VIEW_DESC(
    ID3D11Texture3D *pTex3D,
    DXGI_FORMAT     format,
    UINT            mostDetailedMip,
    UINT            mipLevels
  );
  void ~CD3D11_SHADER_RESOURCE_VIEW_DESC();
};