typedef struct _RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W {
  RPC_AUTH_IDENTITY_HANDLE TransportCredentials;
  unsigned long            Flags;
  unsigned long            AuthenticationTarget;
  unsigned long            NumberOfAuthnSchemes;
  unsigned long            *AuthnSchemes;
  unsigned short           *ServerCertificateSubject;
  RPC_AUTH_IDENTITY_HANDLE ProxyCredentials;
  unsigned long            NumberOfProxyAuthnSchemes;
  unsigned long            *ProxyAuthnSchemes;
} RPC_HTTP_TRANSPORT_CREDENTIALS_V3_W, *PRPC_HTTP_TRANSPORT_CREDENTIALS_V3_W;