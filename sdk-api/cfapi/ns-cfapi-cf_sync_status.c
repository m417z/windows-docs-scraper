typedef struct CF_SYNC_STATUS {
  ULONG StructSize;
  ULONG Code;
  ULONG DescriptionOffset;
  ULONG DescriptionLength;
  ULONG DeviceIdOffset;
  ULONG DeviceIdLength;
} CF_SYNC_STATUS;