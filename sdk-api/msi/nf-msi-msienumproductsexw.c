UINT MsiEnumProductsExW(
  [in, optional]      LPCWSTR           szProductCode,
  [in]                LPCWSTR           szUserSid,
  [in]                DWORD             dwContext,
  [in]                DWORD             dwIndex,
  [out, optional]     WCHAR [39]        szInstalledProductCode,
  [out, optional]     MSIINSTALLCONTEXT *pdwInstalledContext,
  [out, optional]     LPWSTR            szSid,
  [in, out, optional] LPDWORD           pcchSid
);