typedef struct WICBitmapPlane {
  WICPixelFormatGUID Format;
  BYTE               *pbBuffer;
  UINT               cbStride;
  UINT               cbBufferSize;
} WICBitmapPlane;