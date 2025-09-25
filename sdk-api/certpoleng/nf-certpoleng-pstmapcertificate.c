NTSTATUS PstMapCertificate(
  [in]  PCCERT_CONTEXT             pCert,
  [out] LSA_TOKEN_INFORMATION_TYPE *pTokenInformationType,
  [out] PVOID                      *ppTokenInformation
);