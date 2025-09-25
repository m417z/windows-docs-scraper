UINT MsiQueryComponentStateA(
  [in]  LPCSTR            szProductCode,
  [in]  LPCSTR            szUserSid,
  [in]  MSIINSTALLCONTEXT dwContext,
  [in]  LPCSTR            szComponentCode,
  [out] INSTALLSTATE      *pdwState
);