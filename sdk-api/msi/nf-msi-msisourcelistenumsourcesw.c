UINT MsiSourceListEnumSourcesW(
  [in]                LPCWSTR           szProductCodeOrPatchCode,
  [in, optional]      LPCWSTR           szUserSid,
  [in]                MSIINSTALLCONTEXT dwContext,
  [in]                DWORD             dwOptions,
  [in]                DWORD             dwIndex,
  [in, optional]      LPWSTR            szSource,
  [in, out, optional] LPDWORD           pcchSource
);