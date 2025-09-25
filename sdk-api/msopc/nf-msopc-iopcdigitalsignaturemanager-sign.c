HRESULT Sign(
  [in]          const CERT_CONTEXT   *certificate,
  [in]          IOpcSigningOptions   *signingOptions,
  [out, retval] IOpcDigitalSignature **digitalSignature
);