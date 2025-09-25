typedef struct _REFS_QUERY_VOLUME_IO_METRICS_INFO_OUTPUT_BUFFER {
  ULONG                                        Version;
  REFS_QUERY_VOLUME_IO_METRICS_INFO_QUERY_TYPE QueryType;
  ULONG                                        Reserved[6];
  union {
    ULONGLONG UnusedAlign;
    struct {
      ULONG GlobalSecondsToTrack;
      ULONG MetricsPeriodicitySeconds;
      ULONG MetricsGenerationsPerContainer;
      ULONG Reserved[6];
    } Parameters;
    struct {
      ULONG                                     EntryCount;
      ULONGLONG                                 ResumeKeyBlob[2];
      ULONG                                     Reserved[6];
      REFS_QUERY_VOLUME_IO_METRICS_METRICS_DATA Metrics[ANYSIZE_ARRAY];
    } MetricsData;
  };
} REFS_QUERY_VOLUME_IO_METRICS_INFO_OUTPUT_BUFFER, *PREFS_QUERY_VOLUME_IO_METRICS_INFO_OUTPUT_BUFFER;