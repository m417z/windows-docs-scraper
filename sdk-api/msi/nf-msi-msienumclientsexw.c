UINT MsiEnumClientsExW(
  [in]                LPCWSTR           szComponent,
  [in, optional]      LPCWSTR           szUserSid,
  [in]                DWORD             dwContext,
  [in]                DWORD             dwProductIndex,
  [out, optional]     WCHAR [39]        szProductBuf,
  [out, optional]     MSIINSTALLCONTEXT *pdwInstalledContext,
  [out, optional]     LPWSTR            szSid,
  [in, out, optional] LPDWORD           pcchSid
);