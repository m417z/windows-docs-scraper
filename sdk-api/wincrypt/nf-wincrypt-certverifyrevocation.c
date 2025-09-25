BOOL CertVerifyRevocation(
  [in]           DWORD                   dwEncodingType,
  [in]           DWORD                   dwRevType,
  [in]           DWORD                   cContext,
  [in]           PVOID []                rgpvContext,
  [in]           DWORD                   dwFlags,
  [in, optional] PCERT_REVOCATION_PARA   pRevPara,
  [in, out]      PCERT_REVOCATION_STATUS pRevStatus
);