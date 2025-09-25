HRESULT GetDeviceServices(
  [in]      LPCWSTR pszPnPDeviceID,
  [in]      REFGUID guidServiceCategory,
  [in, out] LPWSTR  *pServices,
  [in, out] DWORD   *pcServices
);