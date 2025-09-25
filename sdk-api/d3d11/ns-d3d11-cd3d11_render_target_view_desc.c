struct CD3D11_RENDER_TARGET_VIEW_DESC : D3D11_RENDER_TARGET_VIEW_DESC {
  void CD3D11_RENDER_TARGET_VIEW_DESC();
  void CD3D11_RENDER_TARGET_VIEW_DESC(
    const D3D11_RENDER_TARGET_VIEW_DESC & o
  );
  void CD3D11_RENDER_TARGET_VIEW_DESC(
    D3D11_RTV_DIMENSION viewDimension,
    DXGI_FORMAT         format,
    UINT                mipSlice,
    UINT                firstArraySlice,
    UINT                arraySize
  );
  void CD3D11_RENDER_TARGET_VIEW_DESC(
    ID3D11Buffer *unnamedParam1,
    DXGI_FORMAT  format,
    UINT         firstElement,
    UINT         numElements
  );
  void CD3D11_RENDER_TARGET_VIEW_DESC(
    ID3D11Texture1D     *pTex1D,
    D3D11_RTV_DIMENSION viewDimension,
    DXGI_FORMAT         format,
    UINT                mipSlice,
    UINT                firstArraySlice,
    UINT                arraySize
  );
  void CD3D11_RENDER_TARGET_VIEW_DESC(
    ID3D11Texture2D     *pTex2D,
    D3D11_RTV_DIMENSION viewDimension,
    DXGI_FORMAT         format,
    UINT                mipSlice,
    UINT                firstArraySlice,
    UINT                arraySize
  );
  void CD3D11_RENDER_TARGET_VIEW_DESC(
    ID3D11Texture3D *pTex3D,
    DXGI_FORMAT     format,
    UINT            mipSlice,
    UINT            firstWSlice,
    UINT            wSize
  );
  void ~CD3D11_RENDER_TARGET_VIEW_DESC();
};