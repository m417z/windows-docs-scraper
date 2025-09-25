HRESULT VerifyRequest(
  [in]          CERTTRANSBLOB *pctbRequest,
  [in]          CERTTRANSBLOB *pctbSigningCertEncoded,
  [in]          PCWSTR        pwszTemplate,
  [in]          PCWSTR        pwszTransactionId,
  [out, retval] BOOL          *pfVerified
);