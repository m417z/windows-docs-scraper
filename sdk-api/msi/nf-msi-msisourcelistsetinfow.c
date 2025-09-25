UINT MsiSourceListSetInfoW(
  [in]           LPCWSTR           szProductCodeOrPatchCode,
  [in, optional] LPCWSTR           szUserSid,
  [in]           MSIINSTALLCONTEXT dwContext,
  [in]           DWORD             dwOptions,
  [in]           LPCWSTR           szProperty,
  [in]           LPCWSTR           szValue
);