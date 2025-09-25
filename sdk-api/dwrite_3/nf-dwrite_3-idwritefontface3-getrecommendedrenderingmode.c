HRESULT GetRecommendedRenderingMode(
  [in]           FLOAT                    fontEmSize,
  [in]           FLOAT                    dpiX,
  [in]           FLOAT                    dpiY,
  [in, optional] DWRITE_MATRIX const      *transform,
  [in]           BOOL                     isSideways,
  [in]           DWRITE_OUTLINE_THRESHOLD outlineThreshold,
  [in]           DWRITE_MEASURING_MODE    measuringMode,
  [in, optional] IDWriteRenderingParams   *renderingParams,
  [out]          DWRITE_RENDERING_MODE1   *renderingMode,
  [out]          DWRITE_GRID_FIT_MODE     *gridFitMode
);