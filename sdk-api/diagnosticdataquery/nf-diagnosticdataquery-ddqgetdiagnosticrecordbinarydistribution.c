HRESULT DdqGetDiagnosticRecordBinaryDistribution(
  HDIAGNOSTIC_DATA_QUERY_SESSION     hSession,
  PCWSTR                             *producerNames,
  UINT32                             producerNameCount,
  UINT32                             topNBinaries,
  DIAGNOSTIC_DATA_EVENT_BINARY_STATS **binaryStats,
  UINT32                             *statCount
);