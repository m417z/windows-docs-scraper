BOOL CertStrToNameW(
  [in]            DWORD   dwCertEncodingType,
  [in]            LPCWSTR pszX500,
  [in]            DWORD   dwStrType,
  [in, optional]  void    *pvReserved,
  [out]           BYTE    *pbEncoded,
  [in, out]       DWORD   *pcbEncoded,
  [out, optional] LPCWSTR *ppszError
);