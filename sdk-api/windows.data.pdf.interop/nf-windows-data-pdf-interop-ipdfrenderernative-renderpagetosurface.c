HRESULT RenderPageToSurface(
  [in]           IUnknown          *pdfPage,
  [in]           IDXGISurface      *pSurface,
  [in]           POINT             offset,
  [in, optional] PDF_RENDER_PARAMS *pRenderParams
);