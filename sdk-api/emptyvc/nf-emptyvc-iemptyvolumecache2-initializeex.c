HRESULT InitializeEx(
  [in]      HKEY    hkRegKey,
  [in]      LPCWSTR pcwszVolume,
  [in]      LPCWSTR pcwszKeyName,
  [out]     LPWSTR  *ppwszDisplayName,
  [out]     LPWSTR  *ppwszDescription,
  [out]     LPWSTR  *ppwszBtnText,
  [in, out] DWORD   *pdwFlags
);