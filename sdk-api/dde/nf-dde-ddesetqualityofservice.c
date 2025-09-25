BOOL DdeSetQualityOfService(
  [in]  HWND                              hwndClient,
  [in]  const SECURITY_QUALITY_OF_SERVICE *pqosNew,
  [out] PSECURITY_QUALITY_OF_SERVICE      pqosPrev
);