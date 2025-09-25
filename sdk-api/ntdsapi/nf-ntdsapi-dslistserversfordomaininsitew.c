NTDSAPI DWORD DsListServersForDomainInSiteW(
  [in]  HANDLE           hDs,
  [in]  LPCWSTR          domain,
  [in]  LPCWSTR          site,
  [out] PDS_NAME_RESULTW *ppServers
);