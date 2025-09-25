HRESULT CreateBitmapFromDxgiSurface(
  [in]           IDXGISurface                    *surface,
  [in, optional] const D2D1_BITMAP_PROPERTIES1 & bitmapProperties,
  [out]          ID2D1Bitmap1                    **bitmap
);