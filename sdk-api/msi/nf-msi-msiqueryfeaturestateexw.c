UINT MsiQueryFeatureStateExW(
  [in]            LPCWSTR           szProductCode,
  [in]            LPCWSTR           szUserSid,
  [in]            MSIINSTALLCONTEXT dwContext,
  [in]            LPCWSTR           szFeature,
  [out, optional] INSTALLSTATE      *pdwState
);