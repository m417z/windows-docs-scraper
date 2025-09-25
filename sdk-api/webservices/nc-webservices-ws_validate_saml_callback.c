WS_VALIDATE_SAML_CALLBACK WsValidateSamlCallback;

HRESULT WsValidateSamlCallback(
  [in, optional] void *samlValidatorCallbackState,
  [in]           WS_XML_BUFFER *samlAssertion,
  [in, optional] WS_ERROR *error
)
{...}