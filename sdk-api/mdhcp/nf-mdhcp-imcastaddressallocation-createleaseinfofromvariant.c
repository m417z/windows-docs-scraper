HRESULT CreateLeaseInfoFromVariant(
  [in]  DATE            LeaseStartTime,
  [in]  DATE            LeaseStopTime,
  [in]  VARIANT         vAddresses,
  [in]  BSTR            pRequestID,
  [in]  BSTR            pServerAddress,
  [out] IMcastLeaseInfo **ppReleaseRequest
);