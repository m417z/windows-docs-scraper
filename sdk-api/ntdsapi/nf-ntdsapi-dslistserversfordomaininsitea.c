NTDSAPI DWORD DsListServersForDomainInSiteA(
  [in]  HANDLE           hDs,
  [in]  LPCSTR           domain,
  [in]  LPCSTR           site,
  [out] PDS_NAME_RESULTA *ppServers
);