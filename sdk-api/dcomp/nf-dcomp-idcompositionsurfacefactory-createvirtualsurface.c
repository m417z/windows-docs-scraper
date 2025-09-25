HRESULT CreateVirtualSurface(
  [in]  UINT                        initialWidth,
  [in]  UINT                        initialHeight,
  [in]  DXGI_FORMAT                 pixelFormat,
  [in]  DXGI_ALPHA_MODE             alphaMode,
  [out] IDCompositionVirtualSurface **virtualSurface
);