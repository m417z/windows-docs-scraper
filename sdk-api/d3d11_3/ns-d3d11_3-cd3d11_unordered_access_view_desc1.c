struct CD3D11_UNORDERED_ACCESS_VIEW_DESC1 : D3D11_UNORDERED_ACCESS_VIEW_DESC1 {
  void CD3D11_UNORDERED_ACCESS_VIEW_DESC1();
  void CD3D11_UNORDERED_ACCESS_VIEW_DESC1(
    const D3D11_UNORDERED_ACCESS_VIEW_DESC1 & o
  );
  void CD3D11_UNORDERED_ACCESS_VIEW_DESC1(
    D3D11_UAV_DIMENSION viewDimension,
    DXGI_FORMAT         format,
    UINT                mipSlice,
    UINT                firstArraySlice,
    UINT                arraySize,
    UINT                flags,
    UINT                planeSlice
  );
  void CD3D11_UNORDERED_ACCESS_VIEW_DESC1(
    ID3D11Buffer *unnamedParam1,
    DXGI_FORMAT  format,
    UINT         firstElement,
    UINT         numElements,
    UINT         flags
  );
  void CD3D11_UNORDERED_ACCESS_VIEW_DESC1(
    ID3D11Texture1D     *pTex1D,
    D3D11_UAV_DIMENSION viewDimension,
    DXGI_FORMAT         format,
    UINT                mipSlice,
    UINT                firstArraySlice,
    UINT                arraySize
  );
  void CD3D11_UNORDERED_ACCESS_VIEW_DESC1(
    ID3D11Texture2D     *pTex2D,
    D3D11_UAV_DIMENSION viewDimension,
    DXGI_FORMAT         format,
    UINT                mipSlice,
    UINT                firstArraySlice,
    UINT                arraySize,
    UINT                planeSlice
  );
  void CD3D11_UNORDERED_ACCESS_VIEW_DESC1(
    ID3D11Texture3D *pTex3D,
    DXGI_FORMAT     format,
    UINT            mipSlice,
    UINT            firstWSlice,
    UINT            wSize
  );
  void ~CD3D11_UNORDERED_ACCESS_VIEW_DESC1();
};