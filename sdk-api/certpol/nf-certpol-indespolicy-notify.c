HRESULT Notify(
  [in] PCWSTR              pwszChallenge,
  [in] PCWSTR              pwszTransactionId,
  [in] X509SCEPDisposition disposition,
  [in] LONG                lastHResult,
  [in] CERTTRANSBLOB       *pctbIssuedCertEncoded
);