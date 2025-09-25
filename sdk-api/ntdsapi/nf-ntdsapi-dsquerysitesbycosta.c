NTDSAPI_POSTXP DWORD DsQuerySitesByCostA(
  [in]  HANDLE             hDS,
        LPSTR              pszFromSite,
        LPSTR              *rgszToSites,
  [in]  DWORD              cToSites,
  [in]  DWORD              dwFlags,
  [out] PDS_SITE_COST_INFO *prgSiteInfo
);