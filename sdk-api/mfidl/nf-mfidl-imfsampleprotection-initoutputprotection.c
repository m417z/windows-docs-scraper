HRESULT InitOutputProtection(
  [in]  DWORD dwVersion,
  [in]  DWORD dwOutputId,
  [in]  BYTE  *pbCert,
  [in]  DWORD cbCert,
  [out] BYTE  **ppbSeed,
  [out] DWORD *pcbSeed
);