HRESULT CreateGradientStopCollection(
        const D2D1_GRADIENT_STOP      *straightAlphaGradientStops,
        UINT32                        straightAlphaGradientStopsCount,
        D2D1_COLOR_SPACE              preInterpolationSpace,
        D2D1_COLOR_SPACE              postInterpolationSpace,
        D2D1_BUFFER_PRECISION         bufferPrecision,
        D2D1_EXTEND_MODE              extendMode,
        D2D1_COLOR_INTERPOLATION_MODE colorInterpolationMode,
  [out] ID2D1GradientStopCollection1  **gradientStopCollection1
);