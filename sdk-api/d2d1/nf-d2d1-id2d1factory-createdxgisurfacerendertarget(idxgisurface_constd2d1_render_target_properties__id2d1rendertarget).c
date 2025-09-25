HRESULT CreateDxgiSurfaceRenderTarget(
  [in]  IDXGISurface                          *dxgiSurface,
  [ref] const D2D1_RENDER_TARGET_PROPERTIES & renderTargetProperties,
  [out] ID2D1RenderTarget                     **renderTarget
);