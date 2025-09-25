NTDSAPI DWORD DsListDomainsInSiteA(
  [in]  HANDLE           hDs,
  [in]  LPCSTR           site,
  [out] PDS_NAME_RESULTA *ppDomains
);