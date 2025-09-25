typedef struct D2D1_BITMAP_PROPERTIES1 {
  D2D1_PIXEL_FORMAT   pixelFormat;
  FLOAT               dpiX;
  FLOAT               dpiY;
  D2D1_BITMAP_OPTIONS bitmapOptions;
  ID2D1ColorContext   *colorContext;
} D2D1_BITMAP_PROPERTIES1;