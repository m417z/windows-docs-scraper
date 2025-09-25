typedef struct {
  ULONG  ByteCount;
  USHORT MajorVersion;
  USHORT MinorVersion;
  ULONG  BytesPerPhysicalSector;
  USHORT LfsMajorVersion;
  USHORT LfsMinorVersion;
  ULONG  MaxDeviceTrimExtentCount;
  ULONG  MaxDeviceTrimByteCount;
  ULONG  MaxVolumeTrimExtentCount;
  ULONG  MaxVolumeTrimByteCount;
} NTFS_EXTENDED_VOLUME_DATA, *PNTFS_EXTENDED_VOLUME_DATA;