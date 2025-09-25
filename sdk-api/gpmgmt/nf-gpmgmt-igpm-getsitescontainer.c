HRESULT GetSitesContainer(
  [in]  BSTR               bstrForest,
  [in]  BSTR               bstrDomain,
  [in]  BSTR               bstrDomainController,
  [in]  long               lDCFlags,
  [out] IGPMSitesContainer **ppIGPMSitesContainer
);