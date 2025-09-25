UINT MsiSourceListEnumMediaDisksW(
  [in]                LPCWSTR           szProductCodeOrPatchCode,
  [in, optional]      LPCWSTR           szUserSid,
  [in]                MSIINSTALLCONTEXT dwContext,
  [in]                DWORD             dwOptions,
  [in]                DWORD             dwIndex,
  [out, optional]     LPDWORD           pdwDiskId,
  [out, optional]     LPWSTR            szVolumeLabel,
  [in, out, optional] LPDWORD           pcchVolumeLabel,
  [out, optional]     LPWSTR            szDiskPrompt,
  [in, out, optional] LPDWORD           pcchDiskPrompt
);