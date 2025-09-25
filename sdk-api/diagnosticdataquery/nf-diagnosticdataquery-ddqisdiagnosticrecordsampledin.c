HRESULT DdqIsDiagnosticRecordSampledIn(
  HDIAGNOSTIC_DATA_QUERY_SESSION hSession,
  const GUID                     *providerGroup,
  const GUID                     *providerId,
  PCWSTR                         providerName,
  const UINT32                   *eventId,
  PCWSTR                         eventName,
  const UINT32                   *eventVersion,
  const UINT64                   *eventKeywords,
  BOOL                           *isSampledIn
);