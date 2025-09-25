HRESULT CreateCustomRenderingParams(
        FLOAT                   gamma,
        FLOAT                   enhancedContrast,
        FLOAT                   grayscaleEnhancedContrast,
        FLOAT                   clearTypeLevel,
        DWRITE_PIXEL_GEOMETRY   pixelGeometry,
        DWRITE_RENDERING_MODE1  renderingMode,
        DWRITE_GRID_FIT_MODE    gridFitMode,
  [out] IDWriteRenderingParams3 **renderingParams
);