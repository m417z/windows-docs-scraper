struct CD3D11_DEPTH_STENCIL_VIEW_DESC : D3D11_DEPTH_STENCIL_VIEW_DESC {
  void CD3D11_DEPTH_STENCIL_VIEW_DESC();
  void CD3D11_DEPTH_STENCIL_VIEW_DESC(
    const D3D11_DEPTH_STENCIL_VIEW_DESC & o
  );
  void CD3D11_DEPTH_STENCIL_VIEW_DESC(
    D3D11_DSV_DIMENSION viewDimension,
    DXGI_FORMAT         format,
    UINT                mipSlice,
    UINT                firstArraySlice,
    UINT                arraySize,
    UINT                flags
  );
  void CD3D11_DEPTH_STENCIL_VIEW_DESC(
    ID3D11Texture1D     *pTex1D,
    D3D11_DSV_DIMENSION viewDimension,
    DXGI_FORMAT         format,
    UINT                mipSlice,
    UINT                firstArraySlice,
    UINT                arraySize,
    UINT                flags
  );
  void CD3D11_DEPTH_STENCIL_VIEW_DESC(
    ID3D11Texture2D     *pTex2D,
    D3D11_DSV_DIMENSION viewDimension,
    DXGI_FORMAT         format,
    UINT                mipSlice,
    UINT                firstArraySlice,
    UINT                arraySize,
    UINT                flags
  );
  void ~CD3D11_DEPTH_STENCIL_VIEW_DESC();
};