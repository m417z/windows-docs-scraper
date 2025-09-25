QUERYCLIENTCERT Queryclientcert;

BOOLEAN Queryclientcert(
  [in]      PLDAP Connection,
  [in]      PSecPkgContext_IssuerListInfoEx trusted_CAs,
  [in, out] PCCERT_CONTEXT *ppCertificate
)
{...}