BOOL CryptVerifyCertificateSignatureEx(
  [in]                HCRYPTPROV_LEGACY hCryptProv,
  [in]                DWORD             dwCertEncodingType,
  [in]                DWORD             dwSubjectType,
  [in]                void              *pvSubject,
  [in]                DWORD             dwIssuerType,
  [in]                void              *pvIssuer,
  [in]                DWORD             dwFlags,
  [in, out, optional] void              *pvExtra
);