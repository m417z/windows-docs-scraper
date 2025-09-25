void DrawBitmap(
  [in]           ID2D1Bitmap             *bitmap,
  [in, optional] const D2D1_RECT_F &     destinationRectangle,
                 FLOAT                   opacity,
                 D2D1_INTERPOLATION_MODE interpolationMode,
  [in, optional] const D2D1_RECT_F       *sourceRectangle,
  [in, optional] const D2D1_MATRIX_4X4_F *perspectiveTransform
);