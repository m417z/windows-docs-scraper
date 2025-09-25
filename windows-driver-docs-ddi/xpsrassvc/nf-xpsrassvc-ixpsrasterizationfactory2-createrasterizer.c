HRESULT CreateRasterizer(
  [in, optional]  IXpsOMPage              *xpsPage,
  [in]            FLOAT                   DPIX,
  [in]            FLOAT                   DPIY,
  [in]            XPSRAS_RENDERING_MODE   nonTextRenderingMode,
  [in]            XPSRAS_RENDERING_MODE   textRenderingMode,
  [in]            XPSRAS_PIXEL_FORMAT     pixelFormat,
  [in]            XPSRAS_BACKGROUND_COLOR backgroundColor,
  [out, optional] IXpsRasterizer          **ppIXpsRasterizer
);