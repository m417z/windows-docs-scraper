NTDSAPI DWORD DsListServersInSiteW(
  [in]  HANDLE           hDs,
  [in]  LPCWSTR          site,
  [out] PDS_NAME_RESULTW *ppServers
);