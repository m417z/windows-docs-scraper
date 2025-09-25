typedef struct _RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W {
  SEC_WINNT_AUTH_IDENTITY_W *TransportCredentials;
  unsigned long             Flags;
  unsigned long             AuthenticationTarget;
  unsigned long             NumberOfAuthnSchemes;
  unsigned long             *AuthnSchemes;
  unsigned short            *ServerCertificateSubject;
  SEC_WINNT_AUTH_IDENTITY_W *ProxyCredentials;
  unsigned long             NumberOfProxyAuthnSchemes;
  unsigned long             *ProxyAuthnSchemes;
} RPC_HTTP_TRANSPORT_CREDENTIALS_V2_W, *PRPC_HTTP_TRANSPORT_CREDENTIALS_V2_W;