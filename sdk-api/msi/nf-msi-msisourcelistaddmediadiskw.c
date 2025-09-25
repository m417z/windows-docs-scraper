UINT MsiSourceListAddMediaDiskW(
  [in]           LPCWSTR           szProductCodeOrPatchCode,
  [in, optional] LPCWSTR           szUserSid,
  [in]           MSIINSTALLCONTEXT dwContext,
  [in]           DWORD             dwOptions,
  [in]           DWORD             dwDiskId,
  [in]           LPCWSTR           szVolumeLabel,
  [in, optional] LPCWSTR           szDiskPrompt
);