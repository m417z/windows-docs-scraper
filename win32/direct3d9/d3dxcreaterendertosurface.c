HRESULT D3DXCreateRenderToSurface(
  _In_  LPDIRECT3DDEVICE9     pDevice,
  _In_  UINT                  Width,
  _In_  UINT                  Height,
  _In_  D3DFORMAT             Format,
  _In_  BOOL                  DepthStencil,
  _In_  D3DFORMAT             DepthStencilFormat,
  _Out_ LPD3DXRENDERTOSURFACE *ppRenderToSurface
);