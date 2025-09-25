typedef struct _FILTER_AGGREGATE_STANDARD_INFORMATION {
  ULONG NextEntryOffset;
  ULONG Flags;
  union {
    struct {
      ULONG  Flags;
      ULONG  FrameID;
      ULONG  NumberOfInstances;
      USHORT FilterNameLength;
      USHORT FilterNameBufferOffset;
      USHORT FilterAltitudeLength;
      USHORT FilterAltitudeBufferOffset;
    } MiniFilter;
    struct {
      ULONG  Flags;
      USHORT FilterNameLength;
      USHORT FilterNameBufferOffset;
      USHORT FilterAltitudeLength;
      USHORT FilterAltitudeBufferOffset;
    } LegacyFilter;
  } Type;
} FILTER_AGGREGATE_STANDARD_INFORMATION, *PFILTER_AGGREGATE_STANDARD_INFORMATION;