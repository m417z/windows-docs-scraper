typedef struct WICImageParameters {
  D2D1_PIXEL_FORMAT PixelFormat;
  FLOAT             DpiX;
  FLOAT             DpiY;
  FLOAT             Top;
  FLOAT             Left;
  UINT32            PixelWidth;
  UINT32            PixelHeight;
} WICImageParameters;