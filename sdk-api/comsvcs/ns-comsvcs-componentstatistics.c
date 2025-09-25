typedef struct _ComponentStatistics {
  ULONG NumInstances;
  ULONG NumBoundReferences;
  ULONG NumPooledObjects;
  ULONG NumObjectsInCall;
  ULONG AvgResponseTimeInMs;
  ULONG NumCallsCompletedRecent;
  ULONG NumCallsFailedRecent;
  ULONG NumCallsCompletedTotal;
  ULONG NumCallsFailedTotal;
  ULONG Reserved1;
  ULONG Reserved2;
  ULONG Reserved3;
  ULONG Reserved4;
} ComponentStatistics;