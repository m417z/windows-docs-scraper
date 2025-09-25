typedef struct _FILE_REGION_INFO {
  LONGLONG FileOffset;
  LONGLONG Length;
  ULONG    Usage;
  ULONG    Reserved;
} FILE_REGION_INFO, *PFILE_REGION_INFO;