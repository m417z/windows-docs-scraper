HRESULT CreateBitmapBrush(
  [in]           ID2D1Bitmap                           *bitmap,
  [in, optional] const D2D1_BITMAP_BRUSH_PROPERTIES1 & bitmapBrushProperties,
  [in, optional] const D2D1_BRUSH_PROPERTIES &         brushProperties,
  [out]          ID2D1BitmapBrush1                     **bitmapBrush
);