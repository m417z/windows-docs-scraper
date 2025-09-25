BOOL InternetEnumPerSiteCookieDecisionW(
  [out]     LPWSTR        pszSiteName,
  [in, out] unsigned long *pcSiteNameSize,
  [out]     unsigned long *pdwDecision,
  [in]      unsigned long dwIndex
);