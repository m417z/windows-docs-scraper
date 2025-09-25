HRESULT GetDeviceProperty(
  [in]      LPCWSTR pszPnPDeviceID,
  [in]      LPCWSTR pszDevicePropertyName,
  [in, out] BYTE    *pData,
  [in, out] DWORD   *pcbData,
  [in, out] DWORD   *pdwType
);