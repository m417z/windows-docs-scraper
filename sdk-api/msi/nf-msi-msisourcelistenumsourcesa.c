UINT MsiSourceListEnumSourcesA(
  [in]                LPCSTR            szProductCodeOrPatchCode,
  [in, optional]      LPCSTR            szUserSid,
  [in]                MSIINSTALLCONTEXT dwContext,
  [in]                DWORD             dwOptions,
  [in]                DWORD             dwIndex,
  [in, optional]      LPSTR             szSource,
  [in, out, optional] LPDWORD           pcchSource
);