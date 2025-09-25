HRESULT CreateLeaseInfo(
  [in]  DATE            LeaseStartTime,
  [in]  DATE            LeaseStopTime,
  [in]  DWORD           dwNumAddresses,
  [in]  LPWSTR          *ppAddresses,
  [in]  LPWSTR          pRequestID,
  [in]  LPWSTR          pServerAddress,
  [out] IMcastLeaseInfo **ppReleaseRequest
);