UINT MsiEnumClientsExA(
  [in]                LPCSTR            szComponent,
  [in, optional]      LPCSTR            szUserSid,
  [in]                DWORD             dwContext,
  [in]                DWORD             dwProductIndex,
  [out, optional]     CHAR [39]         szProductBuf,
  [out, optional]     MSIINSTALLCONTEXT *pdwInstalledContext,
  [out, optional]     LPSTR             szSid,
  [in, out, optional] LPDWORD           pcchSid
);