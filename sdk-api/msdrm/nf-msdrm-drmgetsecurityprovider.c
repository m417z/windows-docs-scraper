DRMEXPORT HRESULT UDAPICALL DRMGetSecurityProvider(
  [in]      UINT  uFlags,
  [in, out] UINT  *puTypeLen,
  [out]     PWSTR wszType,
  [in, out] UINT  *puPathLen,
  [out]     PWSTR wszPath
);