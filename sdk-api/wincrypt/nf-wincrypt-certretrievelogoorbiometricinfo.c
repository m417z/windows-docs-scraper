BOOL CertRetrieveLogoOrBiometricInfo(
  [in]  PCCERT_CONTEXT pCertContext,
  [in]  LPCSTR         lpszLogoOrBiometricType,
  [in]  DWORD          dwRetrievalFlags,
  [in]  DWORD          dwTimeout,
  [in]  DWORD          dwFlags,
        void           *pvReserved,
  [out] BYTE           **ppbData,
  [out] DWORD          *pcbData,
  [out] LPWSTR         *ppwszMimeType
);