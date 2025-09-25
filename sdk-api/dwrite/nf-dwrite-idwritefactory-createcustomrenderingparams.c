HRESULT CreateCustomRenderingParams(
        FLOAT                  gamma,
        FLOAT                  enhancedContrast,
        FLOAT                  clearTypeLevel,
        DWRITE_PIXEL_GEOMETRY  pixelGeometry,
        DWRITE_RENDERING_MODE  renderingMode,
  [out] IDWriteRenderingParams **renderingParams
);