BOOL CertStrToNameA(
  [in]            DWORD  dwCertEncodingType,
  [in]            LPCSTR pszX500,
  [in]            DWORD  dwStrType,
  [in, optional]  void   *pvReserved,
  [out]           BYTE   *pbEncoded,
  [in, out]       DWORD  *pcbEncoded,
  [out, optional] LPCSTR *ppszError
);