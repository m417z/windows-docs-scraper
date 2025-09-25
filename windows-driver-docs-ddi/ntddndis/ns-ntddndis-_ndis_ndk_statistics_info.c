typedef struct _NDIS_NDK_STATISTICS_INFO {
  NDIS_OBJECT_HEADER            Header;
  ULONG                         Flags;
  NDIS_NDK_PERFORMANCE_COUNTERS CounterSet;
} NDIS_NDK_STATISTICS_INFO;