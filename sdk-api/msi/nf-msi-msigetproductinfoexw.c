UINT MsiGetProductInfoExW(
  [in]                LPCWSTR           szProductCode,
  [in]                LPCWSTR           szUserSid,
  [in]                MSIINSTALLCONTEXT dwContext,
  [in]                LPCWSTR           szProperty,
  [out, optional]     LPWSTR            szValue,
  [in, out, optional] LPDWORD           pcchValue
);