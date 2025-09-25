typedef struct _FLT_VOLUME_PROPERTIES {
  DEVICE_TYPE    DeviceType;
  ULONG          DeviceCharacteristics;
  ULONG          DeviceObjectFlags;
  ULONG          AlignmentRequirement;
  USHORT         SectorSize;
  USHORT         Flags;
  UNICODE_STRING FileSystemDriverName;
  UNICODE_STRING FileSystemDeviceName;
  UNICODE_STRING RealDeviceName;
} FLT_VOLUME_PROPERTIES, *PFLT_VOLUME_PROPERTIES;