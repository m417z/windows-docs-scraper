BOOL CertIsStrongHashToSign(
  [in]           PCCERT_STRONG_SIGN_PARA pStrongSignPara,
  [in]           LPCWSTR                 pwszCNGHashAlgid,
  [in, optional] PCCERT_CONTEXT          pSigningCert
);