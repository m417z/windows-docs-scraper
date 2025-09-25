BOOL InternetEnumPerSiteCookieDecisionA(
  [out]     LPSTR         pszSiteName,
  [in, out] unsigned long *pcSiteNameSize,
  [out]     unsigned long *pdwDecision,
  [in]      unsigned long dwIndex
);