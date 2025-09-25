typedef struct _CLS_IO_STATISTICS_HEADER {
  UCHAR              ubMajorVersion;
  UCHAR              ubMinorVersion;
  CLFS_IOSTATS_CLASS eStatsClass;
  USHORT             cbLength;
  ULONG              coffData;
} CLS_IO_STATISTICS_HEADER, *PCLS_IO_STATISTICS_HEADER, PPCLS_IO_STATISTICS_HEADER;