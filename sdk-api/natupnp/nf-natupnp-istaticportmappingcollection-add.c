HRESULT Add(
  [in]  long               lExternalPort,
  [in]  BSTR               bstrProtocol,
  [in]  long               lInternalPort,
  [in]  BSTR               bstrInternalClient,
  [in]  VARIANT_BOOL       bEnabled,
  [in]  BSTR               bstrDescription,
  [out] IStaticPortMapping **ppSPM
);