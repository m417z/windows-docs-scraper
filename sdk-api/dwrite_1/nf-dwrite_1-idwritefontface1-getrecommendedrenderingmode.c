HRESULT GetRecommendedRenderingMode(
                 FLOAT                    fontEmSize,
                 FLOAT                    dpiX,
                 FLOAT                    dpiY,
  [in, optional] DWRITE_MATRIX const      *transform,
                 BOOL                     isSideways,
                 DWRITE_OUTLINE_THRESHOLD outlineThreshold,
                 DWRITE_MEASURING_MODE    measuringMode,
  [out]          DWRITE_RENDERING_MODE    *renderingMode
);