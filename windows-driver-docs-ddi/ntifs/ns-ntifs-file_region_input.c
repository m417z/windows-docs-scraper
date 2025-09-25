typedef struct _FILE_REGION_INPUT {
  LONGLONG FileOffset;
  LONGLONG Length;
  ULONG    DesiredUsage;
} FILE_REGION_INPUT, *PFILE_REGION_INPUT;