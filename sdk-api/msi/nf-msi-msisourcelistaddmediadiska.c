UINT MsiSourceListAddMediaDiskA(
  [in]           LPCSTR            szProductCodeOrPatchCode,
  [in, optional] LPCSTR            szUserSid,
  [in]           MSIINSTALLCONTEXT dwContext,
  [in]           DWORD             dwOptions,
  [in]           DWORD             dwDiskId,
  [in]           LPCSTR            szVolumeLabel,
  [in, optional] LPCSTR            szDiskPrompt
);