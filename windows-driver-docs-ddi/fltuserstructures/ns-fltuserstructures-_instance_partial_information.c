typedef struct _INSTANCE_PARTIAL_INFORMATION {
  ULONG  NextEntryOffset;
  USHORT InstanceNameLength;
  USHORT InstanceNameBufferOffset;
  USHORT AltitudeLength;
  USHORT AltitudeBufferOffset;
} INSTANCE_PARTIAL_INFORMATION, *PINSTANCE_PARTIAL_INFORMATION;