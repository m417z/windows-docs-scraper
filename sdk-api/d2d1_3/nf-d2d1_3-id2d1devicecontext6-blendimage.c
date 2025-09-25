void BlendImage(
  [in]           ID2D1Image              *image,
                 D2D1_BLEND_MODE         blendMode,
  [in, optional] const D2D1_POINT_2F     *targetOffset,
  [in, optional] const D2D1_RECT_F       *imageRectangle,
                 D2D1_INTERPOLATION_MODE interpolationMode
);