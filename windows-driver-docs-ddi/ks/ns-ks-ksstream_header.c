typedef struct {
  ULONG    Size;
  ULONG    TypeSpecificFlags;
  KSTIME   PresentationTime;
  LONGLONG Duration;
  ULONG    FrameExtent;
  ULONG    DataUsed;
  PVOID    Data;
  ULONG    OptionsFlags;
  ULONG    Reserved;
} KSSTREAM_HEADER, *PKSSTREAM_HEADER;