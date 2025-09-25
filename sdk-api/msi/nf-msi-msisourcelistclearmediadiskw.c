UINT MsiSourceListClearMediaDiskW(
  [in]           LPCWSTR           szProductCodeOrPatchCode,
  [in, optional] LPCWSTR           szUserSid,
  [in]           MSIINSTALLCONTEXT dwContext,
  [in]           DWORD             dwOptions,
  [in]           DWORD             dwDiskId
);