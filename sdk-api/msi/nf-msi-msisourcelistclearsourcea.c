UINT MsiSourceListClearSourceA(
  [in]           LPCSTR            szProductCodeOrPatchCode,
  [in, optional] LPCSTR            szUserSid,
  [in]           MSIINSTALLCONTEXT dwContext,
  [in]           DWORD             dwOptions,
  [in]           LPCSTR            szSource
);