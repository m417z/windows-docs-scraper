typedef struct WICMetadataHeader {
  ULARGE_INTEGER Position;
  ULONG          Length;
  BYTE           *Header;
  ULARGE_INTEGER DataOffset;
} WICMetadataHeader;