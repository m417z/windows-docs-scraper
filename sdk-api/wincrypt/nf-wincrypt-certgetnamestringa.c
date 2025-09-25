DWORD CertGetNameStringA(
  [in]  PCCERT_CONTEXT pCertContext,
  [in]  DWORD          dwType,
  [in]  DWORD          dwFlags,
  [in]  void           *pvTypePara,
  [out] LPSTR          pszNameString,
  [in]  DWORD          cchNameString
);