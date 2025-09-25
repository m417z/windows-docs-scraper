typedef struct WICBitmapPattern {
  ULARGE_INTEGER Position;
  ULONG          Length;
  BYTE           *Pattern;
  BYTE           *Mask;
  BOOL           EndOfStream;
} WICBitmapPattern;