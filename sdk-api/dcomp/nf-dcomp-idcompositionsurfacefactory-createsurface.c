HRESULT CreateSurface(
  [in]  UINT                 width,
  [in]  UINT                 height,
  [in]  DXGI_FORMAT          pixelFormat,
  [in]  DXGI_ALPHA_MODE      alphaMode,
  [out] IDCompositionSurface **surface
);