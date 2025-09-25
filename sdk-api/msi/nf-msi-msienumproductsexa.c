UINT MsiEnumProductsExA(
  [in, optional]      LPCSTR            szProductCode,
  [in]                LPCSTR            szUserSid,
  [in]                DWORD             dwContext,
  [in]                DWORD             dwIndex,
  [out, optional]     CHAR [39]         szInstalledProductCode,
  [out, optional]     MSIINSTALLCONTEXT *pdwInstalledContext,
  [out, optional]     LPSTR             szSid,
  [in, out, optional] LPDWORD           pcchSid
);