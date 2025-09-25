NTDSAPI DWORD DsListServersInSiteA(
  [in]  HANDLE           hDs,
  [in]  LPCSTR           site,
  [out] PDS_NAME_RESULTA *ppServers
);