UINT MsiSourceListSetInfoA(
  [in]           LPCSTR            szProductCodeOrPatchCode,
  [in, optional] LPCSTR            szUserSid,
  [in]           MSIINSTALLCONTEXT dwContext,
  [in]           DWORD             dwOptions,
  [in]           LPCSTR            szProperty,
  [in]           LPCSTR            szValue
);