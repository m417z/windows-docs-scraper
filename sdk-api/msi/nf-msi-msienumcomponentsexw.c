UINT MsiEnumComponentsExW(
  [in, optional]  LPCWSTR           szUserSid,
  [in]            DWORD             dwContext,
  [in]            DWORD             dwIndex,
  [out, optional] WCHAR [39]        szInstalledComponentCode,
  [out, optional] MSIINSTALLCONTEXT *pdwInstalledContext,
  [out, optional] LPWSTR            szSid,
  [in, out]       LPDWORD           pcchSid
);