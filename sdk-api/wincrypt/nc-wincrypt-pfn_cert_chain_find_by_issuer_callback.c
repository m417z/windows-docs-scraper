PFN_CERT_CHAIN_FIND_BY_ISSUER_CALLBACK PfnCertChainFindByIssuerCallback;

BOOL PfnCertChainFindByIssuerCallback(
  [in] PCCERT_CONTEXT pCert,
  [in] void *pvFindArg
)
{...}