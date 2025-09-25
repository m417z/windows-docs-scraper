BOOL CertVerifyCertificateChainPolicy(
  [in]      LPCSTR                    pszPolicyOID,
  [in]      PCCERT_CHAIN_CONTEXT      pChainContext,
  [in]      PCERT_CHAIN_POLICY_PARA   pPolicyPara,
  [in, out] PCERT_CHAIN_POLICY_STATUS pPolicyStatus
);