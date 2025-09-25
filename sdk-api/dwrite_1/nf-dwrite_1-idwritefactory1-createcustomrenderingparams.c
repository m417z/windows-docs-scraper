HRESULT CreateCustomRenderingParams(
        FLOAT                   gamma,
        FLOAT                   enhancedContrast,
        FLOAT                   enhancedContrastGrayscale,
        FLOAT                   clearTypeLevel,
        DWRITE_PIXEL_GEOMETRY   pixelGeometry,
        DWRITE_RENDERING_MODE   renderingMode,
  [out] IDWriteRenderingParams1 **renderingParams
);