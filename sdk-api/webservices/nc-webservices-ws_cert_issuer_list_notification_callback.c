WS_CERT_ISSUER_LIST_NOTIFICATION_CALLBACK WsCertIssuerListNotificationCallback;

HRESULT WsCertIssuerListNotificationCallback(
  [in]           void *certIssuerListNotificationCallbackState,
  [in]           const _SecPkgContext_IssuerListInfoEx *issuerList,
  [in, optional] WS_ERROR *error
)
{...}