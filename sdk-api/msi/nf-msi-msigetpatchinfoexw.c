UINT MsiGetPatchInfoExW(
  [in]            LPCWSTR           szPatchCode,
  [in]            LPCWSTR           szProductCode,
  [in]            LPCWSTR           szUserSid,
  [in]            MSIINSTALLCONTEXT dwContext,
  [in]            LPCWSTR           szProperty,
  [out, optional] LPWSTR            lpValue,
  [in, out]       LPDWORD           pcchValue
);