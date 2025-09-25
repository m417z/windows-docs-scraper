typedef struct {
  DWORD ByteCount;
  WORD  MajorVersion;
  WORD  MinorVersion;
  DWORD BytesPerPhysicalSector;
  WORD  LfsMajorVersion;
  WORD  LfsMinorVersion;
  DWORD MaxDeviceTrimExtentCount;
  DWORD MaxDeviceTrimByteCount;
  DWORD MaxVolumeTrimExtentCount;
  DWORD MaxVolumeTrimByteCount;
} NTFS_EXTENDED_VOLUME_DATA, *PNTFS_EXTENDED_VOLUME_DATA;