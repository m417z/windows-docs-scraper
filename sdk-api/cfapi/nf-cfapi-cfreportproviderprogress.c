HRESULT CfReportProviderProgress(
  [in] CF_CONNECTION_KEY ConnectionKey,
  [in] CF_TRANSFER_KEY   TransferKey,
  [in] LARGE_INTEGER     ProviderProgressTotal,
  [in] LARGE_INTEGER     ProviderProgressCompleted
);