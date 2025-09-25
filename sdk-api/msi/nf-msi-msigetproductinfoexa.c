UINT MsiGetProductInfoExA(
  [in]                LPCSTR            szProductCode,
  [in]                LPCSTR            szUserSid,
  [in]                MSIINSTALLCONTEXT dwContext,
  [in]                LPCSTR            szProperty,
  [out, optional]     LPSTR             szValue,
  [in, out, optional] LPDWORD           pcchValue
);