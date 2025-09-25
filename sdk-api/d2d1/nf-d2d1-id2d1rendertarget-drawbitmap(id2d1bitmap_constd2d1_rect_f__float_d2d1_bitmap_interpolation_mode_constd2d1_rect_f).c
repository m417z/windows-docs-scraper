void DrawBitmap(
  [in]           ID2D1Bitmap                    *bitmap,
  [ref]          const D2D1_RECT_F &            destinationRectangle,
                 FLOAT                          opacity,
                 D2D1_BITMAP_INTERPOLATION_MODE interpolationMode,
  [in, optional] const D2D1_RECT_F              *sourceRectangle
);