WS_HTTP_REDIRECT_CALLBACK WsHttpRedirectCallback;

HRESULT WsHttpRedirectCallback(
  [in] void *state,
  [in] const WS_STRING *originalUrl,
  [in] const WS_STRING *newUrl
)
{...}