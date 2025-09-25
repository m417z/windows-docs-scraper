NTSTATUS PstValidate(
  [in, optional]  PUNICODE_STRING  pTargetName,
  [in]            BOOL             bIsClient,
  [in, optional]  CERT_USAGE_MATCH *pRequestedIssuancePolicy,
  [in, optional]  HCERTSTORE       *phAdditionalCertStore,
  [in]            PCCERT_CONTEXT   pCert,
  [out, optional] GUID             *pProvGUID
);