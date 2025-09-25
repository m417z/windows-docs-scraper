WS_VALIDATE_PASSWORD_CALLBACK WsValidatePasswordCallback;

HRESULT WsValidatePasswordCallback(
  [in, optional] void *passwordValidatorCallbackState,
  [in]           const WS_STRING *username,
  [in]           const WS_STRING *password,
  [in, optional] const WS_ASYNC_CONTEXT *asyncContext,
  [in, optional] WS_ERROR *error
)
{...}