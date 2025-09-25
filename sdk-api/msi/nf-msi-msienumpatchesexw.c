UINT MsiEnumPatchesExW(
  [in, optional]      LPCWSTR           szProductCode,
  [in, optional]      LPCWSTR           szUserSid,
  [in]                DWORD             dwContext,
  [in]                DWORD             dwFilter,
  [in]                DWORD             dwIndex,
  [out, optional]     WCHAR [39]        szPatchCode,
  [out, optional]     WCHAR [39]        szTargetProductCode,
  [out, optional]     MSIINSTALLCONTEXT *pdwTargetProductContext,
  [out, optional]     LPWSTR            szTargetUserSid,
  [in, out, optional] LPDWORD           pcchTargetUserSid
);