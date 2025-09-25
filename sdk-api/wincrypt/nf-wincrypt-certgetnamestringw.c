DWORD CertGetNameStringW(
  [in]  PCCERT_CONTEXT pCertContext,
  [in]  DWORD          dwType,
  [in]  DWORD          dwFlags,
  [in]  void           *pvTypePara,
  [out] LPWSTR         pszNameString,
  [in]  DWORD          cchNameString
);