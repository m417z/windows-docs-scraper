typedef struct _INSTANCE_FULL_INFORMATION {
  ULONG  NextEntryOffset;
  USHORT InstanceNameLength;
  USHORT InstanceNameBufferOffset;
  USHORT AltitudeLength;
  USHORT AltitudeBufferOffset;
  USHORT VolumeNameLength;
  USHORT VolumeNameBufferOffset;
  USHORT FilterNameLength;
  USHORT FilterNameBufferOffset;
} INSTANCE_FULL_INFORMATION, *PINSTANCE_FULL_INFORMATION;