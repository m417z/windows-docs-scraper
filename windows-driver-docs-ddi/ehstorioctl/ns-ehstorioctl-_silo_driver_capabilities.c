typedef struct _SILO_DRIVER_CAPABILITIES {
  ULONG StructSize;
  ULONG Capabilities;
  ULONG MaxLbaFilterCount;
  ULONG RedirectedIoctlListCount;
  ULONG RedirectedIoctlListOffset;
} SILO_DRIVER_CAPABILITIES, *PSILO_DRIVER_CAPABILITIES;