HRESULT GetCACertificate(
  [in]          LONG       fExchangeCertificate,
  [in]          const BSTR strConfig,
  [in]          LONG       Flags,
  [out, retval] BSTR       *pstrCertificate
);