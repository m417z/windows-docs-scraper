HRESULT RequestAddress(
  [in]  IMcastScope     *pScope,
  [in]  DATE            LeaseStartTime,
  [in]  DATE            LeaseStopTime,
  [in]  long            NumAddresses,
  [out] IMcastLeaseInfo **ppLeaseResponse
);