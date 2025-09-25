HRESULT Validate(
  [in]          IOpcDigitalSignature            *signature,
  [in]          const CERT_CONTEXT              *certificate,
  [out, retval] OPC_SIGNATURE_VALIDATION_RESULT *validationResult
);