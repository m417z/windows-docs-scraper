HRESULT CreateGradientStopCollection(
  const D2D1_GRADIENT_STOP    *gradientStops,
  UINT32                      gradientStopsCount,
  D2D1_GAMMA                  colorInterpolationGamma,
  D2D1_EXTEND_MODE            extendMode,
  ID2D1GradientStopCollection **gradientStopCollection
);