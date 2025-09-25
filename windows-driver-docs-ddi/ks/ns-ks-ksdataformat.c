typedef struct {
  ULONG FormatSize;
  ULONG Flags;
  ULONG SampleSize;
  ULONG Reserved;
  GUID  MajorFormat;
  GUID  SubFormat;
  GUID  Specifier;
} KSDATAFORMAT, *PKSDATAFORMAT, KSDATARANGE, *PKSDATARANGE;