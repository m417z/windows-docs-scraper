typedef struct WICMetadataPattern {
  ULARGE_INTEGER Position;
  ULONG          Length;
  BYTE           *Pattern;
  BYTE           *Mask;
  ULARGE_INTEGER DataOffset;
} WICMetadataPattern;