HRESULT QueryBand(
  [in]            DWORD     dwBandID,
  [out, optional] IDeskBand **ppstb,
  [out, optional] DWORD     *pdwState,
  [out]           LPWSTR    pszName,
  [in]            int       cchName
);