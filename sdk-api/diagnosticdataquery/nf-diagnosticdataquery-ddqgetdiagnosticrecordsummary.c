HRESULT DdqGetDiagnosticRecordSummary(
  HDIAGNOSTIC_DATA_QUERY_SESSION hSession,
  const PCWSTR                   *producerNames,
  UINT32                         producerNameCount,
  DIAGNOSTIC_DATA_GENERAL_STATS  *generalStats
);