typedef struct _WS_CUSTOM_CERT_CREDENTIAL {
  WS_CERT_CREDENTIAL                        credential;
  WS_GET_CERT_CALLBACK                      getCertCallback;
  void                                      *getCertCallbackState;
  WS_CERT_ISSUER_LIST_NOTIFICATION_CALLBACK certIssuerListNotificationCallback;
  void                                      *certIssuerListNotificationCallbackState;
} WS_CUSTOM_CERT_CREDENTIAL;