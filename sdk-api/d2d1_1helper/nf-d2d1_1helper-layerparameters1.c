D2D1_LAYER_PARAMETERS1 LayerParameters1(
  [in, ref]      const D2D1_RECT_F & contentBounds,
  [in, optional] ID2D1Geometry       *geometricMask,
                 D2D1_ANTIALIAS_MODE maskAntialiasMode,
                 D2D1_MATRIX_3X2_F   maskTransform,
                 FLOAT               opacity,
  [in, optional] ID2D1Brush          *opacityBrush,
                 D2D1_LAYER_OPTIONS1 layerOptions
);