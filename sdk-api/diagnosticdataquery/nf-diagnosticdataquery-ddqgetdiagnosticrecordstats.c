HRESULT DdqGetDiagnosticRecordStats(
  HDIAGNOSTIC_DATA_QUERY_SESSION        hSession,
  DIAGNOSTIC_DATA_SEARCH_CRITERIA const *searchCriteria,
  UINT32                                *recordCount,
  INT64                                 *minRowId,
  INT64                                 *maxRowId
);