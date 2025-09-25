WS_CERTIFICATE_VALIDATION_CALLBACK WsCertificateValidationCallback;

HRESULT WsCertificateValidationCallback(
  [in]           PCCERT_CONTEXT certContext,
  [in, optional] void *state
)
{...}