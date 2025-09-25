HRESULT Initialize(
  [in]      HKEY    hkRegKey,
  [in]      LPCWSTR pcwszVolume,
  [out]     LPWSTR  *ppwszDisplayName,
  [out]     LPWSTR  *ppwszDescription,
  [in, out] DWORD   *pdwFlags
);