typedef struct D2D1_LAYER_PARAMETERS1 {
  D2D1_RECT_F         contentBounds;
  ID2D1Geometry       *geometricMask;
  D2D1_ANTIALIAS_MODE maskAntialiasMode;
  D2D1_MATRIX_3X2_F   maskTransform;
  FLOAT               opacity;
  ID2D1Brush          *opacityBrush;
  D2D1_LAYER_OPTIONS1 layerOptions;
} D2D1_LAYER_PARAMETERS1;