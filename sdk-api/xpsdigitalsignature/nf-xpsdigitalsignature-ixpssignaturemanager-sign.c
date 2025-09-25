HRESULT Sign(
  [in]          IXpsSigningOptions *signOptions,
  [in]          const CERT_CONTEXT *x509Certificate,
  [out, retval] IXpsSignature      **signature
);