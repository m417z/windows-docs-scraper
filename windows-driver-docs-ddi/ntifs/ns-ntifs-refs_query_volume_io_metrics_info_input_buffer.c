typedef struct _REFS_QUERY_VOLUME_IO_METRICS_INFO_INPUT_BUFFER {
  ULONG                                        Version;
  REFS_QUERY_VOLUME_IO_METRICS_INFO_QUERY_TYPE QueryType;
  ULONG                                        Reserved[6];
  union {
    ULONGLONG UnusedAlign;
    struct {
      ULONG Reserved[6];
    } Parameters;
    struct {
      ULONGLONG ResumeKeyBlob[2];
      ULONG     Reserved[6];
    } MetricsData;
  };
} REFS_QUERY_VOLUME_IO_METRICS_INFO_INPUT_BUFFER, *PREFS_QUERY_VOLUME_IO_METRICS_INFO_INPUT_BUFFER;