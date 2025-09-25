HRESULT CreateBitmap(
                 D2D1_SIZE_U                   size,
  [in, optional] const void                    *sourceData,
                 UINT32                        pitch,
  [in, ref]      const D2D1_BITMAP_PROPERTIES1 *bitmapProperties,
  [out]          ID2D1Bitmap1                  **bitmap
);