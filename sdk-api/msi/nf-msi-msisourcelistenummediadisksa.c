UINT MsiSourceListEnumMediaDisksA(
  [in]                LPCSTR            szProductCodeOrPatchCode,
  [in, optional]      LPCSTR            szUserSid,
  [in]                MSIINSTALLCONTEXT dwContext,
  [in]                DWORD             dwOptions,
  [in]                DWORD             dwIndex,
  [out, optional]     LPDWORD           pdwDiskId,
  [out, optional]     LPSTR             szVolumeLabel,
  [in, out, optional] LPDWORD           pcchVolumeLabel,
  [out, optional]     LPSTR             szDiskPrompt,
  [in, out, optional] LPDWORD           pcchDiskPrompt
);