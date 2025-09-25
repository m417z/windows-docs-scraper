HRESULT CreateRasterizer(
  [in, optional]  IXpsOMPage            *xpsPage,
  [in]            FLOAT                 DPI,
  [in]            XPSRAS_RENDERING_MODE nonTextRenderingMode,
  [in]            XPSRAS_RENDERING_MODE textRenderingMode,
                  XPSRAS_PIXEL_FORMAT   pixelFormat,
  [out, optional] IXpsRasterizer        **ppIXPSRasterizer
);