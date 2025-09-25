HRESULT ProcessLicenseRequest(
  [in]  BYTE  *pLicenseRequest,
  [in]  DWORD cbLicenseRequest,
  [out] BYTE  **ppLicenseResponse,
  [out] DWORD *pcbLicenseResponse,
  [out] BSTR  *pbstrKID
);