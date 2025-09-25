HRESULT CfReportProviderProgress2(
  CF_CONNECTION_KEY ConnectionKey,
  CF_TRANSFER_KEY   TransferKey,
  CF_REQUEST_KEY    RequestKey,
  LARGE_INTEGER     ProviderProgressTotal,
  LARGE_INTEGER     ProviderProgressCompleted,
  DWORD             TargetSessionId
);