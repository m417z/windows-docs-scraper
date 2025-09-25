typedef union {
  struct {
    ULONG FormatSize;
    ULONG Flags;
    ULONG SampleSize;
    ULONG Reserved;
    GUID  MajorFormat;
    GUID  SubFormat;
    GUID  Specifier;
  };
  LONGLONG Alignment;
} KSDATAFORMAT, *PKSDATAFORMAT, KSDATARANGE, *PKSDATARANGE;