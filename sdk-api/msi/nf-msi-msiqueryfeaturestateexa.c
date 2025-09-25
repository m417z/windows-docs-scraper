UINT MsiQueryFeatureStateExA(
  [in]            LPCSTR            szProductCode,
  [in]            LPCSTR            szUserSid,
  [in]            MSIINSTALLCONTEXT dwContext,
  [in]            LPCSTR            szFeature,
  [out, optional] INSTALLSTATE      *pdwState
);