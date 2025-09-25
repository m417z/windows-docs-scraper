UINT MsiEnumComponentsExA(
  [in, optional]  LPCSTR            szUserSid,
  [in]            DWORD             dwContext,
  [in]            DWORD             dwIndex,
  [out, optional] CHAR [39]         szInstalledComponentCode,
  [out, optional] MSIINSTALLCONTEXT *pdwInstalledContext,
  [out, optional] LPSTR             szSid,
  [in, out]       LPDWORD           pcchSid
);