NTDSAPI DWORD DsListDomainsInSiteW(
  [in]  HANDLE           hDs,
  [in]  LPCWSTR          site,
  [out] PDS_NAME_RESULTW *ppDomains
);