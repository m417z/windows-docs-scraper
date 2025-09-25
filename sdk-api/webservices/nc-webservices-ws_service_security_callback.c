WS_SERVICE_SECURITY_CALLBACK WsServiceSecurityCallback;

HRESULT WsServiceSecurityCallback(
  [in]           const WS_OPERATION_CONTEXT *context,
  [out]          BOOL *authorized,
  [in, optional] WS_ERROR *error
)
{...}