HRESULT DdqGetDiagnosticRecordTagDistribution(
  HDIAGNOSTIC_DATA_QUERY_SESSION  hSession,
  PCWSTR                          *producerNames,
  UINT32                          producerNameCount,
  DIAGNOSTIC_DATA_EVENT_TAG_STATS **tagStats,
  UINT32                          *statCount
);