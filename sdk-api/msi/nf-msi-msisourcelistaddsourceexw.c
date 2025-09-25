UINT MsiSourceListAddSourceExW(
  [in]           LPCWSTR           szProductCodeOrPatchCode,
  [in, optional] LPCWSTR           szUserSid,
  [in]           MSIINSTALLCONTEXT dwContext,
  [in]           DWORD             dwOptions,
  [in]           LPCWSTR           szSource,
  [in, optional] DWORD             dwIndex
);