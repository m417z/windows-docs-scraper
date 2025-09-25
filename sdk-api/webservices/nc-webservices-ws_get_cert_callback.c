WS_GET_CERT_CALLBACK WsGetCertCallback;

HRESULT WsGetCertCallback(
  [in]           void *getCertCallbackState,
  [in, optional] const WS_ENDPOINT_ADDRESS *targetAddress,
  [in, optional] const WS_STRING *viaUri,
                 const _CERT_CONTEXT **cert,
  [in, optional] WS_ERROR *error
)
{...}