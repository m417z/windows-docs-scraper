HRESULT CreateDepthStencilView(
  [in]            ID3D11Resource                      *pResource,
  [in, optional]  const D3D11_DEPTH_STENCIL_VIEW_DESC *pDesc,
  [out, optional] ID3D11DepthStencilView              **ppDepthStencilView
);