typedef struct _WS_CERT_SIGNED_SAML_AUTHENTICATOR {
  WS_SAML_AUTHENTICATOR     authenticator;
  const _CERT_CONTEXT       **trustedIssuerCerts;
#if ...
  struct                    _CERT_CONTEXT;
  ULONG                     trustedIssuerCertCount;
  const _CERT_CONTEXT       *decryptionCert;
#else
  struct                    _CERT_CONTEXT;
#endif
  WS_VALIDATE_SAML_CALLBACK samlValidator;
  void                      *samlValidatorCallbackState;
} WS_CERT_SIGNED_SAML_AUTHENTICATOR;