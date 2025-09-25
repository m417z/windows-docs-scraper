UINT MsiQueryComponentStateW(
  [in]  LPCWSTR           szProductCode,
  [in]  LPCWSTR           szUserSid,
  [in]  MSIINSTALLCONTEXT dwContext,
  [in]  LPCWSTR           szComponentCode,
  [out] INSTALLSTATE      *pdwState
);