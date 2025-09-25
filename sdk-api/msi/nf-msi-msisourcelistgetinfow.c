UINT MsiSourceListGetInfoW(
  [in]                LPCWSTR           szProductCodeOrPatchCode,
  [in, optional]      LPCWSTR           szUserSid,
  [in]                MSIINSTALLCONTEXT dwContext,
  [in]                DWORD             dwOptions,
  [in]                LPCWSTR           szProperty,
  [out, optional]     LPWSTR            szValue,
  [in, out, optional] LPDWORD           pcchValue
);