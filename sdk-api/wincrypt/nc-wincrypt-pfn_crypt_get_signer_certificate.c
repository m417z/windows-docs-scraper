PFN_CRYPT_GET_SIGNER_CERTIFICATE PfnCryptGetSignerCertificate;

PCCERT_CONTEXT PfnCryptGetSignerCertificate(
  [in] void *pvGetArg,
  [in] DWORD dwCertEncodingType,
  [in] PCERT_INFO pSignerId,
  [in] HCERTSTORE hMsgCertStore
)
{...}