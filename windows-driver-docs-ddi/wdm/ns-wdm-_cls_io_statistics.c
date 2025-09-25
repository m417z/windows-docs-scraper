typedef struct _CLS_IO_STATISTICS {
  CLS_IO_STATISTICS_HEADER hdrIoStats;
  ULONGLONG                cFlush;
  ULONGLONG                cbFlush;
  ULONGLONG                cMetaFlush;
  ULONGLONG                cbMetaFlush;
} CLS_IO_STATISTICS, *PCLS_IO_STATISTICS, PPCLS_IO_STATISTICS;