HRESULT DdqGetDiagnosticRecordPage(
  HDIAGNOSTIC_DATA_QUERY_SESSION          hSession,
  DIAGNOSTIC_DATA_SEARCH_CRITERIA * const searchCriteria,
  UINT32                                  offset,
  UINT32                                  pageRecordCount,
  INT64                                   baseRowId,
  HDIAGNOSTIC_RECORD                      *hRecord
);