NTDSAPI_POSTXP DWORD DsQuerySitesByCostW(
  [in]  HANDLE             hDS,
  [in]  LPWSTR             pwszFromSite,
  [in]  LPWSTR             *rgwszToSites,
  [in]  DWORD              cToSites,
  [in]  DWORD              dwFlags,
  [out] PDS_SITE_COST_INFO *prgSiteInfo
);