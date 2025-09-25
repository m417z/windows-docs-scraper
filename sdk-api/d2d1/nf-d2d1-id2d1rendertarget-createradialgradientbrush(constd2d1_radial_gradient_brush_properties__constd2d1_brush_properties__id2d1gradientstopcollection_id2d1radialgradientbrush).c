HRESULT CreateRadialGradientBrush(
  const D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES & radialGradientBrushProperties,
  const D2D1_BRUSH_PROPERTIES &                 brushProperties,
  ID2D1GradientStopCollection                   *gradientStopCollection,
  ID2D1RadialGradientBrush                      **radialGradientBrush
);